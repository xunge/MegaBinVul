#include <stddef.h>

typedef unsigned char char_u;

#define BARTYPE_VERSION 1
#define BARTYPE_HISTORY 2
#define BARTYPE_REGISTER 3
#define BARTYPE_MARK 4

#define BVAL_NR 1
#define BVAL_STRING 2

#define FALSE 0
#define TRUE 1

typedef struct garray_T {
    void *ga_data;
    int ga_len;
} garray_T;

typedef struct bval_T {
    int bv_type;
    int bv_nr;
    char_u *bv_string;
    int bv_allocated;
    void *bv_tofree;
} bval_T;

typedef struct vir_T {
    char_u *vir_line;
    int vir_version;
    garray_T vir_barlines;
} vir_T;

static int barline_parse(vir_T *virp, char_u *p, garray_T *values);
static void handle_viminfo_history(garray_T *values, int writing);
static void handle_viminfo_register(garray_T *values, int force);
static void handle_viminfo_mark(garray_T *values, int force);
static int viminfo_readline(vir_T *virp);
static void ga_init2(garray_T *gap, size_t item_size, int size);
static void ga_add_string(garray_T *gap, char_u *str);
static void ga_clear(garray_T *gap);
static void vim_free(void *p);
static int getdigits(char_u **pp);