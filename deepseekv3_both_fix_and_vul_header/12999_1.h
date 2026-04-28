#include <stdlib.h>
#include <stdbool.h>

struct expr_parse_ctx {
    void *ids;
    int runtime;
};

unsigned int key_hash(const void *key, void *ctx);
bool key_equal(const void *key1, const void *key2, void *ctx);
void *hashmap__new(unsigned int (*hash_fn)(const void *key, void *ctx),
                   bool (*equal_fn)(const void *key1, const void *key2, void *ctx),
                   void *ctx);