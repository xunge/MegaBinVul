#include <stddef.h>
#include <errno.h>
#include <string.h>

typedef struct pool pool;

typedef struct array_header {
    void *elts;
} array_header;

typedef struct cmd_rec {
    pool *pool;
    pool *tmp_pool;
    int stash_index;
    unsigned int stash_hash;
    int argc;
    char **argv;
    char *arg;
    void *notes;
} cmd_rec;

#define FALSE 0
#define TRUE 1

#define PR_ISSPACE(c) ((c) == ' ' || (c) == '\t' || (c) == '\n' || (c) == '\r' || (c) == '\f' || (c) == '\v')
#define PR_STR_FL_PRESERVE_COMMENTS 0x01
#define PR_STR_FL_IGNORE_QUOTES 0x02