#include <stdlib.h>

struct xen_flask_boolean {
    int bool_id;
    char *name;
    unsigned int size;
};

extern int bool_maxstr;
extern int flask_copyin_string(char *src, char **dst, unsigned int size, ...);
extern int security_find_bool(char *name);
extern void xfree(void *ptr);