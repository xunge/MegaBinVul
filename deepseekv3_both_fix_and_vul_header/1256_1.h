#include <stdint.h>
#include <stdlib.h>

struct pgpDigParams {
    int sigtype;
};

typedef struct pgpDigParams *pgpDigParams;

struct pgpPkt {
    uint8_t *head;
    uint8_t *body;
    size_t blen;
    int tag;
};

#define PGPTAG_PUBLIC_SUBKEY 14
#define PGPTAG_SIGNATURE 2
#define PGPSIGTYPE_SUBKEY_BINDING 24

pgpDigParams pgpDigParamsNew(int tag);
pgpDigParams pgpDigParamsFree(pgpDigParams digp);
int decodePkt(const uint8_t *p, size_t plen, struct pgpPkt *pkt);
int pgpPrtPkt(struct pgpPkt *pkt, pgpDigParams digp);
int pgpVerifySelf(pgpDigParams digp, pgpDigParams selfsig, struct pgpPkt *all, int i);
void *xmalloc(size_t size);
void *xrealloc(void *ptr, size_t size);