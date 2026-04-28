#include <stdlib.h>
#include <errno.h>

struct connection {
    unsigned int id;
    struct domain *domain;
    void *transaction;
};

struct node {
    struct {
        struct {
            unsigned int id;
        } *p;
    } perms;
};

struct domain {
    unsigned int nbentry;
};

extern struct domain *find_or_alloc_existing_domain(unsigned int domid);
extern void transaction_entry_inc(void *transaction, unsigned int domid);