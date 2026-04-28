#include <errno.h>

struct connection;
struct node;
struct perm {
    int id;
    unsigned int perms;
};
struct perms {
    unsigned int num;
    struct perm *p;
};
struct node {
    struct perms perms;
    unsigned int generation;
};

extern int priv_domid;
#define XS_PERM_IGNORE (1U << 0)

int chk_domain_generation(int id, unsigned int generation);