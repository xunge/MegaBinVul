#include <stdint.h>
#include <assert.h>
#include <stddef.h>

typedef uint8_t OPJ_BYTE;
typedef uint32_t OPJ_UINT32;
typedef uint16_t OPJ_UINT16;
typedef int64_t OPJ_INT64;
typedef int32_t OPJ_INT32;
typedef int OPJ_BOOL;

#define OPJ_FALSE 0
#define OPJ_TRUE 1

#define EVT_ERROR 1
#define EVT_WARNING 2
#define PRId64 "lld"

#define OPJ_J2K_MCT_DEFAULT_NB_RECORDS 10
#define OPJ_J2K_MCC_DEFAULT_NB_RECORDS 10

enum {
    J2K_STATE_MH
};

struct opj_event_mgr;
struct opj_image_comp {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 prec;
    OPJ_UINT32 sgnd;
    OPJ_UINT32 resno_decoded;
    OPJ_UINT32 factor;
};

struct opj_image {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT16 numcomps;
    struct opj_image_comp* comps;
};

struct opj_tccp {
    OPJ_UINT32 m_dc_level_shift;
};

struct opj_mct_data {
    /* empty */
};

struct opj_simple_mcc_decorrelation_data {
    /* empty */
};

struct opj_tcp {
    struct opj_tccp* tccps;
    struct opj_mct_data* m_mct_records;
    struct opj_simple_mcc_decorrelation_data* m_mcc_records;
    OPJ_UINT32 m_nb_max_mct_records;
    OPJ_UINT32 m_nb_max_mcc_records;
};

struct opj_dec_param {
    OPJ_UINT32 m_reduce;
};

struct opj_dec_specific_param {
    struct opj_dec_param m_dec;
};

struct opj_decoder_param {
    OPJ_UINT32 m_start_tile_x;
    OPJ_UINT32 m_start_tile_y;
    OPJ_UINT32 m_end_tile_x;
    OPJ_UINT32 m_end_tile_y;
    OPJ_BOOL m_discard_tiles;
    struct opj_tcp* m_default_tcp;
    OPJ_UINT32 m_state;
};

struct opj_cp {
    OPJ_UINT16 rsiz;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    struct opj_tcp* tcps;
    struct opj_dec_specific_param m_specific_param;
    OPJ_UINT32 exp_comps;
    OPJ_BOOL correct;
    OPJ_UINT32 max_tiles;
};

struct opj_j2k {
    struct opj_image* m_private_image;
    struct opj_cp m_cp;
    struct {
        struct opj_decoder_param m_decoder;
    } m_specific_param;
};

typedef struct opj_event_mgr opj_event_mgr_t;
typedef struct opj_j2k opj_j2k_t;
typedef struct opj_image opj_image_t;
typedef struct opj_cp opj_cp_t;
typedef struct opj_image_comp opj_image_comp_t;
typedef struct opj_tcp opj_tcp_t;
typedef struct opj_tccp opj_tccp_t;
typedef struct opj_mct_data opj_mct_data_t;
typedef struct opj_simple_mcc_decorrelation_data opj_simple_mcc_decorrelation_data_t;

static void opj_event_msg(opj_event_mgr_t *p_manager, int level, const char *fmt, ...);
static void opj_read_bytes(OPJ_BYTE *src, void *dst, OPJ_UINT32 num_bytes);
static void* opj_calloc(size_t num, size_t size);
static OPJ_UINT32 opj_uint_adds(OPJ_UINT32 a, OPJ_UINT32 b);
static OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b);
static void opj_image_comp_header_update(opj_image_t *image, opj_cp_t *cp);