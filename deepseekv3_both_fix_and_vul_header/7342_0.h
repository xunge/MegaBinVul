#include <ctype.h>
#include <string.h>

#define HTTP_MAX_URI 2048
#define DEBUG_printf(x)
#define DEBUG_puts(x)

extern size_t web_files;
extern struct {
    const char *name;
} *web_cache;

extern const char *file_find_check(const char *filename);
extern size_t strlcpy(char *dst, const char *src, size_t siz);