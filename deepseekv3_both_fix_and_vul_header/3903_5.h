#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdatomic.h>

#define DPU_STAGE_MAX 16
#define DPU_STAGE_0 0
#define SSPP_MAX 32
#define ENOMEM 12
#define E2BIG 7
#define EINVAL 22
#define GFP_KERNEL 0

struct drm_crtc {
    struct {
        int id;
    } base;
    char *name;
};

struct drm_display_mode {
    int hdisplay;
    int vdisplay;
};

struct drm_crtc_state {
    bool enable;
    bool active;
    bool active_changed;
    bool mode_changed;
    struct drm_display_mode adjusted_mode;
};

struct drm_plane {
    struct {
        int id;
    } base;
};

struct drm_plane_state {
    bool visible;
    int normalized_zpos;
    int crtc_x;
    struct drm_plane *plane;
};

struct drm_atomic_state;
struct drm_rect {
    int x1, y1, x2, y2;
};

struct drm_kms_helper {
    atomic_int bandwidth_ref;
};

struct dpu_crtc;
struct dpu_crtc_state {
    int num_mixers;
    struct {
        int new_perf;
    };
};

struct dpu_plane_state {
    bool needs_dirtyfb;
    int stage;
    struct {
        struct {
            struct drm_plane *plane;
        } base;
    };
};

struct plane_state {
    struct dpu_plane_state *dpu_pstate;
    const struct drm_plane_state *drm_pstate;
    int stage;
    int pipe_id;
};

struct dpu_multirect_plane_states {
    const struct drm_plane_state *r0;
    const struct drm_plane_state *r1;
};

#define DRM_DEBUG_ATOMIC(fmt, ...)
#define DPU_ERROR(fmt, ...)
#define DRM_RECT_FMT "%d,%d-%dx%d"
#define DRM_RECT_ARG(r) (r)->x1, (r)->y1, (r)->x2-(r)->x1, (r)->y2-(r)->y1
#define IS_ERR_OR_NULL(ptr) (!(ptr))
#define PTR_ERR(ptr) (-1)

static inline void atomic_inc(atomic_int *v) { (*v)++; }

static inline void swap_int(int32_t *a, int32_t *b) { 
    int32_t tmp = *a; 
    *a = *b; 
    *b = tmp; 
}

static inline void swap_rect(struct drm_rect *a, struct drm_rect *b) {
    struct drm_rect tmp = *a;
    *a = *b;
    *b = tmp;
}

static inline int drm_rect_width(const struct drm_rect *r) { return r->x2 - r->x1; }
static inline int drm_rect_height(const struct drm_rect *r) { return r->y2 - r->y1; }
static inline bool drm_rect_intersect(const struct drm_rect *a, const struct drm_rect *b) { return true; }

static inline struct drm_crtc_state *drm_atomic_get_new_crtc_state(struct drm_atomic_state *state, struct drm_crtc *crtc) { return NULL; }
static inline struct dpu_crtc *to_dpu_crtc(struct drm_crtc *crtc) { return NULL; }
static inline struct dpu_crtc_state *to_dpu_crtc_state(struct drm_crtc_state *state) { return NULL; }
static inline struct dpu_plane_state *to_dpu_plane_state(const struct drm_plane_state *state) { return NULL; }
static inline int dpu_plane_pipe(struct drm_plane *plane) { return 0; }
static inline bool dpu_crtc_needs_dirtyfb(struct drm_crtc_state *state) { return false; }
static inline void _dpu_crtc_setup_lm_bounds(struct drm_crtc *crtc, struct drm_crtc_state *state) {}
static inline void dpu_plane_clear_multirect(const struct drm_plane_state *state) {}
static inline bool dpu_plane_validate_multirect_v2(struct dpu_multirect_plane_states *plane) { return false; }
static inline struct drm_rect drm_plane_state_dest(const struct drm_plane_state *state) { struct drm_rect r = {0}; return r; }
static inline struct drm_kms_helper *_dpu_crtc_get_kms(struct drm_crtc *crtc) { return NULL; }
static inline int dpu_core_perf_crtc_check(struct drm_crtc *crtc, struct drm_crtc_state *state) { return 0; }
static inline void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static inline void kfree(void *ptr) { free(ptr); }

#define drm_atomic_crtc_state_for_each_plane_state(plane, pstate, crtc_state) \
    for (plane = NULL, pstate = NULL; 0;)