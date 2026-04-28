#include <string.h>

typedef struct {
    void *dptr;
    unsigned int dsize;
} TDB_DATA;

struct connection {
    void *transaction;
};

struct node {
    char *name;
    TDB_DATA key;
};

extern void *tdb_ctx;

int streq(const char *a, const char *b);
void corrupt(void *unused, const char *msg);
void domain_entry_dec(struct connection *conn, struct node *node);
void fail_transaction(void *transaction);
void set_tdb_key(const char *name, TDB_DATA *key);
int tdb_delete(void *tdb_ctx, TDB_DATA key);