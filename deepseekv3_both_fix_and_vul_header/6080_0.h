#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define _cleanup_free_ __attribute__((cleanup(free_ptr)))
#define __attribute__(...)

static inline void free_ptr(void *p) {
        free(*(void**) p);
}

int path_simplify(char *path);
int empty_or_root(const char *path);
int path_is_normalized(const char *path);
void delete_trailing_chars(char *path, const char *trailing);
char *skip_leading_chars(char *path, const char *leading);
char *unit_name_escape(const char *f);