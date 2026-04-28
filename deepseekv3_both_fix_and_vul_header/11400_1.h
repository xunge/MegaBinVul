#include <stdbool.h>
#include <stddef.h>

enum merge_mode {
    MERGE_DEFAULT
};

enum xkb_file_type {
    FILE_TYPE_GEOMETRY,
    FIRST_KEYMAP_FILE_TYPE,
    LAST_KEYMAP_FILE_TYPE
};

struct xkb_context;
struct xkb_keymap {
    struct xkb_context *ctx;
};

struct xkb_common {
    struct xkb_common *next;
};

typedef struct XkbFile {
    enum xkb_file_type file_type;
    struct xkb_common common;
    char *name;
    void *defs;
} XkbFile;

bool UpdateDerivedKeymapFields(struct xkb_keymap *keymap);
void log_vrb(struct xkb_context *ctx, int level, const char *fmt, ...);
void log_err(struct xkb_context *ctx, const char *fmt, ...);
void log_dbg(struct xkb_context *ctx, const char *fmt, ...);
const char *xkb_file_type_to_string(enum xkb_file_type type);
extern bool (*compile_file_fns[])(XkbFile *file, struct xkb_keymap *keymap, enum merge_mode merge);