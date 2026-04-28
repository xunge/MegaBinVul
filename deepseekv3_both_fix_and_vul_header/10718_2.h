#include <stdint.h>
#include <stdlib.h>

typedef uint32_t __be32;
typedef uint8_t stateid_opaque_t[16];

#define nfserr_resource ((__be32)1)

struct xdr_stream {
    // Minimal xdr_stream definition
    __be32 *p;
    __be32 *end;
};

struct nfsd4_compoundres {
    struct xdr_stream xdr;
};

struct nfsd4_layoutget {
    int lg_layout_type;
    struct {
        uint32_t si_generation;
        stateid_opaque_t si_opaque;
    } lg_sid;
    struct {
        uint64_t offset;
        uint64_t length;
        uint32_t iomode;
    } lg_seg;
    void *lg_content;
};

struct nfsd4_layout_ops {
    __be32 (*encode_layoutget)(struct xdr_stream *, struct nfsd4_layoutget *);
};

extern struct nfsd4_layout_ops *nfsd4_layout_ops[];
extern void kfree(void *ptr);

#define dprintk(fmt, ...) 

static inline __be32 cpu_to_be32(uint32_t x) {
    return x;
}

static inline __be32 *xdr_reserve_space(struct xdr_stream *xdr, size_t n) {
    return NULL;
}

static inline __be32 *xdr_encode_opaque_fixed(__be32 *p, void *data, size_t len) {
    return p;
}

static inline __be32 *xdr_encode_hyper(__be32 *p, uint64_t val) {
    return p;
}