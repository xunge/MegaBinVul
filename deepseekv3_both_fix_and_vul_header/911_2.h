#include <stdbool.h>
#include <stddef.h>

#define DOMID_XEN 0
#define DOMID_IO 1
#define DOMID_COW 2
#define __init

struct domain;
typedef unsigned int domid_t;

extern struct domain *dom_xen;
extern struct domain *dom_io;
extern struct domain *dom_cow;

struct domain *domain_create(domid_t domid, void *data, bool is_privileged);
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))
#define PTR_ERR(ptr) ((long)(ptr))
void panic(const char *fmt, ...);