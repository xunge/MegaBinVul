#include <stdio.h>
#include <string.h>

typedef struct {
    const char *hostname;
    int port;
    const char *user_name;
    const char *pub_auth;
} cachemgr_request;

extern const char *script_name;

const char *safe_str(const char *str);