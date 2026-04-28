#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#define GITERR_INVALID 1
#define GITERR_CHECK_ALLOC(ptr) if (!(ptr)) { return -1; }
#define GITERR_CHECK_ALLOC_ADD(out, a, b) *out = (a) + (b)

void giterr_set(int code, const char *msg);

static int hdr_sz(size_t *sz, const unsigned char **delta, const unsigned char *delta_end);

static void *git__malloc(size_t size) {
    return malloc(size);
}

static void git__free(void *ptr) {
    free(ptr);
}