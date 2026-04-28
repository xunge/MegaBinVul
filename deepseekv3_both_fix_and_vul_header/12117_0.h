#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

typedef struct zckCtx zckCtx;
typedef struct zckComp zckComp;

struct zckComp {
    char *dc_data;
    size_t dc_data_size;
};

#define VALIDATE_INT(zck)
#define ALLOCD_INT(zck, ptr)
#define zrealloc realloc
#define zck_log(level, fmt, ...)