#include <stdlib.h>

typedef struct VTerm {
    int rows;
    int cols;
} VTerm;

typedef struct VTermState VTermState;

enum {
    MOUSE_X10
};

struct VTermState {
    VTerm *vt;
    int rows;
    int cols;
    int mouse_col;
    int mouse_row;
    int mouse_buttons;
    int mouse_protocol;
    void *callbacks;
    void *cbdata;
    int bold_is_highbright;
};

void *vterm_allocator_malloc(VTerm *vt, size_t size);
void vterm_state_newpen(VTermState *state);