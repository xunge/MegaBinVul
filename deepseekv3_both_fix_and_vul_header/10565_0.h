#include <stdint.h>

#define IW_DENSITY_UNKNOWN 0

struct iw_image {
    int density_code;
    double density_x;
    double density_y;
};

struct iw_context {
    struct iw_image img1;
};

#define IW_IMPL(return_type) return_type