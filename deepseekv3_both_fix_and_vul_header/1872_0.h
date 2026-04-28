#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>

#define XS_SET_PERMS 1
#define XS_PERM_WRITE 2
#define XS_PERM_OWNER 4
#define XS_PERM_IGNORE 8

struct connection;
struct xs_permissions {
    int id;
    int perms;
};

struct buffered_data {
    char *buffer;
    size_t used;
};

struct node_perms {
    int num;
    struct xs_permissions *p;
};

struct node {
    struct node_perms perms;
};

extern int quota_nb_perms_per_node;

static inline void *talloc_array(const void *ctx, size_t el_size, size_t num) {
    return calloc(num, el_size);
}

static inline bool strstarts(const char *str, const char *prefix) {
    return strncmp(str, prefix, strlen(prefix)) == 0;
}

static inline int xs_count_strings(const char *buffer, size_t len) {
    int count = 0;
    const char *p = buffer;
    while (p < buffer + len && *p) {
        count++;
        p += strlen(p) + 1;
    }
    return count;
}

static inline int domain_is_unprivileged(struct connection *conn) {
    return 0;
}

static inline bool xs_strings_to_perms(struct xs_permissions *perms, int num, const char *permstr) {
    return true;
}

static inline int set_perms_special(struct connection *conn, const char *name, struct node_perms *perms) {
    return 0;
}

static inline void send_ack(struct connection *conn, int type) {
}

static inline struct node *get_node_canonicalized(struct connection *conn, const void *ctx, const char *name, char **out_name, int perm) {
    return NULL;
}

static inline void domain_entry_dec(struct connection *conn, struct node *node) {
}

static inline int domain_entry_inc(struct connection *conn, struct node *node) {
    return 0;
}

static inline int write_node(struct connection *conn, struct node *node, bool no_quota) {
    return 0;
}

static inline void fire_watches(struct connection *conn, const void *ctx, const char *name, struct node *node, bool is_new, struct node_perms *old_perms) {
}

static inline int domain_alloc_permrefs(struct node_perms *perms) {
    return 0;
}

#define talloc_array(ctx, type, num) talloc_array(ctx, sizeof(type), num)