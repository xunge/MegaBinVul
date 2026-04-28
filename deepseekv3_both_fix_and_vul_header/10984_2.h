#include <stdint.h>
#include <stdbool.h>

#define likely(x) __builtin_expect(!!(x), 1)

typedef uint64_t u64;

struct cfs_rq {
    u64 runtime_remaining;
    void *curr;
};

struct rq;

void expire_cfs_rq_runtime(struct cfs_rq *cfs_rq);
bool assign_cfs_rq_runtime(struct cfs_rq *cfs_rq);
struct rq *rq_of(struct cfs_rq *cfs_rq);
void resched_curr(struct rq *rq);