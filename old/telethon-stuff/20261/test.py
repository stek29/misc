from session import client
from telethon.tl.types.contacts import ContactsNotModified
from telethon.tl.functions.contacts import GetContactsRequest

def hash_20261_32(ids):
    acc = 0
    for i in ids:
        acc = (acc * 20261 + i) & 0xffffffff
    return acc & 0x7fffffff

def test_hash_32():
    contacts = client(GetContactsRequest(hash=0))
    ids = [c.user_id for c in contacts.contacts] 
    ids = [contacts.saved_count] + ids

    resp = client(GetContactsRequest(hash=hash_20261_32(ids)))
    return isinstance(resp, ContactsNotModified)

assert test_hash_32()