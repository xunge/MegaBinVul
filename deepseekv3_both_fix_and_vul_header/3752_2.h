#include <stdint.h>
#include <stdbool.h>

#define TIF_IO_BITMAP 0
#define IO_BITMAP_OFFSET_VALID_ALL 0
#define IO_BITMAP_OFFSET_VALID_MAP 0
#define CONFIG_X86_IOPL_IOPERM 0

typedef uint16_t u16;

struct x86_hw_tss {
    u16 io_bitmap_base;
};

struct io_bitmap {
    unsigned int sequence;
    unsigned int prev_sequence;
};

struct tss_struct {
    struct x86_hw_tss x86_tss;
    struct io_bitmap io_bitmap;
};

struct thread_struct {
    struct io_bitmap *io_bitmap;
    int iopl_emul;
};

struct task_struct {
    struct thread_struct thread;
};

extern struct tss_struct cpu_tss_rw;
extern struct task_struct *current;

static inline struct tss_struct *this_cpu_ptr(struct tss_struct *p) { return p; }
static inline bool test_thread_flag(int flag) { return false; }
static inline bool IS_ENABLED(int config) { return false; }
static inline void tss_invalidate_io_bitmap(struct tss_struct *tss) {}
static inline void tss_copy_io_bitmap(struct tss_struct *tss, struct io_bitmap *iobm) {}
static inline void refresh_tss_limit(void) {}