#include <stddef.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define SECURITY__CHECK_CONTEXT 0

struct domain {
    struct domain *domain;
};

struct xen_flask_sid_context {
    char *context;
    size_t size;
    int sid;
};

extern struct domain *current;
extern int domain_has_security(struct domain *domain, int permission);
extern int flask_copyin_string(char *src, char **dst, size_t size, ...);
extern int security_context_to_sid(char *buf, size_t size, int *sid);
extern void xfree(void *ptr);