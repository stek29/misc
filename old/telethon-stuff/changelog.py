from telethon import TelegramClient
from telethon.tl.functions import InitConnectionRequest, InvokeWithLayerRequest
from telethon.tl import all_tlobjects
from telethon.tl.functions.help import GetAppChangelogRequest
from telethon.tl.types import UpdateServiceNotification, Updates, UpdateShort

def get_changelog(client, app_version, prev_version, lang_code='en-US'):
    query = GetAppChangelogRequest(prev_app_version=prev_version)
    init_connection_request = InitConnectionRequest(
        api_id=client.api_id,
        query=query,
        lang_code=lang_code,
        app_version=app_version,
        system_lang_code=lang_code,
        lang_pack='',
        **{x: 'shitfuck' for x in ['device_model', 'system_version']}
    )

    return client(InvokeWithLayerRequest(
        layer=all_tlobjects.LAYER, 
        query=init_connection_request
    ))

def get_changelog_notifications_iter(client, app_version, prev_version, lang_code='en-US'):
    resp = get_changelog(client, app_version, prev_version)

    updates = []

    if isinstance(resp, Updates):
        updates = resp.updates
    elif isinstance(resp, UpdateShort):
        updates = [ resp.update ]

    for update in updates:
        if not isinstance(update, UpdateServiceNotification):
            continue

        yield update

def create_client(app_type, base_sname, phone):
    app_type = app_type.lower()

    apps = {
            'ios': (1, 'b6b154c3707471f5339bd661645ed3d6'),
            'android': (6, 'eb06d4abfb49dc3eeb1aeb98ae0f581e'),
    }

    api_id, api_hash = apps[app_type]
    sname = '%s_%s'%(base_sname, app_type)

    client = TelegramClient(sname, api_id, api_hash)
    client.connect()

    if not client.is_user_authorized():
        client.send_code_request(phone)
        client.sign_in(phone, input('Enter auth code: '))

    return client


if __name__ == '__main__':
    app_type, app_version, prev_version = \
        input('Enter app type, version, prev_version: ').split(' ')

    client = create_client(app_type, 'yota', '+78005553535')

    for notification in get_changelog_notifications_iter(client, app_version, prev_version):
        print('\n'.join((
            'TYPE:',
            notification.type,
            '\nMESSAGE:',
            notification.message
        )))

    client.disconnect()
