#include <stddef.h>

typedef int SIXELSTATUS;
typedef struct sixel_frame sixel_frame_t;

#define SIXELAPI
#define SIXEL_FALSE 0
#define SIXEL_BAD_INPUT (-1)
#define SIXEL_OK 0
#define SIXEL_WIDTH_LIMIT (1 << 16)
#define SIXEL_HEIGHT_LIMIT (1 << 16)

struct sixel_frame {
    unsigned char *pixels;
    int width;
    int height;
    int pixelformat;
    unsigned char *palette;
    int ncolors;
};

void sixel_frame_ref(sixel_frame_t *frame);
void sixel_frame_unref(sixel_frame_t *frame);
void sixel_helper_set_additional_message(const char *message);