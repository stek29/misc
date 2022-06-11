from urllib import request
from base64 import b64decode
from telethon.extensions import BinaryReader
from ipaddress import IPv4Address
from datetime import datetime
from hashlib import sha256
from struct import unpack
from pyaes import AESModeOfOperationCBC
import rsa
import re
import json
from telethon.tl.types.help import ConfigSimple
import random

class ConfigNotSimple:
    class IpPort:
        """ ipPort ipv4:int port:int = IpPort; """
        def __init__(self, reader):
            self.ipv4 = reader.read_int(signed=False)
            self.port = reader.read_int(signed=False)
            self.ipaddress = IPv4Address(self.ipv4)

        def __repr__(self):
            return 'ipPort(%s:%s)'%(self.ipaddress.exploded, self.port)

    def __init__(self, reader):
        """
        help.configSimple#d997c3c5 date:int expires:int dc_id:int ip_port_list:Vector<ipPort> = help.ConfigSimple;
        """
        assert(reader.read_int(signed=False) == 0xd997c3c5)
        self.date = reader.read_int(signed=False)
        self.date_date = datetime.utcfromtimestamp(self.date)
        self.expires = reader.read_int(signed=False)
        self.date_expires = datetime.utcfromtimestamp(self.expires)
        self.dc_id = reader.read_int(signed=False)

        assert(reader.read_int(signed=False) == 0x1cb5c415)
        self.ip_port_list = list()

        veclen = reader.read_int(signed=False)
        for _ in range(veclen):
            self.ip_port_list.append(self.IpPort(reader))

    def __repr__(self):
        return 'ConfigSimple dc#%s from %s expires %s : %s'%(self.dc_id, self.date_date, self.date_expires, self.ip_port_list)


class SpecialConfig:
    @classmethod
    def get(cls, test_backend=False, fetcher=None):
        if fetcher is None:
            fetcher = random.choice([
                cls._fetch_webapp,
                cls._fetch_google_dns
            ])

        confb64 = fetcher(test_backend)
        return cls._decode_simpleconf(confb64)

    @classmethod
    def _decrypt_and_validate(cls, data):
        PUBKEY_PEM = b"""-----BEGIN RSA PUBLIC KEY-----
        MIIBCgKCAQEAyr+18Rex2ohtVy8sroGPBwXD3DOoKCSpjDqYoXgCqB7ioln4eDCF
        fOBUlfXUEvM/fnKCpF46VkAftlb4VuPDeQSS/ZxZYEGqHaywlroVnXHIjgqoxiAd
        192xRGreuXIaUKmkwlM9JID9WS2jUsTpzQ91L8MEPLJ/4zrBwZua8W5fECwCCh2c
        9G5IzzBm+otMS/YKwmR1olzRCyEkyAEjXWqBI9Ftv5eG8m0VkBzOG655WIYdyV0H
        fDK/NWcvGqa0w/nriMD6mDjKOryamw0OP9QuYgMN0C9xMW9y8SmP4h92OAWodTYg
        Y1hZCxdv6cs5UnW9+PWvS+WIbkh+GaWYxwIDAQAB
        -----END RSA PUBLIC KEY-----"""

        pubkey = rsa.PublicKey.load_pkcs1(PUBKEY_PEM, format='PEM')

        data_int = rsa.transform.bytes2int(data)
        data_int = rsa.core.decrypt_int(data_int, pubkey.e, pubkey.n)
        data = rsa.transform.int2bytes(data_int)
        
        # Step 2 -- AES decrypt -- what for?..
        AES_KEY_SIZE = 32
        AES_BLOCK_SIZE = 16
        # first bytes are key, and last bytes of key is iv
        cryptor = AESModeOfOperationCBC(
            data[:AES_KEY_SIZE], 
            data[:AES_KEY_SIZE][-AES_BLOCK_SIZE:]
        )

        # Iterate over data in chunks of AES_BLOCK_SIZE and decrypt it
        # pyaes can't do it on its own :(
        data = b''.join(
            cryptor.decrypt(bytes(d)) for d in zip(*[iter(data[AES_KEY_SIZE:])]*AES_BLOCK_SIZE)
        )

        # Step 3 -- SHA256 digest check
        DIGEST_LEN = 16

        actual_digest = sha256(data[:-DIGEST_LEN]).digest()[:DIGEST_LEN]
        expected_digest = data[-DIGEST_LEN:]

        if actual_digest != expected_digest:
            raise "Digest mismatch"

        # Step 4 -- cropping payload and length checks
        data_len = unpack('<i', data[:4])[0]
        data = data[4:]

        if not 0 < data_len <= len(data) or (data_len & 3):
            raise "Invalid data_len"

        return data[:data_len]


    @classmethod
    def _decode_simpleconf(cls, confb64):        
        filtered = re.sub(r'[^a-zA-Z0-9=/+]+', '', confb64)
        if len(filtered) != 344:
            raise "Invalid length"

        decoded = b64decode(filtered)
        if len(decoded) != 256:
            raise "Invalid length decoded"

        decrypted = cls._decrypt_and_validate(decoded)

        reader = BinaryReader(decrypted)
        return ConfigNotSimple(reader)
        cfg = reader.tgread_object()

        if not isinstance(cfg, ConfigSimple):
            raise "Expexted ConfigSimple, got cfg.__class__"

        return cfg

    @staticmethod
    def _fetch_webapp(test_backend=False):
        url = 'https://software-download.microsoft.com/{}/config.txt'.format(
            'test' if test_backend else 'prod'
        )
        req = request.Request(url, headers={'Host': 'tcdnb.azureedge.net'})
        
        r = request.urlopen(req)
        if r.getcode() != 200:
            raise "Expected 200, got r.getcode()"

        return r.read().decode()

    @staticmethod
    def _fetch_google_dns(test_backend=False):
        domain = 'tap.stel.com' if test_backend else 'ap.stel.com'
        url = 'https://google.com/resolve?name={}&type=TXT'.format(domain)
        req = request.Request(url, headers={'Host': 'dns.google.com'})
        r = request.urlopen(req)

        if r.getcode() != 200:
            raise "Expected 200, r.getcode()"

        reply = r.read().decode()
        try:
            reply = json.loads(reply)
        except JSONDecodeError:
            raise "Invalid answer"

        try:
            datas = list(map(lambda x: x['data'], reply['Answer']))
            datas.sort(key=len)
            data = ''.join(datas[::-1])
        except KeyError:
            raise "Invalid answer"

        return data

print(SpecialConfig.get())
