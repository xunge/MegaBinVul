#include <stddef.h>

typedef unsigned long long_u;

typedef struct VTerm VTerm;
typedef struct VTermState VTermState;
typedef struct {
    unsigned red;
    unsigned green;
    unsigned blue;
} VTermColor;

VTermState *vterm_obtain_state(VTerm *vterm);
void vterm_state_set_palette_color(VTermState *state, int index, const VTermColor *color);