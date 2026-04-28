#include <stdlib.h>

#define FAIL 0
#define OK 1

typedef unsigned char char_u;

typedef struct {
    void *ga_data;
    int ga_len;
    int ga_maxlen;
    int ga_itemsize;
    int ga_growsize;
} garray_T;

char_u *vim_strsave(char_u *p);
int ga_grow(garray_T *gap, int n);
void vim_free(void *p);