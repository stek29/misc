# Created to make RE-ing XPC a bit easier (in a shitty way)
# yes, somethings are hard-coded but I've done it because I don't want to spend more time on this
# created by Abraham Masri @cheesecakeufo

import re
import idaapi
import idautils

paths = ["/usr/include/xpc/xpc.h",
         "/usr/include/xpc/activity.h",
         "/usr/include/xpc/availability.h",
         "/usr/include/xpc/base.h",
         "/usr/include/xpc/connection.h",
         "/usr/include/xpc/debug.h",
         "/usr/include/xpc/endpoint.h"
         ]

all_headers = ''

def imp_cb(ea, name, ord):

    if not name and len(name) < 4:
        return True

    # get the actual address of the function
    func_address = LocByName(name)

    # check if the address we have is valid
    if (func_address & 0xffffffffffffffff == 0xffffffffffffffff):
        return True # skip. invalid.

    # fix anything that starts with '_xpc'
    if(name[:4] == '_xpc'):
        name = name[1:]

        type_line = None
        function_definition = None
        last_line = None
        for line in all_headers.split('\n'):

            if function_definition is not None and line[:1] != '#':
                function_definition = function_definition + ' ' + line.strip()
                break

            regex = re.match(r'^({})'.format(name), line)

            if regex is not None:
                function_definition = (type_line + ' ' + line).replace('\n', '')

            type_line = line.strip()

        if function_definition is None:
            print ("[ERROR]: skipping '{}'. no match in headers.".format(name))
            return True # not found :/

        function_definition = function_definition.replace('_Nullable', '').replace('_Nonnull', '').replace('XPC_NONNULL_ARRAY', '')

        print("[INFO]: found matching function '{}'.".format(name))
        ParseTypes(function_definition)

    return True


# define XPC objects first
ParseTypes("typedef void * xpc_object_t;")
ParseTypes("typedef xpc_object_t xpc_connection_t;")
ParseTypes("typedef xpc_object_t xpc_endpoint_t;")
ParseTypes("typedef xpc_object_t xpc_activity_t;")

ParseTypes("typedef void (*xpc_handler_t)(xpc_object_t object);")
ParseTypes("typedef long xpc_activity_state_t;");
ParseTypes("typedef void (*xpc_activity_handler_t)(xpc_activity_t activity);");

ParseTypes("typedef const struct _xpc_type_s * xpc_type_t;")
ParseTypes("const struct _xpc_type_s _xpc_type_connection;")
ParseTypes("const struct _xpc_type_s _xpc_type_endpoint;")
ParseTypes("const struct _xpc_type_s _xpc_type_null;")
ParseTypes("const struct _xpc_type_s _xpc_type_bool;")
ParseTypes("const struct _xpc_type_s _xpc_type_int64;")
ParseTypes("const struct _xpc_type_s _xpc_type_uint64;")
ParseTypes("const struct _xpc_type_s _xpc_type_double;")
ParseTypes("const struct _xpc_type_s _xpc_type_date;")
ParseTypes("const struct _xpc_type_s _xpc_type_data;")
ParseTypes("const struct _xpc_type_s _xpc_type_string;")
ParseTypes("const struct _xpc_type_s _xpc_type_uuid;")
ParseTypes("const struct _xpc_type_s _xpc_type_fd;")
ParseTypes("const struct _xpc_type_s _xpc_type_shmem;")
ParseTypes("const struct _xpc_type_s _xpc_type_array;")
ParseTypes("const struct _xpc_type_s _xpc_type_dictionary;")
ParseTypes("const struct _xpc_type_s _xpc_type_error;")

# private def (not found in headers)
ParseTypes('typedef struct {unsigned int val[8];} audit_token_t;')
ParseTypes('void xpc_connection_get_audit_token(xpc_connection_t, audit_token_t*);')
ParseTypes('xpc_object_t xpc_copy_entitlement_for_token(const char *, audit_token_t *);')

# combine all headers into one for faster reading
for path in paths:
    for line in open('Z:\\' + path):
        all_headers += line

# fix functions
for i in xrange(0, idaapi.get_import_module_qty()):

    name = idaapi.get_import_module_name(i)

    if name:
        idaapi.enum_import_names(i, imp_cb)
