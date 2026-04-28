#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _mxml_node_s mxml_node_t;
typedef struct _mxml_attr_s mxml_attr_t;
typedef struct _mxml_global_s _mxml_global_t;

typedef int (*mxml_save_cb_t)(mxml_node_t *node, void *p, int where);
typedef int (*_mxml_putc_cb_t)(int ch, void *p);

enum {
    MXML_ELEMENT,
    MXML_INTEGER,
    MXML_OPAQUE,
    MXML_REAL,
    MXML_TEXT,
    MXML_CUSTOM
};

enum {
    MXML_WS_BEFORE_OPEN,
    MXML_WS_AFTER_OPEN,
    MXML_WS_BEFORE_CLOSE,
    MXML_WS_AFTER_CLOSE
};

struct _mxml_attr_s {
    char *name;
    char *value;
};

struct _mxml_node_s {
    int type;
    union {
        struct {
            char *name;
            int num_attrs;
            mxml_attr_t *attrs;
        } element;
        int integer;
        double real;
        char *opaque;
        struct {
            char *string;
            int whitespace;
        } text;
    } value;
    mxml_node_t *next;
    mxml_node_t *prev;
    mxml_node_t *parent;
    mxml_node_t *child;
};

struct _mxml_global_s {
    int wrap;
    char *(*custom_save_cb)(mxml_node_t *node);
};

static int mxml_write_ws(mxml_node_t *node, void *p, mxml_save_cb_t cb, int where, int col, _mxml_putc_cb_t putc_cb);
static int mxml_write_name(const char *name, void *p, _mxml_putc_cb_t putc_cb);
static int mxml_write_string(const char *s, void *p, _mxml_putc_cb_t putc_cb);