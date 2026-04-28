#include <stdint.h>
#include <stdlib.h>

#define PAGE_SIZE 4096
#define SECURITY__COMPUTE_USER 0
#define EFAULT 14

typedef uint32_t u32;

struct domain {
    int domain;
};

struct xen_flask_userlist {
    union {
        char *user;
        u32 *sids;
    } u;
    u32 size;
    u32 start_sid;
};

extern struct domain *current;

int domain_has_security(int domain, int permission);
int flask_copyin_string(char *src, char **dst, u32 size, ...);
int security_get_user_sids(u32 start_sid, char *user, u32 **sids, u32 *nsids);
int copy_to_guest(void *dst, void *src, u32 size);
void xfree(void *ptr);