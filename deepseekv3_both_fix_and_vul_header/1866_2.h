#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>

struct node {
    struct node *parent;
    void *data;
    unsigned int datalen;
};

struct connection;

extern struct node *construct_node(struct connection *conn, const void *ctx, const char *name);
extern void destroy_node(struct connection *conn, struct node *node);
extern int write_node(struct connection *conn, struct node *node, bool flag);
extern unsigned int domain_entry(struct connection *conn);
extern void domain_entry_inc(struct connection *conn, struct node *node);
extern void *talloc_free(void *ptr);
extern void talloc_set_destructor(void *ptr, void (*destructor)(void *));

extern unsigned int quota_nb_entry_per_domain;