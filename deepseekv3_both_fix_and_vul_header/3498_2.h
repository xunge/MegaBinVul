#include <stdlib.h>
#include <string.h>

struct cond_bool_datum {
    int state;
};

struct cond_node {
    struct cond_node *next;
};

struct hashtab {
    struct hashtab_node **table;
};

struct hashtab_node {
    char *key;
    void *datum;
    struct hashtab_node *next;
};

struct policydb {
    struct hashtab p_bools;
    struct cond_node *cond_list;
};

int security_get_bools(int *nbools, char ***bnames, int **bvalues, ...);
int evaluate_cond_node(struct policydb *p, struct cond_node *cur);
struct cond_bool_datum *hashtab_search(struct hashtab_node **table, const char *key);
void xfree(void *ptr);