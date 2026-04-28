#include <stdbool.h>
#include <stddef.h>

#define CHIP_R300 0
#define CHIP_RS200 0

struct radeon_device {
    unsigned int family;
};

struct r100_cs_track {
    bool cb_dirty;
    bool zb_dirty;
    bool tex_dirty;
    bool aa_dirty;
    unsigned num_cb;
    unsigned num_texture;
    unsigned maxy;
    unsigned separate_cube;
    bool aaresolve;
    struct {
        void *robj;
    } aa;
    struct {
        void *robj;
        unsigned pitch;
        unsigned cpp;
        unsigned offset;
    } cb[4];
    bool z_enabled;
    struct {
        void *robj;
        unsigned pitch;
        unsigned cpp;
        unsigned offset;
    } zb;
    unsigned vtx_size;
    unsigned immd_dwords;
    unsigned num_arrays;
    unsigned max_indx;
    struct {
        void *robj;
        unsigned esize;
    } arrays[11];
    struct {
        unsigned compress_format;
        unsigned pitch;
        unsigned width;
        unsigned height;
        unsigned width_11;
        unsigned height_11;
        unsigned num_levels;
        unsigned tex_coord_type;
        unsigned txdepth;
        unsigned cpp;
        void *robj;
        bool enabled;
        bool lookup_disable;
        bool roundup_w;
        bool roundup_h;
        struct {
            void *robj;
            unsigned width;
            unsigned height;
            unsigned offset;
        } cube_info[5];
    } textures[16];
};

#define R100_TRACK_COMP_NONE 0