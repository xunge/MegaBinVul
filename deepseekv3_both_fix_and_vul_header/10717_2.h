#include <stdint.h>
#include <stdlib.h>

typedef uint32_t __be32;
typedef uint32_t u32;

struct xdr_buf {
    u32 len;
};

struct xdr_stream {
    struct xdr_buf *buf;
};

struct nfsd4_layout_ops {
    __be32 (*encode_getdeviceinfo)(struct xdr_stream *, void *);
};

struct nfsd4_getdeviceinfo {
    u32 gd_layout_type;
    u32 gd_maxcount;
    u32 gd_notify_types;
    void *gd_device;
};

struct nfsd4_compoundres {
    struct xdr_stream xdr;
};

extern struct nfsd4_layout_ops *nfsd4_layout_ops[];

#define dprintk(fmt, ...)
#define cpu_to_be32(x) (x)
#define be32_to_cpu(x) (x)
#define kfree free

#define nfserr_resource 1
#define nfserr_toosmall 2

static void xdr_truncate_encode(struct xdr_stream *xdr, u32 len) {}
static __be32 *xdr_reserve_space(struct xdr_stream *xdr, int size) { return NULL; }