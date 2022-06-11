from session import client
from telethon.tl.functions.contacts import GetContactsRequest
from telethon.tl.types.contacts import ContactsNotModified
import struct
from time import sleep

def hash_ids_0(ids):
    acc = 0
    for uid in ids:
        acc = (acc * 20261 + 1) & 0xffffffff
        acc = (acc * 20261 + uid) & 0xffffffff
    return acc

def hash_ids_1(ids):
    acc = 0
    for uid in ids:
        acc = (acc * 20261 + uid) & 0xffffffff
        acc = (acc * 20261 + uid) & 0xffffffff
    return acc

def hash_ids_2(ids):
    acc = 0
    for uid in ids:
        acc = (acc * 20261) & 0xffffffff
        acc = (acc * 20261 + uid) & 0xffffffff
    return acc

def hash_ids_3(ids):
    acc = 0
    for uid in ids:
        acc = (acc * 20261 + uid) & 0xffffffff
    return acc

def bruteforce(ids):
    for h in [hash_ids_0, hash_ids_1, hash_ids_2, hash_ids_3]:
        yield h(ids) & 0x7fffffff
        yield struct.unpack('<i', struct.pack('<I', h(ids)))[0]

def bruh(c):
    for hsh in bruteforce(c):
        resp = client(GetContactsRequest(hash=hsh))
        if isinstance(resp, ContactsNotModified):
            print("WERKS %s"%hex(hsh))
            break
        else:
            print('SUCC %s'%hex(hsh))


client.connect()

contacts = client(GetContactsRequest(hash=0))
c = [c.user_id for c in contacts.contacts]

bruh([contacts.saved_count] + c)
bruh(c + [contacts.saved_count])
c.sort()
bruh([contacts.saved_count] + c)
bruh(c + [contacts.saved_count])
c.reverse()
bruh([contacts.saved_count] + c)
bruh(c + [contacts.saved_count])

client.disconnect()