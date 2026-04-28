#include <stdio.h>
#include <stdlib.h>

struct oid {
    char *hex;
};

struct object {
    struct oid oid;
};

struct strbuf {
    char *buf;
    size_t len;
    size_t alloc;
};

char *path_name(struct strbuf *path, const char *component);
char *oid_to_hex(const struct oid *oid);