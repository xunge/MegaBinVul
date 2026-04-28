#include <stddef.h>
#include <stdbool.h>
#include <linux/types.h>
#include <linux/errno.h>

struct radeon_device {
    void *dev;
};

struct radeon_bo;

struct r100_cs_track_cb {
    struct radeon_bo *robj;
    unsigned pitch;
    unsigned cpp;
    unsigned offset;
};

struct r100_cs_track_array {
    struct radeon_bo *robj;
    unsigned esize;
};

struct r100_cs_track_zb {
    struct radeon_bo *robj;
    unsigned pitch;
    unsigned cpp;
    unsigned offset;
};

struct r100_cs_track_aa {
    struct radeon_bo *robj;
    unsigned pitch;
    unsigned offset;
};

struct r100_cs_track {
    bool cb_dirty;
    bool zb_dirty;
    bool aa_dirty;
    bool tex_dirty;
    bool z_enabled;
    bool aaresolve;
    bool blend_read_enable;
    bool zb_cb_clear;
    unsigned num_cb;
    unsigned color_channel_mask;
    unsigned maxy;
    unsigned max_indx;
    unsigned num_arrays;
    unsigned vtx_size;
    unsigned immd_dwords;
    unsigned vap_vf_cntl;
    unsigned vap_alt_nverts;
    struct r100_cs_track_cb cb[8];
    struct r100_cs_track_array arrays[16];
    struct r100_cs_track_zb zb;
    struct r100_cs_track_aa aa;
};

static inline unsigned long radeon_bo_size(struct radeon_bo *bo) { return 0; }
void DRM_ERROR(const char *fmt, ...);
int dev_err(void *dev, const char *fmt, ...);