#include <string.h>
#include <stddef.h>

struct node {
    char *name;
};

typedef struct {
    void *dptr;
    size_t dsize;
} TDB_DATA;

typedef struct TDB_CONTEXT TDB_CONTEXT;

extern TDB_CONTEXT *tdb_ctx;
extern int streq(const char *s1, const char *s2);
extern void corrupt(void *ctx, const char *msg);
extern void set_tdb_key(const char *name, TDB_DATA *key);
extern void domain_entry_dec(void *ctx, struct node *node);
extern int tdb_delete(TDB_CONTEXT *tdb, TDB_DATA key);
extern void *talloc_parent(const void *ptr);