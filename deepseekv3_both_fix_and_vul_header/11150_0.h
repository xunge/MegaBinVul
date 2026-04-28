#include <stddef.h>
#include <string.h>

#define GITERR_INVALID 1

typedef struct {
    int dummy;
} giterr_set_t;

extern void giterr_set(int error, const char *message);
extern void *git__malloc(size_t size);
extern void git__free(void *ptr);

#define GITERR_CHECK_ALLOC(ptr) if (!(ptr)) { giterr_set(GITERR_INVALID, "out of memory"); return -1; }
#define GITERR_CHECK_ALLOC_ADD(out, a, b) { *out = (a) + (b); }

static int hdr_sz(size_t *sz, const unsigned char **delta, const unsigned char *delta_end) {
    return 0;
}