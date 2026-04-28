#include <stdint.h>
#include <netinet/in.h>

typedef uint32_t __be32;

struct kvec {
    void *iov_base;
    size_t iov_len;
};

struct svc_rqst {
    struct {
        struct kvec *head;
        unsigned int page_len;
    } rq_arg;
    struct kvec rq_vec[8];
    void *rq_pages[8];
};

struct nfsd_writeargs {
    unsigned char fh[128];  // Simplified placeholder for knfsd_fh
    unsigned int offset;
    unsigned int len;
    int vlen;
};

__be32 *decode_fh(__be32 *p, unsigned char *fhp);

#define NFSSVC_MAXBLKSIZE_V2 8192
#define XDR_QUADLEN(len) (((len) + 3) >> 2)
#define PAGE_SIZE 4096

static inline void *page_address(void *page) {
    return page;
}