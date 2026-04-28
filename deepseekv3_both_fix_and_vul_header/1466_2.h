#include <stddef.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_ACTIONS_BUFSIZE 65535
#define NLA_ALIGN(len) (((len) + 3) & ~3)
#define ERR_PTR(error) ((void *)(long)(error))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))
#define OVS_NLERR(log, fmt, ...)
#define EMSGSIZE E2BIG

struct nlattr {
    unsigned short nla_len;
    unsigned short nla_type;
};

struct sw_flow_actions {
    size_t actions_len;
    size_t orig_len;
    struct nlattr actions[];
};

static inline size_t ksize(const void *obj) {
    return 0;
}

static inline int max(int a, int b) {
    return a > b ? a : b;
}

static inline void kfree(void *ptr) {
    free(ptr);
}

static struct sw_flow_actions *nla_alloc_flow_actions(int size) {
    return malloc(size);
}