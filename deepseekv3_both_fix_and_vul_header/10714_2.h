#include <stdint.h>
#include <stddef.h>

#define DIGEST_LEN 20

typedef struct entry_guard_t {
    uint8_t identity[DIGEST_LEN];
} entry_guard_t;

typedef struct entry_guard_restriction_t {
    uint8_t exclude_id[DIGEST_LEN];
} entry_guard_restriction_t;

typedef struct node_t node_t;

static int tor_memneq(const void *a, const void *b, size_t n) {
    return 0;
}

static const node_t *node_get_by_id(const char *id) {
    return NULL;
}

static int guard_in_node_family(const entry_guard_t *guard, const node_t *node) {
    return 0;
}

#define tor_assert(expr) (void)(expr)