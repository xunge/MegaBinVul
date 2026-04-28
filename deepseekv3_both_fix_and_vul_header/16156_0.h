#include <string.h>
#include <stddef.h>

struct link_map {
    const char *l_origin;
};

extern const char *_dl_platform;
extern int __libc_enable_secure;

char *__stpcpy(char *dest, const char *src);