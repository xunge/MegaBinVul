#include <stdint.h>
#include <stddef.h>

typedef uint32_t __be32;

struct svc_rqst {
    int rq_vers;
    int rq_proc;
    struct svc_procedure *rq_procinfo;
    unsigned int rq_cachetype;
    struct {
        struct {
            void *iov_base;
            size_t iov_len;
        } head[1];
        void *argp;
    } rq_arg;
    struct {
        struct {
            void *iov_base;
            size_t iov_len;
        } head[1];
        void *resp;
    } rq_res;
    unsigned long rq_flags;
    void *rq_argp;
    void *rq_resp;
};

struct svc_procedure {
    int (*pc_decode)(struct svc_rqst *, __be32 *, void *);
    int (*pc_encode)(struct svc_rqst *, __be32 *, void *);
    __be32 (*pc_func)(struct svc_rqst *, void *, void *);
    unsigned int pc_cachetype;
};

typedef int (*kxdrproc_t)(struct svc_rqst *, __be32 *, void *);

enum {
    RC_DROPIT,
    RC_REPLY,
    RC_DOIT,
    RC_NOCACHE
};

#define RQ_DROPME (0)
#define rpc_garbage_args ((__be32)0)
#define rpc_system_err ((__be32)0)
#define nfserr_dropit ((__be32)0)

static inline int test_bit(int nr, const unsigned long *addr) {
    return (*addr >> nr) & 1;
}

void dprintk(const char *fmt, ...);
int nfsd_cache_lookup(struct svc_rqst *rqstp);
void nfsd_cache_update(struct svc_rqst *rqstp, int cachetype, __be32 *statp);
__be32 map_new_errors(unsigned int vers, __be32 nfserr);