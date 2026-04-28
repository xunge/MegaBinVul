#include <stddef.h>
#include <errno.h>

struct connection;
struct node;
struct domain;
struct perm;

struct perms {
    struct perm *p;
};

struct connection {
    unsigned int id;
    struct domain *domain;
    void *transaction;
};

struct node {
    char *name;
    struct perms perms;
};

struct perm {
    unsigned int id;
};

struct domain {
    unsigned int nbentry;
};

void transaction_entry_dec(void *transaction, unsigned int domid);
struct domain *find_domain_struct(unsigned int domid);
void corrupt(struct connection *conn, const char *fmt, ...);