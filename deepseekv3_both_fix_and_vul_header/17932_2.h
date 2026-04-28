#include <stdint.h>
#include <stdlib.h>

struct xdr_buf {
    unsigned int len;
};

struct rpc_rqst {
    struct xdr_buf rq_rcv_buf;
};

struct xdr_stream {
    void *buf;
};

struct nfs4_sequence_args {
    unsigned int dummy;
};

struct nfs_fh {
    unsigned int size;
    unsigned char data[0];
};

struct page {
    void *data;
};

struct compound_hdr {
    unsigned int minorversion;
    unsigned int replen;
};

struct nfs_getaclargs {
    struct nfs4_sequence_args seq_args;
    struct nfs_fh *fh;
    struct page **acl_pages;
    unsigned int acl_pgbase;
    unsigned int acl_len;
    struct page *acl_scratch;
};

#define FATTR4_WORD0_ACL 0
#define op_decode_hdr_maxsz 0
#define nfs4_fattr_bitmap_maxsz 0
#define PAGE_SIZE 4096

static inline unsigned int nfs4_xdr_minorversion(const struct nfs4_sequence_args *args) { return 0; }
static inline void encode_compound_hdr(struct xdr_stream *xdr, struct rpc_rqst *req, struct compound_hdr *hdr) {}
static inline void encode_sequence(struct xdr_stream *xdr, const struct nfs4_sequence_args *args, struct compound_hdr *hdr) {}
static inline void encode_putfh(struct xdr_stream *xdr, const struct nfs_fh *fh, struct compound_hdr *hdr) {}
static inline void encode_getattr_two(struct xdr_stream *xdr, int bitmap, int mask, struct compound_hdr *hdr) {}
static inline void xdr_inline_pages(struct xdr_buf *buf, unsigned int offset, struct page **pages, unsigned int base, unsigned int len) {}
static inline void xdr_set_scratch_buffer(struct xdr_stream *xdr, void *buf, size_t size) {}
static inline void encode_nops(struct compound_hdr *hdr) {}
static inline void *page_address(struct page *page) { return page ? page->data : NULL; }