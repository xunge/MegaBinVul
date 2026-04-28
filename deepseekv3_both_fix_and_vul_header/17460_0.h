#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char uchar;

typedef enum {
    MARKUP_NONE,
    MARKUP_COMMENT,
    MARKUP_UNKNOWN,
    MARKUP_AREA,
    MARKUP_BODY,
    MARKUP_DOCTYPE,
    MARKUP_ERROR,
    MARKUP_FILE,
    MARKUP_HEAD,
    MARKUP_HTML,
    MARKUP_MAP,
    MARKUP_META,
    MARKUP_TITLE,
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
    MARKUP_H7,
    MARKUP_H8,
    MARKUP_H9,
    MARKUP_H10,
    MARKUP_H11,
    MARKUP_H12,
    MARKUP_H13,
    MARKUP_H14,
    MARKUP_H15,
    MARKUP_HR,
    MARKUP_LI,
    MARKUP_OL,
    MARKUP_P,
    MARKUP_PRE,
    MARKUP_TABLE,
    MARKUP_TR,
    MARKUP_UL,
    MARKUP_IMG,
    MARKUP_EMBED
} markup_t;

typedef struct {
    uchar *name;
    uchar *value;
} var_t;

typedef struct tree_t {
    markup_t markup;
    uchar *data;
    int preformatted;
    int nvars;
    var_t *vars;
    struct tree_t *child;
    struct tree_t *next;
} tree_t;

extern uchar *iso8859(uchar c);
extern uchar *htmlGetVariable(tree_t *t, uchar *name);
extern void htmlSetVariable(tree_t *t, uchar *name, uchar *value);
extern char *file_method(char *filename);
extern void image_copy(char *src, char *dst, char *output_path);
extern char *file_basename(char *filename);
extern char *OutputPath;
extern char *_htmlMarkups[];