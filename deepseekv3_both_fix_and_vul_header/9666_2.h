#include <stdio.h>

typedef struct ADisplay {
    void *bitmap;
    int fore_color;
} *ADisplay;

typedef struct FontFace {
    int index;
    char *filepath;
} *FontFace;

typedef struct RenderState {
    struct {
        void *disp;
    } display;
    char *message;
    char message0[256];
    FontFace *faces;
    int face_index;
    int num_faces;
    char *filename;
    float char_size;
} *RenderState;

#define DIM_Y 100

void grWriteCellString(void *bitmap, int x, int y, char *str, int color);