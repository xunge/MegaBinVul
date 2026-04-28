#include <string.h>

typedef unsigned long XID;

struct auth {
    XID id;
    unsigned short len;
    const char *data;
    struct auth *next;
};

extern struct auth *mit_auth;

typedef struct _Client *ClientPtr;