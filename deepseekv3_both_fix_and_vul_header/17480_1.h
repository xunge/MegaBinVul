#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define FAIL -1
#define IOSIZE 1024

typedef char char_u;
typedef struct {
    char *ga_data;
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} garray_T;

static char_u IObuff[IOSIZE];
static char_u *compl_orig_text;
static int has_mbyte;

#define MB_ISLOWER(c) (islower(c))
#define MB_ISUPPER(c) (isupper(c))
#define MB_TOLOWER(c) tolower(c)
#define MB_TOUPPER(c) toupper(c)

#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))

static int mb_ptr2char_adv(char_u **p) { return **p; }
static int mb_char2bytes(int c, char_u *buf) { *buf = c; return 1; }
static void ga_init2(garray_T *gap, int itemsize, int growsize) {
    gap->ga_data = NULL;
    gap->ga_len = 0;
    gap->ga_maxlen = 0;
    gap->ga_itemsize = itemsize;
    gap->ga_growsize = growsize;
}
static int ga_grow(garray_T *gap, int n) {
    return 0;
}
static void ga_clear(garray_T *gap) {
    free(gap->ga_data);
}
static void vim_free(void *p) {
    free(p);
}
static char_u *STRCPY(char_u *dest, char_u *src) {
    return strcpy(dest, src);
}
static int STRLEN(char_u *str) {
    return strlen(str);
}