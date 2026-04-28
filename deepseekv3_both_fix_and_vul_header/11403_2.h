#include <stdbool.h>
#include <stdlib.h>

#define darray_foreach(ptr, arr) \
    for ((ptr) = (typeof(ptr))((arr)->data); \
         (ptr) < (typeof(ptr))((arr)->data + (arr)->size); \
         (ptr)++)

struct darray {
    void *data;
    size_t size;
};

struct xkb_keymap {
    unsigned int num_key_aliases;
    struct xkb_key_alias *key_aliases;
};

struct xkb_key_alias {
    unsigned int alias;
    unsigned int real;
};

typedef struct {
    unsigned int alias;
    unsigned int real;
} AliasInfo;

typedef struct {
    struct darray *aliases;
    void *ctx;
} KeyNamesInfo;

#define XKB_ATOM_NONE 0

static bool XkbKeyByName(struct xkb_keymap *keymap, unsigned int name, bool case_insensitive);
static const char *KeyNameText(void *ctx, unsigned int name);
static void log_vrb(void *ctx, int level, const char *fmt, ...);