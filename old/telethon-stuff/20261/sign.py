from session import client
from telethon.tl.functions.contacts import GetContactsRequest
from telethon.tl.types.contacts import ContactsNotModified
import struct
from time import sleep

def hash_20261_u32(ids):
    acc = 0
    for i in ids:
        acc = (acc * 20261 + i) & 0xffffffff
    return acc & 0x7fffffff

def hash_20261_i32(ids):
    acc = 0
    for i in ids:
        acc = (acc * 20261 + i) & 0xffffffff
    return struct.unpack('<i', struct.pack('<I', acc))[0]

def hash_20261_li(ids):
    acc = 0
    for i in ids:
        acc = (acc * 20261 + i) & 0xffffffffffffffff
    return struct.unpack('<i', struct.pack('<I', acc & 0xffffffff))[0]

def test_hash(hsh):
    resp = client(GetContactsRequest(hash=hsh))
    return isinstance(resp, ContactsNotModified)

def werk():
    contacts = client(GetContactsRequest(hash=0))
    c = [c.user_id for c in contacts.contacts]
    c.sort() # just in case
    c = [contacts.saved_count] + c
    hashes = set()
    def add_hash(x):
        res = x(c)
        print(x.__name__, hex(res))
        hashes.add(res)
    
    for h in [hash_20261_u32, hash_20261_i32, hash_20261_li]:
        add_hash(h)

    for x in hashes:
        print(hex(x), test_hash(x))


client.connect()

werk()

client.disconnect()