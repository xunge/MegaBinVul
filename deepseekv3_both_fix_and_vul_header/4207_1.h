#include <stdlib.h>

#define OBJECT_ADDED (1u << 0)

struct object {
    unsigned int flags;
    unsigned char type;
    struct {
        unsigned char hash[1];
    } oid;
};

struct strbuf;

char *path_name(struct strbuf *path, const char *last);
void add_preferred_base_object(const char *name);
void add_object_entry(const unsigned char *hash, unsigned char type, const char *name, int exclude);