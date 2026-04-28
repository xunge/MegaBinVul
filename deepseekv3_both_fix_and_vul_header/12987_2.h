#include <stdlib.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint32_t gfp_t;

struct nft_ctx {
    // 添加必要的字段
    int dummy;  // 示例字段
};

struct list_head {
    struct list_head *next, *prev;
};

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

struct nft_trans {
    struct list_head list;
    int msg_type;
    struct nft_ctx ctx;
};

void *kzalloc(size_t size, gfp_t flags);