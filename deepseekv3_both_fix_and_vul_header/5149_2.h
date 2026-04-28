#include <stdlib.h>

typedef struct VTerm VTerm;
typedef struct VTermScreen VTermScreen;

typedef struct {
    unsigned long fg;
    unsigned long bg;
    unsigned int bold:1;
    unsigned int underline:1;
    unsigned int italic:1;
    unsigned int blink:1;
    unsigned int reverse:1;
    unsigned int strike:1;
    unsigned int font:4;
} VTermPen;

typedef struct {
    unsigned int chars[1];
    VTermPen pen;
} ScreenCell;

struct VTermScreen {
    VTerm *vt;
    int rows;
    int cols;
    VTermPen pen;
};

void *vterm_allocator_malloc(VTerm *vt, size_t size);
void vterm_allocator_free(VTerm *vt, void *ptr);