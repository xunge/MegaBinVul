#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

struct file;
struct io_fixed_file {
    unsigned long file_ptr;
};

struct io_file_table {
    struct io_fixed_file *files;
};

struct io_ring_ctx {
    unsigned int nr_user_files;
    struct io_file_table file_table;
};

struct io_kiocb {
    unsigned int flags;
};

#define IO_URING_F_NONBLOCK 0x00000001
#define FFS_MASK (~0U)
#define REQ_F_NOWAIT_READ_BIT 0

static inline bool unlikely(bool x) { return x; }
static inline int array_index_nospec(int index, int size) { return index < size ? index : 0; }
static inline struct io_fixed_file *io_fixed_file_slot(struct io_file_table *table, int fd) { return &table->files[fd]; }
static inline void io_ring_submit_lock(struct io_ring_ctx *ctx, bool nested) {}
static inline void io_ring_submit_unlock(struct io_ring_ctx *ctx, bool nested) {}
static inline void io_req_set_rsrc_node(struct io_kiocb *req) {}