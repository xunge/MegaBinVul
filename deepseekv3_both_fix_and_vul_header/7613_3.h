#include <stdint.h>
#include <stdbool.h>

typedef uint32_t u32;

struct list_head {
    struct list_head *next, *prev;
};

struct io_submit_link {
    void *head;
    struct {
        int opcode;
        unsigned flags;
    } *last;
};

struct io_timeout_data {
    struct io_kiocb *req;
    unsigned flags;
    struct {
        int64_t tv_sec;
        long tv_nsec;
    } ts;
    int mode;
    void *timer;
};

struct io_kiocb {
    struct {
        struct list_head list;
        u32 off;
        void *head;
    } timeout;
    void *async_data;
    struct {
        struct {
            unsigned flags;
            bool off_timeout_used;
            struct {
                struct io_submit_link link;
            } submit_state;
        } *ctx;
    };
};

struct io_uring_sqe {
    u32 off;
    u32 ioprio;
    u32 buf_index;
    u32 len;
    u32 splice_fd_in;
    u32 timeout_flags;
    uint64_t addr;
};

#define READ_ONCE(x) (x)
#define WARN_ON_ONCE(x) (x)
#define unlikely(x) (x)
#define hweight32(x) (x)

#define IORING_SETUP_IOPOLL (1 << 0)
#define IORING_TIMEOUT_ABS (1 << 0)
#define IORING_TIMEOUT_CLOCK_MASK (0x0F << 1)
#define IORING_TIMEOUT_ETIME_SUCCESS (1 << 5)
#define IORING_OP_LINK_TIMEOUT 0
#define REQ_F_ARM_LTIMEOUT (1 << 0)

#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

static inline void INIT_LIST_HEAD(struct list_head *list) {
    list->next = list;
    list->prev = list;
}

static inline bool req_has_async_data(struct io_kiocb *req) { return false; }
static inline int io_alloc_async_data(struct io_kiocb *req) { return 0; }
static inline int get_timespec64(struct io_timeout_data *data, const void *addr) { return 0; }
static inline void *u64_to_user_ptr(uint64_t addr) { return (void *)(uintptr_t)addr; }
static inline int io_translate_timeout_mode(unsigned flags) { return 0; }
static inline int io_timeout_get_clock(struct io_timeout_data *data) { return 0; }
static inline void hrtimer_init(void *timer, int clock, int mode) {}