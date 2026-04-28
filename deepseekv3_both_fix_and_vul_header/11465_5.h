#include <stddef.h>
#include <stdbool.h>

typedef struct gs_composite_s gs_composite_t;
typedef struct gs_gstate_s gs_gstate;
typedef struct gs_memory_s gs_memory_t;
typedef struct pdf14_ctx_s pdf14_ctx;

struct gx_device_s;

struct gs_devn_params_s {
    int page_spot_colors;
    int num_std_colorant_names;
    void *pdf14_separations;
    void *separations;
};

struct cmm_profile_s {
    int data_cs;
    bool islab;
    struct gx_device_s *dev;
};

struct cmm_dev_profile_s {
    struct cmm_profile_s *blend_profile;
};

struct gsicc_rendering_param_s {
    int dummy;
};

struct gx_device_clist_reader_s {
    int trans_dev_icc_hash;
};

struct gs_pdf14trans_s {
    struct {
        int pdf14_op;
    } params;
};

struct gx_device_s {
    struct {
        void (*get_profile)(struct gx_device_s *, struct cmm_dev_profile_s **);
        struct gs_devn_params_s *(*ret_devn_params)(struct gx_device_s *);
        int (*open_device)(struct gx_device_s *);
    } procs;
};

struct pdf14_device_s {
    struct {
        struct cmm_profile_s *device_profile[1];
    } *icc_struct;
    struct gs_devn_params_s devn_params;
    struct {
        int num_components;
        int max_components;
    } color_info;
    bool using_blend_cs;
    bool free_devicen;
    pdf14_ctx *ctx;
    struct {
        int num_components;
    } saved_target_color_info;
    struct {
        void (*get_profile)(struct gx_device_s *, struct cmm_dev_profile_s **);
    } procs;
};

typedef struct gx_device_s gx_device;
typedef struct pdf14_device_s pdf14_device;
typedef struct gs_pdf14trans_s gs_pdf14trans_t;
typedef struct gs_devn_params_s gs_devn_params;
typedef struct gx_device_clist_reader_s gx_device_clist_reader;
typedef struct cmm_profile_s cmm_profile_t;
typedef struct gsicc_rendering_param_s gsicc_rendering_param_t;
typedef struct cmm_dev_profile_s cmm_dev_profile_t;

#define GS_UNKNOWN_TAG 0
#define gsCIELAB 0
#define PDF14_PUSH_DEVICE 0
#define PDF14_POP_DEVICE 1

#define dev_proc(dev, proc) ((dev)->procs.proc)

static void gsicc_adjust_profile_rc(cmm_profile_t *profile, int adjust, const char *msg);
static void devn_free_params(gx_device *dev);
static void pdf14_ctx_free(pdf14_ctx *ctx);
static cmm_profile_t *gsicc_read_serial_icc(gx_device *dev, int hash);
static void gsicc_extract_profile(int tag, cmm_dev_profile_t *dev_profile, 
                                cmm_profile_t **icc_profile, 
                                gsicc_rendering_param_t *render_cond);