#include <stdbool.h>
#include <stdint.h>

#define EBADF 9
#define ENXIO 6
#define EINVAL 22
#define FFS_MASK 0xFFFFFFFF

typedef uint32_t u32;

struct file;
struct io_rsrc_data;
struct io_rsrc_node;

struct io_file_table {
    // 最小化定义以满足编译
    void* bitmap;
    u32 size;
};

struct io_fixed_file {
    unsigned long file_ptr;
};

struct io_ring_ctx {
    struct io_rsrc_data *file_data;
    u32 nr_user_files;
    struct io_file_table file_table;
    struct io_rsrc_node *rsrc_node;
};

#define __must_hold(x)

// 函数声明
static inline u32 array_index_nospec(u32 index, u32 size);
static inline int io_is_uring_fops(struct file *file);
static inline struct io_fixed_file* io_fixed_file_slot(struct io_file_table *table, u32 slot);
static inline int io_rsrc_node_switch_start(struct io_ring_ctx *ctx);
static inline int io_queue_rsrc_removal(struct io_rsrc_data *data, u32 slot, 
                                      struct io_rsrc_node *node, struct file *file);
static inline void io_file_bitmap_clear(struct io_file_table *table, u32 slot);
static inline int io_scm_file_account(struct io_ring_ctx *ctx, struct file *file);
static inline int* io_get_tag_slot(struct io_rsrc_data *data, u32 slot);
static inline void io_fixed_file_set(struct io_fixed_file *slot, struct file *file);
static inline void io_file_bitmap_set(struct io_file_table *table, u32 slot);
static inline void io_rsrc_node_switch(struct io_ring_ctx *ctx, struct io_rsrc_data *data);
static inline void fput(struct file *file);

// 最小实现
static inline u32 array_index_nospec(u32 index, u32 size) { 
    return index < size ? index : 0; 
}