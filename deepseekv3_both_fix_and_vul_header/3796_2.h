#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef enum {
    BLEND_MODE_Compatible,
    BLEND_MODE_Normal
} gs_blend_mode_t;

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point p;
    point q;
} rect;

typedef struct pdf14_buf_s {
    int num_spots;
    uint16_t alpha;
    uint16_t shape;
    gs_blend_mode_t blend_mode;
    unsigned char *data;
    rect rect;
    int rowstride;
    int planestride;
    bool isolated;
    bool has_shape;
    bool has_tags;
    int n_planes;
    bool has_alpha_g;
    unsigned char *backdrop;
    int n_chan;
    bool knockout;
    bool deep;
    void *dirty;
    const uint16_t *transfer_fn;
} pdf14_buf;

typedef struct pdf14_device_s {
    // Placeholder for device structure
} pdf14_device;

typedef struct gx_device_s {
    unsigned int graphics_type_tag;
} gx_device;

typedef struct gs_memory_s {
    // Placeholder for memory structure
} gs_memory_t;

typedef unsigned long gx_color_index;

typedef struct {
    const uint16_t *transfer_fn;
} pdf14_nonseparable_blending_procs_t;

typedef void (*art_pdf_compose_group16_fn)();

#define GS_DEVICE_ENCODES_TAGS 0

// Function pointer declarations
void compose_group16_knockout();
void compose_group16_nonknockout_blend();
void compose_group16_nonknockout_nonblend_isolated_allmask_common();
void compose_group16_nonknockout_nonblend_isolated_mask_common();
void compose_group16_nonknockout_nonblend_isolated_nomask_common();
void compose_group16_nonknockout_nonblend_nonisolated_mask_common();
void compose_group16_nonknockout_nonblend_nonisolated_nomask_common();
void compose_group16_nonknockout_noblend_general();

// External function declarations
void rect_merge(void *dirty1, void *dirty2);
void if_debug7m(char c, gs_memory_t *memory, const char *fmt, ...);
void if_debug6m(char c, gs_memory_t *memory, const char *fmt, ...);
uint16_t interp16(const uint16_t *tr_fn, uint16_t value);