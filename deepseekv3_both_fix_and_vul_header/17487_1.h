#include <stdio.h>
#include <stddef.h>

struct key_preparsed_payload {
    const char *orig_description;
    size_t datalen;
    union {
        void *data[2];
    } payload;
};

struct rxrpc_security {
    int (*preparse_server_key)(struct key_preparsed_payload *prep);
};

extern const struct rxrpc_security *rxrpc_security_lookup(unsigned int sec_class);

#define _enter(fmt, ...) 
#define EINVAL 22
#define ENOPKG 65