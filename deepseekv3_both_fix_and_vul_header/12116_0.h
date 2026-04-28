#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct zckCtx zckCtx;
typedef struct zckComp zckComp;

struct zckComp {
    void *data;
    size_t data_size;
    size_t data_loc;
};

#define VALIDATE_BOOL(ptr)
#define ALLOCD_BOOL(ctx, ptr)
#define zrealloc realloc

enum {
    ZCK_LOG_ERROR,
    ZCK_LOG_DEBUG
};

void zck_log(int level, const char *format, ...);