#include <stdio.h>
#include <string.h>

typedef unsigned char uchar;

typedef struct tree_t tree_t;
typedef struct var_t var_t;

struct var_t {
    char *name;
    uchar *value;
};

struct tree_t {
    int markup;
    int preformatted;
    uchar *data;
    int nvars;
    var_t *vars;
    tree_t *child;
    tree_t *next;
};

enum {
    MARKUP_NONE,
    MARKUP_COMMENT,
    MARKUP_AREA,
    MARKUP_BR,
    MARKUP_CENTER,
    MARKUP_DD,
    MARKUP_DL,
    MARKUP_DT,
    MARKUP_H1,
    MARKUP_H2,
    MARKUP_H3,
    MARKUP_H4,
    MARKUP_H5,
    MARKUP_H6,
    MARKUP_HEAD,
    MARKUP_HR,
    MARKUP_LI,
    MARKUP_MAP,
    MARKUP_OL,
    MARKUP_P,
    MARKUP_PRE,
    MARKUP_TABLE,
    MARKUP_TITLE,
    MARKUP_TR,
    MARKUP_UL,
    MARKUP_DIR,
    MARKUP_MENU
};

extern const char * const _htmlMarkups[];
extern char *iso8859(uchar ch);