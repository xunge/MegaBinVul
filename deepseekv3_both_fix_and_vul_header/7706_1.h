#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;

typedef struct garray_S {
    int ga_len;
    int ga_maxlen;
    char_u *ga_data;
} garray_T;

typedef struct source_cookie_S {
    int sourcing_lnum;
    int source_from_buf;
    int buf_lnum;
    garray_T buflines;
    FILE *fp;
    int fileformat;
    int error;
} source_cookie_T;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define NUL '\0'
#define Ctrl_V 22
#define Ctrl_Z 26
#define EOL_UNKNOWN 0
#define EOL_UNIX 1
#define EOL_DOS 2
#define HL_ATTR(x) (x)
#define HLF_W 0

#define STRLEN(s) strlen((const char *)(s))

static void ga_init2(garray_T *gap, int size, int growsize)
{
    gap->ga_len = 0;
    gap->ga_maxlen = growsize;
    gap->ga_data = malloc(growsize);
}

static int ga_grow(garray_T *gap, int n)
{
    return 0;
}

static void ga_concat(garray_T *gap, const char_u *s)
{
    size_t len = strlen((const char *)s);
    if (gap->ga_len + len >= gap->ga_maxlen) {
        gap->ga_maxlen = gap->ga_len + len + 1;
        gap->ga_data = realloc(gap->ga_data, gap->ga_maxlen);
    }
    memcpy(gap->ga_data + gap->ga_len, s, len);
    gap->ga_len += len;
}

static void line_breakcheck(void) {}
static void msg_source(int attr) {}
static void emsg(const char *msg) {}
static void vim_free(void *ptr) { free(ptr); }