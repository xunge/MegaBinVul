#include <stddef.h>

struct plist_node {
    struct plist_node *next;
    struct plist_node *prev;
    struct plist_node *plist;
};

struct futex_q {
    struct plist_node list;
    void *pi_state;
    void *lock_ptr;
    void *key;
};

#define WARN_ON(cond) 
#define BUG_ON(cond) 

static void plist_del(struct plist_node *node, struct plist_node *plist);
static int plist_node_empty(struct plist_node *node);
static void free_pi_state(void *pi_state);
static void spin_unlock(void *lock);
static void drop_futex_key_refs(void *key);