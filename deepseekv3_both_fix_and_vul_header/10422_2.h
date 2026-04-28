#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#define NFS3_MAXPATHLEN 1024
#define PAGE_SIZE 4096

typedef uint32_t __be32;

struct svc_rqst {
    struct {
        struct kvec *head;
        unsigned int page_len;
        void **pages;
    } rq_arg;
    void **rq_next_page;
};

struct nfsd3_symlinkargs {
    void *ffh;
    char *fname;
    int flen;
    void *attrs;
    char *tname;
    int tlen;
};

struct kvec {
    void *iov_base;
    size_t iov_len;
};

extern __be32 *decode_fh(__be32 *p, void *fh);
extern __be32 *decode_filename(__be32 *p, char **name, int *len);
extern __be32 *decode_sattr3(__be32 *p, void *attrs);
extern void *page_address(void *page);

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })