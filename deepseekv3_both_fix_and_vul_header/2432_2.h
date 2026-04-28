#include <stdint.h>
#include <string.h>

#define __user
#define __u32 uint32_t

struct fb_info;
struct atyfb_par;

struct atyfb_par {
    struct {
        int vxres;
        int vyres;
    } crtc;
    union aty_pll {
        struct {
            uint32_t pll_ref_div;
            uint32_t mclk_fb_div;
            uint32_t mclk_post_div_real;
            uint32_t mclk_fb_mult;
            uint32_t xclk_post_div_real;
            uint32_t vclk_fb_div;
            uint32_t vclk_post_div_real;
            uint32_t dsp_config;
            uint32_t dsp_on_off;
        } ct;
    } pll;
    uint32_t ref_clk_per;
    uint32_t features;
};

struct fb_info {
    struct atyfb_par *par;
    struct {
        unsigned int bits_per_pixel;
    } var;
    struct {
        unsigned int smem_len;
    } fix;
    struct {
        unsigned int len;
    } cmap;
};

struct atyclk {
    uint32_t ref_clk_per;
    uint32_t pll_ref_div;
    uint32_t mclk_fb_div;
    uint32_t mclk_post_div;
    uint32_t mclk_fb_mult;
    uint32_t xclk_post_div;
    uint32_t vclk_fb_div;
    uint32_t vclk_post_div;
    uint32_t dsp_xclks_per_row;
    uint32_t dsp_loop_latency;
    uint32_t dsp_precision;
    uint32_t dsp_off;
    uint32_t dsp_on;
};

#ifdef __sparc__
struct fbtype {
    int fb_type;
    int fb_width;
    int fb_height;
    int fb_depth;
    int fb_cmsize;
    int fb_size;
};
#define FBTYPE_PCI_GENERIC 0
#endif

#define M64_HAS(x) (0)
#define INTEGRATED 0
#define ATYIO_CLKR 0
#define ATYIO_CLKW 0
#define ATYIO_FEATR 0
#define ATYIO_FEATW 0
#define FBIOGTYPE 0
#define FBIO_WAITFORVSYNC 0
#define EINVAL 22
#define EFAULT 14

typedef unsigned int u_int;
typedef unsigned long u_long;
typedef uint32_t u32;

static inline int copy_to_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int copy_from_user(void *to, const void *from, size_t n) {
    memcpy(to, from, n);
    return 0;
}

static inline int get_user(uint32_t *val, const uint32_t *addr) {
    *val = *addr;
    return 0;
}

static inline int put_user(uint32_t val, uint32_t *addr) {
    *addr = val;
    return 0;
}

static int aty_waitforvblank(struct atyfb_par *par, uint32_t crtc) { return 0; }
static void aty_set_pll_ct(struct fb_info *info, union aty_pll *pll) {}