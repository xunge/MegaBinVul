#include <stdint.h>
#include <stdatomic.h>
#include <stddef.h>

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

struct ib_srq {
    struct ib_pd *pd;
};

struct ib_pd {
};

struct ib_srq_init_attr {
    struct {
        uint32_t max_wr;
        uint32_t max_sge;
        uint32_t srq_limit;
    } attr;
    int srq_type;
};

struct ib_udata {
};

struct bnxt_qplib_pd {
    // Minimal definition
};

struct bnxt_qplib_dev_attr {
    uint32_t max_srq_wqes;
};

struct bnxt_qplib_res {
    // Minimal definition
};

struct bnxt_qplib_dpi {
    // Minimal definition
};

struct bnxt_qplib_srq {
    uint32_t id;
    uint32_t max_wqe;
    uint32_t max_sge;
    uint32_t threshold;
    struct bnxt_qplib_pd *pd;
    struct bnxt_qplib_dpi *dpi;
    uint32_t eventq_hw_ring_id;
};

struct bnxt_re_pd {
    struct ib_pd ib_pd;
    struct bnxt_re_dev *rdev;
    struct bnxt_qplib_pd qplib_pd;
};

struct bnxt_qplib_nq {
    uint32_t ring_id;
    int budget;
};

struct bnxt_re_dev {
    struct bnxt_qplib_dev_attr dev_attr;
    struct bnxt_qplib_res qplib_res;
    struct bnxt_qplib_dpi dpi_privileged;
    struct bnxt_qplib_nq *nq;
    atomic_int srq_count;
};

struct bnxt_re_srq {
    struct ib_srq ib_srq;
    struct bnxt_re_dev *rdev;
    struct bnxt_qplib_srq qplib_srq;
    void *umem;
    uint32_t srq_limit;
};

struct bnxt_re_srq_resp {
    uint32_t srqid;
};

#define IB_SRQT_BASIC 0
#define EINVAL 22
#define EOPNOTSUPP 95

static inline uint32_t roundup_pow_of_two(uint32_t n) {
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    return n + 1;
}