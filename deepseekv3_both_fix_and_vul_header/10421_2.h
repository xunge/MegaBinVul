#include <stdint.h>
#include <arpa/inet.h>

typedef uint32_t __be32;
typedef uint32_t u32;

#define PAGE_SIZE 4096
#define XDR_QUADLEN(len) (((len) + 3) >> 2)

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct svc_rqst {
    struct {
        struct kvec *head;
        struct kvec *tail;
        unsigned int page_len;
    } rq_arg;
    struct kvec rq_vec[16];
    void *rq_pages[16];
};

struct nfsd3_writeargs {
    int fh;
    uint64_t offset;
    uint32_t count;
    uint32_t stable;
    uint32_t len;
    int vlen;
};

static inline __be32 *decode_fh(__be32 *p, int *fh) { return p; }
static inline __be32 *xdr_decode_hyper(__be32 *p, uint64_t *val) { return p; }
static inline uint32_t svc_max_payload(struct svc_rqst *rqstp) { return 0; }
static inline void *page_address(void *page) { return page; }