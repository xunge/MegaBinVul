#include <string.h>

#define NUL '\0'

typedef struct buffblock_S buffblock_T;
typedef struct buffheader_S buffheader_T;

struct buffblock_S {
    char *b_str;
};

struct buffheader_S {
    buffblock_T *bh_curr;
    int bh_space;
};

#define STRLEN(s) strlen(s)