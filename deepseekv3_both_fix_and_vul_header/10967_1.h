#include <stdbool.h>
#include <stddef.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define IORING_MAX_ENTRIES 32768
#define IORING_MAX_CQ_ENTRIES (2 * IORING_MAX_ENTRIES)
#define CAP_IPC_LOCK 0
#define IORING_SETUP_CQSIZE (1U << 1)
#define IORING_FEAT_SINGLE_MMAP (1U << 0)
#define IORING_FEAT_NODROP (1U << 1)
#define EINVAL 22
#define ENOMEM 12

struct user_struct;
struct io_ring_ctx;
struct cred;

struct io_rings {
    struct {
        unsigned head;
        unsigned tail;
    } sq;
    unsigned sq_ring_mask;
    unsigned sq_ring_entries;
    unsigned sq_flags;
    unsigned sq_dropped;
    struct {
        unsigned head;
        unsigned tail;
    } cq;
    unsigned cq_ring_mask;
    unsigned cq_ring_entries;
    unsigned cq_overflow;
    void *cqes;
};

struct io_uring_params {
    unsigned sq_entries;
    unsigned cq_entries;
    unsigned flags;
    unsigned features;
    struct {
        unsigned head;
        unsigned tail;
        unsigned ring_mask;
        unsigned ring_entries;
        unsigned flags;
        unsigned dropped;
        unsigned array;
    } sq_off;
    struct {
        unsigned head;
        unsigned tail;
        unsigned ring_mask;
        unsigned ring_entries;
        unsigned overflow;
        unsigned cqes;
    } cq_off;
};

struct io_ring_ctx {
    bool compat;
    bool account_mem;
    struct user_struct *user;
    struct cred *creds;
    void *sq_array;
    struct io_rings *rings;
};

static inline unsigned roundup_pow_of_two(unsigned n) { return n; }
static struct user_struct *current_user(void) { return NULL; }
static struct user_struct *get_uid(struct user_struct *user) { return user; }
static int capable(int cap) { return 0; }
static int io_account_mem(struct user_struct *user, unsigned pages) { return 0; }
static void free_uid(struct user_struct *user) {}
static void io_unaccount_mem(struct user_struct *user, unsigned pages) {}
static struct io_ring_ctx *io_ring_ctx_alloc(struct io_uring_params *p) { return NULL; }
static int in_compat_syscall(void) { return 0; }
static struct cred *prepare_creds(void) { return NULL; }
static int io_allocate_scq_urings(struct io_ring_ctx *ctx, struct io_uring_params *p) { return 0; }
static int io_sq_offload_start(struct io_ring_ctx *ctx, struct io_uring_params *p) { return 0; }
static int io_uring_get_fd(struct io_ring_ctx *ctx) { return 0; }
static void trace_io_uring_create(int ret, struct io_ring_ctx *ctx, unsigned sq_entries, unsigned cq_entries, unsigned flags) {}
static void io_ring_ctx_wait_and_kill(struct io_ring_ctx *ctx) {}
static unsigned ring_pages(unsigned sq_entries, unsigned cq_entries) { return 0; }