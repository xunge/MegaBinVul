#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

typedef struct zckMP {
    char *buffer;
    size_t buffer_len;
    size_t length;
    int state;
} zckMP;

typedef struct zckDL {
    void *zck;
    zckMP *mp;
    regex_t *dl_regex;
    regex_t *end_regex;
} zckDL;

#define ALLOCD_BOOL(x, y)
#define VALIDATE_BOOL(x)
#define zck_log(x, y, ...)
#define ZCK_LOG_ERROR 0
#define ZCK_LOG_DEBUG 0
#define zmalloc(x) malloc(x)
#define zrealloc(x, y) realloc(x, y)
#define dl_write_range(x, y, z) 0

bool gen_regex(zckDL *dl);
void set_error(void *zck, const char *msg);