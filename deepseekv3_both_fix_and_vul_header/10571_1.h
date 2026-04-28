#include <stdint.h>
#include <stddef.h>

typedef uint32_t iw_uint32;

struct iwjpegrcontext {
    int exif_orientation;
    int exif_density_unit;
    double exif_density_x;
    double exif_density_y;
};

struct iw_exif_state {
    unsigned char *d;
    size_t d_len;
    int endian;
};

static unsigned int iw_get_ui16_e(const unsigned char *d, int endian) {
    return 0;
}

static int get_exif_tag_int_value(struct iw_exif_state *e, unsigned int tag_pos, unsigned int *v) {
    return 0;
}

static int get_exif_tag_dbl_value(struct iw_exif_state *e, unsigned int tag_pos, double *v_dbl) {
    return 0;
}