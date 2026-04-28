#include <stdbool.h>
#include <errno.h>

struct connection;

struct key {
    int dummy;
};

struct node {
    struct key key;
};

enum {
    NODE_ACCESS_WRITE
};

typedef struct {
    int dummy;
} TDB_DATA;

int access_node(struct connection *conn, struct node *node, int access, void *key);
int write_node_raw(struct connection *conn, void *key, struct node *node, bool no_quota_check);