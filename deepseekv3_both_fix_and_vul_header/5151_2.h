#include <stdlib.h>

typedef struct VTerm VTerm;
typedef struct VTermState VTermState;
typedef struct VTermScreen VTermScreen;

typedef enum {
  VTERM_DAMAGE_CELL
} VTermDamageSize;

typedef struct VTermScreenCell {
    unsigned int chars[6];
    unsigned int width;
    unsigned int attrs;
    unsigned int fg;
    unsigned int bg;
} VTermScreenCell;

struct VTermScreen {
  VTerm *vt;
  VTermState *state;
  VTermDamageSize damage_merge;
  struct {
    int start_row;
  } damaged;
  struct {
    int start_row;
  } pending_scrollrect;
  int rows;
  int cols;
  void *callbacks;
  void *cbdata;
  VTermScreenCell *buffers[1];
  VTermScreenCell *buffer;
  VTermScreenCell *sb_buffer;
};

extern VTermState *vterm_obtain_state(VTerm *vt);
extern void vterm_get_size(VTerm *vt, int *rows, int *cols);
extern void *vterm_allocator_malloc(VTerm *vt, size_t size);
extern VTermScreenCell *realloc_buffer(VTermScreen *screen, VTermScreenCell *buffer, int rows, int cols);
extern void vterm_state_set_callbacks(VTermState *state, const void *cbs, VTermScreen *screen);

static const void *state_cbs;