#include <stdbool.h>
#include <stdint.h>
#include <limits>

typedef uint32_t OPJ_UINT32;

struct opj_image_comp {
    OPJ_UINT32 h;
};

struct opj_image_t {
    opj_image_comp* comps;
};

bool sycc420_422_size_is_valid(opj_image_t* img);