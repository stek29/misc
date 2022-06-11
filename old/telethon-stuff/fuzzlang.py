from telethon import TelegramClient
from telethon.tl.functions import InitConnectionRequest, InvokeWithLayerRequest
from telethon.tl import all_tlobjects
from telethon.tl.functions.messages import SendMessageRequest
from telethon.tl.types import InputPeerChannel
from random import randint

def invokeWithCode(client, query, lang_code='en', system_lang_code='ru-RU'):
    init_connection_request = InitConnectionRequest(
        api_id=client.api_id,
        lang_pack='tdesktop',
        query=query,
        lang_code=lang_code,
        system_lang_code=system_lang_code,
        **{x: 'shitfuck' for x in ['device_model', 'system_version', 'app_version']}
    )
    return client(InvokeWithLayerRequest(layer=all_tlobjects.LAYER, query=init_connection_request))

api_id = 0
api_hash = ''
phone_number, sname = '+78005553535', 'yota'

client = TelegramClient(sname, api_id, api_hash)
client.connect()

from pprint import pprint
try:
    while True:
        lang, syst = input('lang_code system_lang_code: ').split(' ')
        query = SendMessageRequest(
            peer=InputPeerChannel(
                channel_id=1331528652,
                access_hash=-2322754698844732062
            ),
            message='/debug lang: %s system: %s'%(lang, syst),
            random_id=randint(0, 0xFFFFFFFF)
        )
        pprint(invokeWithCode(client, query, lang, syst))
finally:
    client.disconnect()
