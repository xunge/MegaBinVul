#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define FATTR4_WORD2_SECURITY_LABEL (1U << 0)
#define NFS4_MAXLABELLEN 1024
#define NFS_ATTR_FATTR_V4_SECURITY_LABEL 1
#define EIO 5
#define ERANGE 34
#define KERN_WARNING ""
#define unlikely(x) (x)
#define likely(x) (x)
#define dprintk(...) 

typedef uint32_t __u32;
typedef uint32_t __be32;

struct xdr_stream;
struct nfs4_label {
    uint32_t len;
    uint32_t pi;
    uint32_t lfs;
    char *label;
};

__be32 *xdr_inline_decode(struct xdr_stream *xdr, size_t nbytes);
#define be32_to_cpup(p) (*(p))