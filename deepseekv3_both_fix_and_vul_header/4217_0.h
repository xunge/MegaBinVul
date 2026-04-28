#include <stddef.h>

struct object {
    struct oid {
        unsigned char hash[1];
    } oid;
};

struct strbuf;
struct bitmap;

void bitmap_set(struct bitmap *base, int pos);
int find_object_pos(const unsigned char *hash);
void mark_as_seen(struct object *object);