#include <stdint.h>
#include <stddef.h>

struct domain {
    uint64_t generation;
};

extern struct domain *find_domain_struct(unsigned int domid);
extern int get_domain_info(unsigned int domid, void *dominfo);
extern struct domain *alloc_domain(void *ptr, unsigned int domid);
extern void *xc_handle;

typedef struct {
    // Add dominfo fields if needed
} xc_dominfo_t;