#include <stddef.h>

struct rpc_rqst;
struct xdr_stream;

struct compound_hdr {
    int dummy;
};

struct nfs4_sequence_res {
    int dummy; 
};

struct nfs_getaclres {
    struct nfs4_sequence_res seq_res;
    size_t acl_len;
};

int decode_compound_hdr(struct xdr_stream *, struct compound_hdr *);
int decode_sequence(struct xdr_stream *, struct nfs4_sequence_res *, struct rpc_rqst *);
int decode_putfh(struct xdr_stream *);
int decode_getacl(struct xdr_stream *, struct rpc_rqst *, size_t *);