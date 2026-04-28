#include <string.h>

#define FAIL 1
#define OK 0
#define NUL '\0'

typedef unsigned char char_u;

struct block_def {
    int startspaces;
    int endspaces;
    int textlen;
    char_u *textstart;
};

struct yank_register {
    char_u **y_array;
} *y_current;

#define VIM_ISWHITE(c) ((c) == ' ' || (c) == '\t')

void *alloc(size_t size);
void vim_memset(void *s, int c, size_t n);
void *mch_memmove(void *dest, const void *src, size_t n);
int mb_head_off(const char_u *s, const char_u *s_end);