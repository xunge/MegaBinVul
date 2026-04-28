#include <string.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define GFP_KERNEL 0

#define LEGACY_FS_MONOLITHIC_PARAMS 1
#define LEGACY_FS_INDIVIDUAL_PARAMS 2
#define ENOPARAM (-100)
#define ENOMEM (-12)

struct fs_context {
    void *fs_private;
};

struct fs_parameter {
    int type;
    char *key;
    char *string;
    size_t size;
};

struct legacy_fs_context {
    unsigned int data_size;
    int param_type;
    char *legacy_data;
};

enum {
    fs_value_is_string,
    fs_value_is_flag
};

#define fallthrough

static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline int vfs_parse_fs_param_source(struct fs_context *fc, struct fs_parameter *param) { return -ENOPARAM; }
static inline int invalf(struct fs_context *fc, const char *fmt, ...) { return -1; }