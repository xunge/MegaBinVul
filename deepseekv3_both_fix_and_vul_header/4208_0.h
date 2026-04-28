#include <stddef.h>

struct object {
    struct oid {
        unsigned char hash[20];
    } oid;
};

struct strbuf;
struct sha1_array;

extern struct sha1_array recent_objects;

void sha1_array_append(struct sha1_array *, const unsigned char *);