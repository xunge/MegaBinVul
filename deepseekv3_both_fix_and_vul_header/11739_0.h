#include <string.h>
#include <stdlib.h>

typedef struct ref_s {
    union {
        int intval;
    } value;
    int type;
} ref;

typedef struct os_ptr_s {
    ref *p;
} os_ptr;

typedef struct i_ctx_s i_ctx_t;
typedef struct stream_s stream;
typedef struct gx_device_s gx_device;
typedef struct cmm_dev_profile_s {
    struct cmm_profile_s *oi_profile;
    struct cmm_profile_s *device_profile[1];
    struct cmm_profile_s *proof_profile;
} cmm_dev_profile_t;
typedef struct cmm_profile_s {
    int num_comps;
    void *profile_handle;
    void *buffer;
    unsigned int buffer_size;
    void *memory;
    int data_cs;
    char *name;
    size_t name_length;
} cmm_profile_t;
typedef struct gsicc_manager_s {
    struct cmm_profile_s *default_rgb;
    struct cmm_profile_s *default_gray;
    struct cmm_profile_s *default_cmyk;
} gsicc_manager_t;
typedef struct gs_memory_s gs_memory_t;
typedef struct gs_gstate_s {
    gsicc_manager_t *icc_manager;
} gs_gstate_t;

typedef enum {
    gs_color_space_index_DevicePixel
} gs_color_space_index;

typedef enum {
    gsCIEXYZ,
    gsCIELAB,
    gsRGB,
    gsGRAY,
    gsCMYK,
    gsNCHANNEL,
    gsNAMED,
    gsUNDEFINED
} gs_color_space_data;

enum {
    t_dictionary,
    t_integer,
    gs_debug_flag_icc,
    gs_error_undefined,
    gs_error_VMerror,
    gs_error_rangecheck,
    gs_error_typecheck
};

#define osp ((os_ptr){0})
#define igs ((gs_gstate_t *)0)
#define imemory ((gs_memory_t *)0)
#define MAX_DEFAULT_ICC_LENGTH 256
#define OI_PROFILE "OutputIntent"
#define get_profile "get_profile"

#define check_type(a, b)
#define check_dict_read(a)
#define if_debug0m(a, b, c)
#define check_read_file(a, b, c)
#define return_error(a) (a)
#define gs_throw(a, b) (a)
#define rc_decrement(a, b)
#define rc_assign(a, b, c)
#define rc_increment(a)
#define pop(a)
#define r_type(a) ((a)->type)
#define gs_note_error(a) (a)

extern gx_device *gs_currentdevice(gs_gstate_t *);
extern int (*dev_proc(gx_device *, const char *))(gx_device *, cmm_dev_profile_t **);
extern int gsicc_init_device_profile_struct(gx_device *, void *, int);
extern int dict_find_string(os_ptr, const char *, ref **);
extern cmm_profile_t *gsicc_profile_new(stream *, gs_memory_t *, void *, int);
extern void *gsicc_get_profile_handle_buffer(void *, unsigned int, gs_memory_t *);
extern int gscms_get_profile_data_space(void *, gs_memory_t *);
extern void gsicc_init_hash_cs(cmm_profile_t *, gs_gstate_t *);
extern void gsicc_set_icc_range(cmm_profile_t **);
extern gs_color_space_index gsicc_get_default_type(cmm_profile_t *);
extern gs_memory_t *gs_gstate_memory(gs_gstate_t *);
extern void *gs_alloc_bytes(gs_memory_t *, unsigned int, const char *);