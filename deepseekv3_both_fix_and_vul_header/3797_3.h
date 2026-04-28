#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t byte;
typedef uint64_t gx_color_index;

typedef enum {
    BLEND_MODE_Compatible,
    BLEND_MODE_Normal
} gs_blend_mode_t;

typedef struct {
    int x;
    int y;
} gs_point;

typedef struct {
    gs_point p;
    gs_point q;
} gs_rect;

typedef struct pdf14_buf_s {
    int num_spots;
    byte alpha;
    byte shape;
    gs_blend_mode_t blend_mode;
    byte *data;
    gs_rect rect;
    int rowstride;
    int planestride;
    bool isolated;
    bool knockout;
    bool has_shape;
    bool has_tags;
    int n_planes;
    bool has_alpha_g;
    byte *backdrop;
    int n_chan;
    void *dirty;
    bool deep;
    byte *transfer_fn;
    bool is_ident;
} pdf14_buf;

typedef struct gx_device_s {
    uint32_t graphics_type_tag;
} gx_device;

typedef struct pdf14_device_s {
    // Device specific fields
} pdf14_device;

typedef struct gs_memory_s {
    // Memory management fields
} gs_memory_t;

typedef struct {
    // Blending procedures
} pdf14_nonseparable_blending_procs_t;

#define GS_DEVICE_ENCODES_TAGS (1 << 0)

typedef void (*art_pdf_compose_group_fn)(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *
);

extern void rect_merge(void *dirty1, void *dirty2);
extern void dump_raw_buffer(gs_memory_t *memory, int height, int width, int n_planes,
                          int planestride, int rowstride, const char *name,
                          byte *data, bool deep);
extern void if_debug7m(char c, gs_memory_t *mem, const char *fmt, ...);
extern void if_debug6m(char c, gs_memory_t *mem, const char *fmt, ...);

// Function pointer declarations with correct signatures
extern void compose_group_knockout(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_blend(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_nonblend_isolated_allmask_common(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_nonblend_isolated_mask_common(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_nonblend_isolated_nomask_common(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_nonblend_nonisolated_mask_common(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_nonblend_nonisolated_nomask_common(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);

extern void compose_group_nonknockout_noblend_general(
    byte *, bool, int, int, byte, byte, gs_blend_mode_t, bool, int, int,
    int, bool, byte *, bool, int, int, byte *, bool, int, int,
    byte *, bool, pdf14_buf *, byte, byte *, byte *, bool, int, bool,
    int, bool, gx_color_index, int, int, int, int,
    const pdf14_nonseparable_blending_procs_t *, pdf14_device *);