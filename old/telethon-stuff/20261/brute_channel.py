from session import client
from telethon.tl.functions.channels import GetParticipants
from telethon.tl.types.channels import ChannelParticipantsNotModified


def hash_20261_32(ids):
    acc = 0
    for i in ids:
        acc = (acc * 20261 + i) & 0xffffffff
    return acc & 0x7fffffff


def bruh(c):
    for hsh in bruteforce(c):
        resp = client(GetContactsRequest(hash=hsh))
        if isinstance(resp, ChannelParticipantsNotModified):
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