#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdbool.h>

struct Context {
    void *data;
    int msgcount;
    int hdrmax;
    struct Header **hdrs;
};

struct PopData {
    bool clear_cache;
};

struct Header {
    char *data;
    int refno;
    int index;
};

static void mx_alloc_memory(struct Context *ctx);
static struct Header *mutt_header_new(void);
static char *mutt_str_strdup(const char *str);
static int mutt_str_strcmp(const char *a, const char *b);
static void mutt_debug(int level, const char *fmt, ...);