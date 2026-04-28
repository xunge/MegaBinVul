#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <sys/socket.h>

struct page {
    // Minimal page structure definition
};

struct rds_sock {
    int rs_recverr;
};

struct rds_message {
    struct {
        int op_active;
        int op_type;
        struct {
            uint64_t add;
            uint64_t nocarry_mask;
        } op_m_fadd;
        struct {
            uint64_t compare;
            uint64_t swap;
            uint64_t compare_mask;
            uint64_t swap_mask;
        } op_m_cswp;
        int op_notify;
        int op_silent;
        int op_recverr;
        void *op_sg;
        struct {
            uint32_t n_user_token;
            int n_status;
        } *op_notifier;
        uint32_t op_rkey;
        uint64_t op_remote_addr;
    } atomic;
};

struct rds_atomic_args {
    uint64_t local_addr;
    uint64_t remote_addr;
    uint64_t cookie;
    uint32_t flags;
    uint32_t user_token;
    union {
        struct {
            uint64_t add;
        } fadd;
        struct {
            uint64_t add;
            uint64_t nocarry_mask;
        } m_fadd;
        struct {
            uint64_t compare;
            uint64_t swap;
        } cswp;
        struct {
            uint64_t compare;
            uint64_t swap;
            uint64_t compare_mask;
            uint64_t swap_mask;
        } m_cswp;
    };
};

enum {
    RDS_CMSG_ATOMIC_FADD,
    RDS_CMSG_MASKED_ATOMIC_FADD,
    RDS_CMSG_ATOMIC_CSWP,
    RDS_CMSG_MASKED_ATOMIC_CSWP
};

enum {
    RDS_ATOMIC_TYPE_FADD,
    RDS_ATOMIC_TYPE_CSWP
};

#define RDS_RDMA_NOTIFY_ME   (1 << 0)
#define RDS_RDMA_SILENT      (1 << 1)
#define RDS_RDMA_SUCCESS     0

#define GFP_KERNEL 0
#define ENOMEM 12
#define EINVAL 22
#define EFAULT 14

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline void put_page(struct page *page) { free(page); }
static inline int rds_message_alloc_sgs(struct rds_message *rm, int count) { return 1; }
static inline int rds_pin_pages(uint64_t addr, int nr_pages, struct page **pages, int flags) { return 1; }
static inline void sg_set_page(void *sg, struct page *page, unsigned int len, unsigned int offset) {}
static inline unsigned int offset_in_page(uint64_t addr) { return addr & 0xFFF; }
static inline uint32_t rds_rdma_cookie_key(uint64_t cookie) { return cookie >> 32; }
static inline uint64_t rds_rdma_cookie_offset(uint64_t cookie) { return cookie & 0xFFFFFFFF; }
#define BUG() abort()