#include <stdint.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

#define RDS_FRAG_SIZE 4096
#define RDS_CONG_MAP_BYTES 64
#define RDS_MAX_ADV_CREDIT 255
#define RDS_FLAG_CONG_BITMAP 0x01
#define RDS_FLAG_ACK_REQUIRED 0x02
#define RDS_FLAG_RETRANSMITTED 0x04
#define RDS_EXTHDR_RDMA 1
#define RDS_LL_SEND_FULL 0
#define RDS_MSG_ACK_REQUIRED 0
#define RDS_MSG_RETRANSMITTED 1
#define ENOMEM 12
#define IB_WR_SEND 0
#define IB_SEND_FENCE (1 << 0)
#define IB_SEND_SIGNALED (1 << 1)
#define IB_SEND_SOLICITED (1 << 2)
#define DMA_TO_DEVICE 1
#define KERN_WARNING ""

typedef uint32_t u32;
typedef uint64_t u64;

enum {
    s_ib_tx_ring_full,
    s_ib_tx_throttle,
    s_ib_tx_sg_mapping_failure,
    s_ib_tx_credit_updates
};

struct rds_connection {
    void *c_transport_data;
    int c_loopback;
    void *c_fcong;
    unsigned long c_flags;
    unsigned int c_xmit_data_off;
    uint32_t c_faddr;
};

struct rds_header {
    uint32_t h_len;
    uint64_t h_ack;
    uint8_t h_flags;
    uint8_t h_credit;
};

struct rds_ext_header_rdma {
    uint32_t h_rdma_rkey;
};

struct ib_send_wr {
    unsigned int send_flags;
    unsigned int opcode;
    unsigned int num_sge;
    struct ib_send_wr *next;
};

struct ib_sge {
    uint64_t addr;
    uint32_t length;
};

struct ib_device;
struct rdma_cm_id {
    struct ib_device *device;
    void *qp;
};

struct scatterlist {
    unsigned long length;
    unsigned int offset;
};

struct rds_data_op {
    struct scatterlist *op_sg;
    unsigned int op_nents;
    unsigned int op_count;
};

struct rds_ib_send_work {
    struct ib_send_wr s_wr;
    struct ib_sge s_sge[2];
    struct rds_data_op *s_op;
    unsigned long s_queued;
};

struct rds_ib_connection {
    struct rdma_cm_id *i_cm_id;
    struct ib_device *i_device;
    struct rds_ib_send_work *i_sends;
    uint64_t i_send_hdrs_dma;
    struct rds_header *i_send_hdrs;
    struct {
        unsigned int w_nr;
    } i_send_ring;
    struct rds_data_op *i_data_op;
    int i_signaled_sends;
    int i_flowctl;
    struct rds_connection *conn;
};

struct rds_message {
    struct {
        struct rds_header i_hdr;
    } m_inc;
    struct rds_data_op data;
    struct {
        int op_active;
        int op_fence;
        uint32_t op_rkey;
    } rdma;
    uint64_t m_rdma_cookie;
    unsigned long m_flags;
};

static inline uint32_t be32_to_cpu(uint32_t x) { return x; }
static inline uint64_t be64_to_cpu(uint64_t x) { return x; }
static inline uint32_t cpu_to_be32(uint32_t x) { return x; }
static inline uint64_t cpu_to_be64(uint64_t x) { return x; }

#define BUG_ON(cond) do { if (cond) abort(); } while (0)
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define ceil(x, y) (((x) + (y) - 1) / (y))

static inline void rds_cong_map_updated(void *fcong, u64 mask) {}
static inline int rds_ib_ring_alloc(void *ring, u32 n, u32 *pos) { return 0; }
static inline void rds_ib_stats_inc(int stat) {}
static inline void set_bit(int nr, unsigned long *addr) {}
static inline int test_bit(int nr, const unsigned long *addr) { return 0; }
static inline void rds_message_addref(struct rds_message *rm) {}
static inline void rds_message_make_checksum(struct rds_header *hdr) {}
static inline void rds_message_add_extension(struct rds_header *hdr, int type, void *data, int len) {}
static inline void rds_message_add_rdma_dest_extension(struct rds_header *hdr, uint32_t key, uint32_t offset) {}
static inline uint32_t rds_rdma_cookie_key(uint64_t cookie) { return 0; }
static inline uint32_t rds_rdma_cookie_offset(uint64_t cookie) { return 0; }
static inline uint64_t rds_ib_piggyb_ack(struct rds_ib_connection *ic) { return 0; }
static inline void rds_ib_set_wr_signal_state(struct rds_ib_connection *ic, struct rds_ib_send_work *send, int state) {}
static inline int ib_post_send(void *qp, struct ib_send_wr *wr, struct ib_send_wr **bad_wr) { return 0; }
static inline void rds_ib_conn_error(struct rds_connection *conn, const char *msg) {}
static inline void rds_ib_sub_signaled(struct rds_ib_connection *ic, int nr) {}
static inline void rds_ib_send_add_credits(struct rds_connection *conn, u32 credits) {}
static inline u32 rds_ib_send_grab_credits(struct rds_ib_connection *ic, u32 wanted, u32 *posted, int need_posted, u32 max) { return 0; }
static inline void rds_ib_ring_unalloc(void *ring, u32 n) {}
static inline int ib_dma_map_sg(struct ib_device *dev, struct scatterlist *sg, int nents, int direction) { return 0; }
static inline unsigned long ib_sg_dma_len(struct ib_device *dev, struct scatterlist *sg) { return 0; }
static inline uint64_t ib_sg_dma_address(struct ib_device *dev, struct scatterlist *sg) { return 0; }
static inline void rdsdebug(const char *fmt, ...) {}
static inline void atomic_add(int i, int *v) {}
static inline int printk(const char *fmt, ...) { return 0; }
static unsigned long jiffies = 0;