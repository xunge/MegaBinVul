#include <stdlib.h>

struct object {
    struct oid {
        unsigned char hash[1];
    } oid;
};

struct strbuf;

struct bitmap;

int bitmap_position(unsigned char *hash);
char *path_name(struct strbuf *path, const char *last);
int ext_index_add_object(struct object *object, const char *name);
void bitmap_set(struct bitmap *base, int pos);