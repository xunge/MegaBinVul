#include <stddef.h>
#include <sys/types.h>

struct file {
    // dummy definition
};
struct dir_context {
    // dummy definition  
};
struct ctl_table_header {
    // dummy definition
};
struct ctl_table {
    // dummy definition
};
struct ctl_dir {
    struct ctl_table_header header;
    // other members
};

#define IS_ERR(x) ((unsigned long)(x) > (unsigned long)-1000L)
#define PTR_ERR(x) ((long)(x))

static inline struct inode *file_inode(struct file *file) { return (struct inode *)0; }
static inline struct ctl_table_header *grab_header(struct inode *inode) { return NULL; }
static inline int dir_emit_dots(struct file *file, struct dir_context *ctx) { return 0; }
static inline void first_entry(struct ctl_dir *dir, struct ctl_table_header **h, struct ctl_table **e) {}
static inline void next_entry(struct ctl_table_header **h, struct ctl_table **e) {}
static inline int scan(struct ctl_table_header *h, struct ctl_table *e, unsigned long *p, struct file *f, struct dir_context *ctx) { return 0; }
static inline void sysctl_head_finish(struct ctl_table_header *h) {}

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))