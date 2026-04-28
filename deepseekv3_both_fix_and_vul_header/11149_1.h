#include <stddef.h>
#include <string.h>
#include <stdint.h>

#define GITERR_INVALID 1
#define GITERR_CHECK_ALLOC(ptr) if (!(ptr)) { goto fail; }
#define GITERR_CHECK_ALLOC_ADD(out, a, b) \
    do { \
        if ((a) > SIZE_MAX - (b)) { \
            giterr_set(GITERR_INVALID, "allocation size overflow"); \
            goto fail; \
        } \
        *(out) = (a) + (b); \
    } while (0)

extern void giterr_set(int error, const char *message);
extern void *git__malloc(size_t size);
extern void git__free(void *ptr);

static int hdr_sz(size_t *sz, const unsigned char **delta, const unsigned char *delta_end);