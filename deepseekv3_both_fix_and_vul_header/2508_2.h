#include <stdint.h>
#include <sys/types.h>
#include <stddef.h>

typedef struct netdissect_options netdissect_options;

enum sunrpc_accept_stat {
    SUNRPC_SUCCESS
};

struct sunrpc_msg {
    struct {
        struct accepted_reply {
            struct opaque_auth {
                uint32_t oa_length;
                uint32_t oa_base;
            } ar_verf;
        } rp_acpt;
    } rm_reply;
};

extern int nfserr;
extern const char *sunrpc_str[];
extern const char *tok2str(const char * const *, const char *, int);

#define ND_TCHECK(x)
#define ND_TCHECK2(x, y)
#define EXTRACT_32BITS(x) (*(x))
#define ND_PRINT(args)