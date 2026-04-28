#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned char char_u;
typedef int bool;

#define FALSE 0
#define TRUE 1
#define FAIL (-1)
#define NUL '\0'
#define Ctrl_Z 0x1A
#define Ctrl_V 0x16

typedef struct {
    void *ga_data;
    int ga_len;
    int ga_maxlen;
} garray_T;

typedef struct {
    FILE *fp;
    int sourcing_lnum;
    bool source_from_buf;
    int buf_lnum;
    garray_T buflines;
    int fileformat;
    bool error;
} source_cookie_T;

#define EOL_UNKNOWN 0
#define EOL_UNIX 1
#define EOL_DOS 2

#define USE_CRNL

#define HL_ATTR(x) (x)
#define HLF_W 0

void ga_init2(garray_T *gap, int size, int len);
int ga_grow(garray_T *gap, int n);
void ga_concat(garray_T *gap, char_u *s);
void vim_free(void *p);
void msg_source(int attr);
void emsg(const char *s);
void line_breakcheck(void);