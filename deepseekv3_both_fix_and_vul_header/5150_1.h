#include <stdlib.h>

typedef struct {
    int row;
    int col;
} VTermPos;

typedef struct {
    int width;
} VTermScreenCell;

typedef struct {
    int rows;
    int cols;
    VTermScreenCell **buffers[2];
    VTermScreenCell *buffer;
    VTermScreenCell *sb_buffer;
    void *vt;
    struct {
        VTermPos pos;
    } *state;
    struct {
        int (*sb_popline)(int, VTermScreenCell*, void*);
        int (*resize)(int, int, void*);
    } *callbacks;
    void *cbdata;
} VTermScreen;

typedef struct {
    int start_row;
    int end_row;
    int start_col;
    int end_col;
} VTermRect;

static int vterm_screen_is_eol(VTermScreen *screen, VTermPos pos);
static void scrollrect(VTermRect rect, int rows, int cols, void *user);
static void vterm_screen_flush_damage(VTermScreen *screen);
static VTermScreenCell *realloc_buffer(VTermScreen *screen, VTermScreenCell *buffer, int new_rows, int new_cols);
static void vterm_allocator_free(void *vt, void *ptr);
static void *vterm_allocator_malloc(void *vt, size_t size);
static void damagerect(VTermScreen *screen, VTermRect rect);
static void vterm_screen_set_cell(VTermScreen *screen, VTermPos pos, VTermScreenCell *cell);