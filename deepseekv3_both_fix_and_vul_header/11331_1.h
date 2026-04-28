#include <stddef.h>
#include <stdint.h>
#include <ctype.h>
#include <arpa/inet.h>

#define AFSTOKEN_LENGTH_MAX 65535
#define AFSTOKEN_CELL_MAX 64
#define AFSTOKEN_MAX 4

#define RXRPC_SECURITY_RXKAD 0
#define RXRPC_SECURITY_RXK5  1

#define _enter(fmt, ...) 
#define _debug(fmt, ...) 
#define _leave(fmt, ...) 

#define EPROTO 71
#define EPROTONOSUPPORT 93

typedef uint32_t __be32;

struct key_preparsed_payload {
    const void *data;
    size_t datalen;
};

static int rxrpc_preparse_xdr_rxkad(struct key_preparsed_payload *prep, size_t datalen, const __be32 *xdr, unsigned int toklen);
static int rxrpc_preparse_xdr_rxk5(struct key_preparsed_payload *prep, size_t datalen, const __be32 *xdr, unsigned int toklen);