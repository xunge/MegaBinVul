#include <stdint.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define ENOMEM 12
#define BIT(n) (1U << (n))

typedef uint32_t u32;

struct drm_encoder {
    unsigned int possible_crtcs;
};

struct drm_connector {
    /* dummy */
};

struct drm_writeback_connector {
    struct {
        struct drm_encoder encoder;
    };
    struct drm_connector base;
};

struct komeda_layer {
    u32 layer_type;
};

struct komeda_dev {
    void* fmt_tbl;
};

struct komeda_kms_dev {
    struct {
        void* dev_private;
    } base;
};

struct komeda_crtc {
    struct {
        int index;
    } base;
    struct {
        struct komeda_layer *wb_layer;
    } *master;
    struct komeda_wb_connector *wb_conn;
};

struct komeda_wb_connector {
    struct drm_writeback_connector base;
    struct komeda_layer *wb_layer;
};

extern const struct drm_connector_funcs komeda_wb_connector_funcs;
extern const struct drm_connector_helper_funcs komeda_wb_conn_helper_funcs;
extern const struct drm_encoder_helper_funcs komeda_wb_encoder_helper_funcs;

u32* komeda_get_layer_fourcc_list(struct komeda_dev *mdev, u32 layer_type, u32 *n_formats);
void komeda_put_fourcc_list(u32 *formats);
void* kzalloc(size_t size, int flags);
int drm_writeback_connector_init(void *kms, struct drm_writeback_connector *wb_conn,
                               const struct drm_connector_funcs *funcs,
                               const struct drm_encoder_helper_funcs *helper_funcs,
                               u32 *formats, u32 n_formats);
void drm_connector_helper_add(struct drm_connector *connector,
                            const struct drm_connector_helper_funcs *funcs);

static inline int drm_crtc_index(void *crtc) {
    return ((struct komeda_crtc*)crtc)->base.index;
}