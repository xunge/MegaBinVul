#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdarg.h>

struct buffer {
    void *data;
    size_t size;
};

struct dm_config_value {
    int type;
    union {
        char *str;
        int64_t i;
        double d;
    } v;
};

struct dm_config_node {
    char *key;
    struct dm_config_value *v;
    struct dm_config_node *parent;
    struct dm_config_node *sib;
    struct dm_config_node *child;
};

struct dm_config_tree {
    struct dm_config_node *root;
};

struct vg_info {
    int flags;
};

typedef struct {
    struct buffer buffer;
    struct dm_config_tree *cft;
} response;

typedef struct {
    const char *type;
} request;

typedef struct {
    void *vgname_to_vgid;
    void *vgid_to_vgname;
    void *vgid_to_metadata;
    void *vgid_to_info;
    int flags;
} lvmetad_state;

#define DM_CFG_STRING 1
#define GLFL_INVALID 1
#define VGFL_INVALID 1

static void buffer_init(struct buffer *buf);
static void ERROR(lvmetad_state *s, const char *fmt, ...);
static void DEBUGLOG(lvmetad_state *s, const char *fmt, ...);
static const char *daemon_request_str(request r, const char *field, const char *def);
static char *dm_hash_lookup(void *table, const char *key);
static char *dm_hash_lookup_with_count(void *table, const char *key, int *count);
static char *dm_hash_lookup_with_val(void *table, const char *key, const char *val, size_t len);
static response reply_unknown(const char *msg);
static response reply_fail(const char *msg);
static response daemon_reply_simple(const char *status, const char *fmt, ...);
static struct dm_config_tree *dm_config_create(void);
static struct dm_config_node *dm_config_create_node(struct dm_config_tree *cft, const char *name);
static struct dm_config_value *dm_config_create_value(struct dm_config_tree *cft);
static struct dm_config_node *dm_config_clone_node(struct dm_config_tree *cft, struct dm_config_node *node, int recursive);
static int update_pv_status(lvmetad_state *s, struct dm_config_tree *cft, struct dm_config_node *n);
static void chain_outdated_pvs(lvmetad_state *s, const char *uuid, struct dm_config_tree *cft, struct dm_config_node *n);
static int add_last_node(struct dm_config_tree *cft, const char *name);