#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <stdbool.h>

#define FILT_ERR_TOO_MANY_PREDS 1
#define FILT_ERR_TOO_MANY_OPEN 2
#define FILT_ERR_TOO_MANY_CLOSE 3
#define FILT_ERR_NO_FILTER 4

#define INVERT 1
#define PROCESS_AND 2
#define PROCESS_OR 4

#define GFP_KERNEL 0

#define ERR_PTR(err) ((void *)(long)(err))
#define WARN_ON(cond) (cond)

struct prog_entry {
    void *pred;
    int target;
    bool when_to_branch;
};

struct filter_parse_error {
    int err;
    int pos;
};

typedef int (*parse_pred_fn)(const char *str, void *data, int pos,
                struct filter_parse_error *pe, void **pred);

static inline bool is_not(const char *str)
{
    return str[0] == '!' && str[1] != '=';
}

static void parse_error(struct filter_parse_error *pe, int err, int pos)
{
    pe->err = err;
    pe->pos = pos;
}

static void update_preds(struct prog_entry *prog, int N, int invert)
{
    prog[N].when_to_branch = invert;
}

static void *kmalloc_array(size_t n, size_t size, int flags)
{
    return calloc(n, size);
}

static void *kcalloc(size_t n, size_t size, int flags)
{
    return calloc(n, size);
}

static void kfree(void *ptr)
{
    free(ptr);
}