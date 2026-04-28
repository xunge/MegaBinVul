#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned int uint;

typedef struct i_ctx_s i_ctx_t;
typedef struct ref_s {
    struct {
        uint8_t *bytes;
    } value;
    size_t size;
} ref;
typedef struct stream_s stream;
typedef struct gs_color_space_s gs_color_space;
typedef struct cmm_profile_s cmm_profile_t;
typedef struct gs_memory_s gs_memory_t;
typedef struct gs_gstate_s gs_gstate_t;

extern gs_gstate_t *igs;

#define GSICC_STANDARD_PROFILES "sRGB", "AdobeRGB", "CMYK"
#define GSICC_STANDARD_PROFILES_KEYS "srgb", "adobe", "cmyk"
#define GSICC_NUMBER_STANDARD_PROFILES 3

enum {
    t_string,
    gsCIEXYZ,
    gsCIELAB,
    gsRGB,
    gsGRAY,
    gsCMYK,
    gsNCHANNEL,
    gsNAMED,
    gsUNDEFINED
};

enum {
    gs_error_undefined,
    gs_error_rangecheck,
    gs_error_VMerror
};

struct range_s {
    float rmin;
    float rmax;
};

struct cmm_profile_s {
    void *profile_handle;
    unsigned char *buffer;
    unsigned int buffer_size;
    int num_comps;
    int data_cs;
    gs_memory_t *memory;
    struct {
        struct range_s ranges[4];
    } Range;
    bool islab;
};

struct gs_color_space_s {
    cmm_profile_t *cmm_icc_profile_data;
};

struct gs_gstate_s {
    struct {
        cmm_profile_t *default_rgb;
        cmm_profile_t *default_gray;
        cmm_profile_t *default_cmyk;
    } *icc_manager;
    gs_memory_t *memory;
};

static inline gs_memory_t *gs_gstate_memory(gs_gstate_t *pgs) {
    return pgs->memory;
}

int dict_find_string(ref *dict, const char *key, ref **value);
int check_read_file(i_ctx_t *i_ctx_p, stream *s, ref *pstrmval);
int gs_cspace_build_ICC(gs_color_space **ppcs, void *pprofile, gs_memory_t *mem);
int gs_setcolorspace(gs_gstate_t *pgs, gs_color_space *pcs);
int gs_rethrow(int code, const char *msg);
int return_error(int errcode);
int gs_throw(int errcode, const char *msg);
void *gs_alloc_bytes(gs_memory_t *mem, size_t size, const char *cname);
void gs_free_object(gs_memory_t *mem, void *ptr, const char *cname);
cmm_profile_t *gsicc_get_profile_handle_file(const char *name, size_t len, gs_memory_t *mem);
cmm_profile_t *gsicc_profile_new(stream *s, gs_memory_t *mem, void *profile, int intents);
void *gsicc_get_profile_handle_buffer(unsigned char *buffer, unsigned int size, gs_memory_t *mem);
int gsicc_set_gscs_profile(gs_color_space *pcs, cmm_profile_t *profile, gs_memory_t *mem);
int gscms_get_profile_data_space(void *profile, gs_memory_t *mem);
void gsicc_init_hash_cs(cmm_profile_t *profile, gs_gstate_t *pgs);
bool gs_currentoverrideicc(gs_gstate_t *pgs);
void rc_decrement(void *ptr, const char *cname);
void rc_decrement_only(void *ptr, const char *cname);
void rc_adjust(void *ptr, int delta, const char *cname);
void rc_increment(void *ptr);
void pop(int n);
static inline size_t r_size(ref *r) { return r->size; }
bool r_has_type(ref *r, int type);