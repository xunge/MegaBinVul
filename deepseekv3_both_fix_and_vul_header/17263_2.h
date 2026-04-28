#include <stddef.h>
#include <assert.h>
#include <stdarg.h>

#define EMPTY (-1)

typedef struct fz_context fz_context;

typedef struct cmap_splay {
    unsigned int low;
    unsigned int high;
    unsigned int out;
    int parent;
    int left;
    int right;
    int many;
} cmap_splay;

typedef struct pdf_cmap {
    char *cmap_name;
    cmap_splay *tree;
    int tlen;
    int tcap;
    int ttop;
} pdf_cmap;

static void fz_warn(fz_context *ctx, const char *fmt, ...);
static void *fz_resize_array(fz_context *ctx, void *p, size_t count, size_t size);
static int delete_node(pdf_cmap *cmap, int current);
static void move_to_root(cmap_splay *tree, int new);