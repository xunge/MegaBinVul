#include <stddef.h>

typedef unsigned char iw_byte;

enum iw_imgtype {
    IW_IMGTYPE_RGBA
};

struct iw_color {
    unsigned char r, g, b, a;
};

struct iw_colortable {
    unsigned int num_entries;
    struct iw_color *entry;
};

struct iw_image {
    enum iw_imgtype imgtype;
};

struct iwgifrcontext {
    struct iw_image *img;
    size_t pixels_set;
    size_t image_width;
    size_t image_height;
    size_t image_left;
    size_t image_top;
    size_t screen_width;
    size_t screen_height;
    iw_byte **row_pointers;
    int bytes_per_pixel;
    struct iw_colortable colortable;
};