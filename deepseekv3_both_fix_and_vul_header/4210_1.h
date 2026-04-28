#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum object_type {
    OBJ_COMMIT,
    OBJ_TREE,
    OBJ_BLOB,
    OBJ_TAG
};

struct oid {
    unsigned char hash[20];
};

struct object {
    struct oid oid;
    enum object_type type;
    void *parsed;
};

struct rev_info {
    int verify_objects;
};

struct rev_list_info {
    struct rev_info *revs;
};

struct strbuf {
    char *buf;
    size_t len;
    size_t alloc;
};

int has_object_file(const struct oid *oid);
char *oid_to_hex(const struct oid *oid);
void die(const char *err, ...);
void parse_object(const unsigned char *sha1);