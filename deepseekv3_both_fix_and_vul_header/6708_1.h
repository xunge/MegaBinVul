#include <stdint.h>

typedef struct _xReq {
    uint8_t reqType;
    uint8_t pad;
    uint16_t length;
} xReq;

typedef struct _xConnClientPrefix {
    uint16_t majorVersion;
    uint16_t minorVersion;
    uint16_t nbytesAuthProto;
    uint16_t nbytesAuthString;
} xConnClientPrefix;

#define sz_xReq sizeof(xReq)
#define sz_xConnClientPrefix sizeof(xConnClientPrefix)

#define X_PROTOCOL 11
#define X_PROTOCOL_REVISION 0

typedef struct _Client {
    int req_len;
    void *stuff;
} Client;

typedef Client *ClientPtr;

#define REQUEST(type) type *stuff = client->stuff

static inline int pad_to_int32(int len) {
    return (len + 3) & ~3;
}

const char *ClientAuthorized(ClientPtr client, unsigned short proto_len, char *proto, 
                           unsigned short string_len, char *string);
int SendConnSetup(ClientPtr client, const char *reason);