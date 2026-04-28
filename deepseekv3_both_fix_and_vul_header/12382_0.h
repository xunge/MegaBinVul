#include <limits.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;
typedef int bufinfo_T;
typedef int vim_conv_T;

#define TRUE 1
#define FALSE 0
#define LONG_MAX __LONG_MAX__
#define U_ALLOC_LINE(size) malloc(size)
#define U_DEBUG
#define UE_MAGIC 0x12345678

typedef struct u_entry_S {
    int ue_magic;
    int ue_top;
    int ue_bot;
    int ue_lcount;
    int ue_size;
    char_u **ue_array;
} u_entry_T;

static int undo_read_4c(bufinfo_T *bi);
static char_u *read_string_decrypt(bufinfo_T *bi, int len);
static void corruption_error(const char *msg, char_u *file_name);
static void vim_memset(void *s, int c, size_t n);