#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>
#include <sys/types.h>

typedef uint64_t u64;
typedef uint32_t u32;
typedef size_t binder_size_t;

#define ALIGN(x, a) __ALIGN_KERNEL((x), (a))
#define __ALIGN_KERNEL(x, a) __ALIGN_KERNEL_MASK(x, (typeof(x))(a) - 1)
#define __ALIGN_KERNEL_MASK(x, mask) (((x) + (mask)) & ~(mask))

#define BINDER_DEBUG_TRANSACTION 0
#define BINDER_TYPE_BINDER 0
#define BINDER_TYPE_WEAK_BINDER 1
#define BINDER_TYPE_HANDLE 2
#define BINDER_TYPE_WEAK_HANDLE 3
#define BINDER_TYPE_FD 4
#define BINDER_TYPE_PTR 5
#define BINDER_TYPE_FDA 6

#define WARN_ON(condition) ((void)0)

struct binder_alloc {
    // placeholder for binder alloc structure
};

struct binder_proc {
    pid_t pid;
    struct binder_alloc alloc;
};

struct binder_thread {
    bool looper_need_return;
};

struct binder_buffer {
    int debug_id;
    size_t data_size;
    size_t offsets_size;
    void *user_data;
    struct binder_node *target_node;
};

struct binder_node {
    int debug_id;
    u64 ptr;
};

struct binder_ref_data {
    int debug_id;
    int desc;
};

struct binder_object_header {
    int type;
};

struct binder_object {
    struct binder_object_header hdr;
};

struct flat_binder_object {
    struct binder_object_header hdr;
    u64 binder;
    int handle;
};

struct binder_fd_array_object {
    struct binder_object_header hdr;
    binder_size_t parent;
    binder_size_t parent_offset;
    size_t num_fds;
};

struct binder_buffer_object {
    void *buffer;
    size_t length;
};

static inline struct flat_binder_object *to_flat_binder_object(struct binder_object_header *hdr) {
    return (struct flat_binder_object *)hdr;
}

static inline struct binder_fd_array_object *to_binder_fd_array_object(struct binder_object_header *hdr) {
    return (struct binder_fd_array_object *)hdr;
}

static void binder_debug(int level, const char *fmt, ...) {}
static void binder_dec_node(struct binder_node *node, int a, int b) {}
static bool binder_alloc_copy_from_buffer(struct binder_alloc *alloc, void *dest, 
                                         struct binder_buffer *buffer, binder_size_t offset, size_t size) { return false; }
static size_t binder_get_object(struct binder_proc *proc, void *a, struct binder_buffer *buffer, 
                               binder_size_t offset, struct binder_object *object) { return 0; }
static void pr_err(const char *fmt, ...) {}
static struct binder_node *binder_get_node(struct binder_proc *proc, u64 binder) { return NULL; }
static void binder_put_node(struct binder_node *node) {}
static int binder_dec_ref_for_handle(struct binder_proc *proc, int handle, bool a, struct binder_ref_data *rdata) { return 0; }
static struct binder_buffer_object *binder_validate_ptr(struct binder_proc *proc, struct binder_buffer *buffer, 
                                                      struct binder_object *object, binder_size_t parent, 
                                                      binder_size_t offset, void *a, binder_size_t num_valid) { return NULL; }
static void binder_deferred_fd_close(u32 fd) {}