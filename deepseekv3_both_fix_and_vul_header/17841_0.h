#include <stdlib.h>
#include <string.h>

struct usmStateReference {
    char *usr_name;
    size_t usr_name_length;
    char *usr_engine_id;
    size_t usr_engine_id_length;
    char *usr_auth_protocol;
    size_t usr_auth_protocol_length;
    char *usr_priv_protocol;
    size_t usr_priv_protocol_length;
    char *usr_auth_key;
    size_t usr_auth_key_length;
    char *usr_priv_key;
    size_t usr_priv_key_length;
    int refcnt;
};

#define SNMP_FREE(ptr) free(ptr)
#define SNMP_ZERO(ptr, size) memset(ptr, 0, size)