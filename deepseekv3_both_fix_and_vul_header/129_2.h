#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define FALSE 0
#define TRUE 1
#define NUL '\0'
#define FAIL 0
#define OK 1
#define IOSIZE 1024

typedef unsigned char char_u;

typedef struct growarray {
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
    void *ga_data;
} garray_T;

static char_u IObuff[IOSIZE];
static char_u *compl_orig_text;
static int has_mbyte;

#define ALLOC_MULT(type, count) ((type *)malloc((count) * sizeof(type)))
#define vim_free(ptr) free(ptr)
#define ga_init2(gap, itemsize, growsize) \
    do { \
        (gap)->ga_len = 0; \
        (gap)->ga_maxlen = 0; \
        (gap)->ga_itemsize = itemsize; \
        (gap)->ga_growsize = growsize; \
        (gap)->ga_data = NULL; \
    } while (0)

static int ga_grow(garray_T *gap, int n) {
    if (gap->ga_maxlen >= gap->ga_len + n)
        return OK;
    gap->ga_data = realloc(gap->ga_data, 
                          (gap->ga_maxlen = gap->ga_len + gap->ga_growsize) * gap->ga_itemsize);
    return gap->ga_data ? OK : FAIL;
}

#define ga_clear(gap) free((gap)->ga_data)
#define STRCPY(dst, src) strcpy((char *)(dst), (char *)(src))
#define STRLEN(str) strlen((char *)(str))

#define MB_ISLOWER(c) islower(c)
#define MB_ISUPPER(c) isupper(c)
#define MB_TOLOWER(c) tolower(c)
#define MB_TOUPPER(c) toupper(c)

static int (*mb_ptr2char_adv)(char_u **);
static int (*mb_char2bytes)(int, char_u *);