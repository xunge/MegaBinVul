#include <stdbool.h>
#include <string.h>

typedef unsigned int xkb_mod_mask_t;
typedef unsigned int xkb_atom_t;
typedef unsigned int xkb_mod_index_t;

enum expr_value_type {
    EXPR_TYPE_INT
};

enum mod_type {
    MOD_REAL_MASK_ALL
};

struct xkb_context;
struct xkb_mod_set;

typedef struct {
    const struct xkb_mod_set *mods;
    enum mod_type mod_type;
} LookupModMaskPriv;

#define XKB_MOD_INVALID ((xkb_mod_index_t)-1)

static bool istreq(const char *str1, const char *str2) {
    return strcmp(str1, str2) == 0;
}