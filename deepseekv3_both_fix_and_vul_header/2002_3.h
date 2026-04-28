#include <stdint.h>
#include <stddef.h>

#define RDS_FLAG_CONG_BITMAP 0x1
#define RDS_CONG_MAP_BYTES 64
#define GFP_KERNEL 0
#define KM_USER0 0
#define BUG_ON(cond) ((void)0)

typedef uint32_t __be32;
typedef uint64_t __be64;
typedef uint64_t u64;

struct scatterlist {
    unsigned int length;
};

struct rds_header {
    uint8_t dummy;
};

struct rds_inc {
    struct {
        __be32 h_len;
        __be64 h_sequence;
        unsigned int h_flags;
    } i_hdr;
};

struct rds_connection {
    struct rds_inc *c_fcong;
    unsigned int c_xmit_data_off;
    __be32 c_laddr;
    __be32 c_faddr;
};

struct rds_message {
    struct rds_inc m_inc;
    struct {
        struct scatterlist *op_sg;
    } data;
};

static inline __be32 be32_to_cpu(__be32 val) { return val; }
static inline __be64 be64_to_cpu(__be64 val) { return val; }
#define min_t(type, x, y) ((type)(x) < (type)(y) ? (type)(x) : (type)(y))

static inline void rds_cong_map_updated(struct rds_inc *inc, u64 mask) {}
static inline void rds_inc_init(struct rds_inc *inc, struct rds_connection *conn, __be32 addr) {}
static inline void rds_message_addref(struct rds_message *rm) {}
static inline void rds_recv_incoming(struct rds_connection *conn, __be32 laddr, __be32 faddr, struct rds_inc *inc, int gfp, int km) {}
static inline void rds_send_drop_acked(struct rds_connection *conn, __be64 sequence, void *arg) {}
static inline void rds_inc_put(struct rds_inc *inc) {}