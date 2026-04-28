#include <stdbool.h>
#include <errno.h>
#include <stddef.h>

struct domain {
    unsigned int memory;
};

struct domain *find_domain_struct(unsigned int domid);
bool domain_chk_quota(struct domain *domain, unsigned int mem);
void corrupt(void *ptr, const char *format, ...);