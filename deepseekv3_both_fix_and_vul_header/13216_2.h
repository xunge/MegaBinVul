#include <stdlib.h>
#include <string.h>

typedef int s32;

#define KiB(x) ((x) * 1024)
#define MiB(x) ((x) * 1024 * 1024)
#define LZP_DICTIONARY 16
#define BZ3_OK 0

typedef struct state {
    // 添加必要的state结构体成员
    int dummy;  // 占位成员，实际使用时需要替换为真实成员
} state;

struct bz3_state {
    state *cm_state;
    void *swap_buffer;
    s32 *sais_array;
    s32 *lzp_lut;
    s32 block_size;
    s32 last_error;
};

size_t bz3_bound(s32 block_size);
size_t BWT_BOUND(s32 block_size);

typedef struct bz3_state bz3_state;