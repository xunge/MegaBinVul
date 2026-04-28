#include <stdbool.h>

#define R_API

struct RParseCur {
    int (*parse)(struct RParse *p, const char *data, char *str);
    void *data;
};

typedef struct RParse {
    struct RParseCur *cur;
} RParse;