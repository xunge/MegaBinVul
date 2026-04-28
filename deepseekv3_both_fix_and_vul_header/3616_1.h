#include <stdint.h>
#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SMALL_FILE_SIZE (10 * 1024 * 1024)
#define CLEANUP_FREE __attribute__((cleanup(free_ptr)))
#define _(x) x

typedef struct guestfs_h guestfs_h;

static inline void free_ptr(void *ptr) {
    free(*(void **)ptr);
}

char *safe_strdup(guestfs_h *g, const char *str);
char **guestfs_head_n(guestfs_h *g, int n, const char *path);
int64_t guestfs_filesize(guestfs_h *g, const char *path);
void guestfs___free_string_list(char **argv);
void error(guestfs_h *g, const char *fmt, ...);