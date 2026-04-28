#include <stdint.h>

#define XS_PERM_IGNORE (1 << 0)

struct perm {
    uint32_t id;
    uint32_t perms;
};

struct perms {
    unsigned int num;
    struct perm *p;
};

struct node {
    struct perms perms;
    uint32_t generation;
};

struct connection;

extern uint32_t priv_domid;

int chk_domain_generation(uint32_t id, uint32_t generation);