#include <stdint.h>
#include <sys/types.h>
#include <arpa/inet.h>

#define FATTR4_WORD0_ACL 0x00000040
#define NFS4_ACL_LEN_REQUEST 0x0001
#define OP_GETATTR 3

typedef uint32_t __be32;
typedef uint32_t u32;
typedef uint8_t u8;

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct xdr_buf {
    struct kvec *head;
    unsigned int len;
};

struct rpc_rqst {
    struct xdr_buf rq_rcv_buf;
};

struct xdr_stream {
    __be32 *p;
};

struct nfs_getaclres {
    unsigned int acl_len;
    unsigned int acl_data_offset;
    unsigned int acl_flags;
};

static inline uint32_t be32_to_cpup(const __be32 *p) {
    return ntohl(*p);
}

#define unlikely(x) __builtin_expect(!!(x), 0)
#define likely(x)   __builtin_expect(!!(x), 1)

#define EIO 5
#define EINVAL 22
#define EOPNOTSUPP 95

static int decode_op_hdr(struct xdr_stream *xdr, unsigned int op) { return 0; }
static int decode_attr_bitmap(struct xdr_stream *xdr, uint32_t *bitmap) { return 0; }
static int decode_attr_length(struct xdr_stream *xdr, uint32_t *attrlen, __be32 **savep) { return 0; }
static void xdr_read_pages(struct xdr_stream *xdr, unsigned int len) {}
#define dprintk(fmt, ...)