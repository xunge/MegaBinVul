#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

typedef struct {
    OPJ_UINT32 tw;
    OPJ_UINT32 th;
    OPJ_UINT32 tdx;
    OPJ_UINT32 tdy;
    OPJ_UINT32 tx0;
    OPJ_UINT32 ty0;
} opj_cp_t;

typedef struct opj_image_comp_t {
    OPJ_UINT32 dx;
    OPJ_UINT32 dy;
    OPJ_UINT32 factor;
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 w;
    OPJ_UINT32 h;
    OPJ_INT32 resno_decoded;
    void* data;
} opj_image_comp_t;

typedef struct {
    OPJ_UINT32 x0;
    OPJ_UINT32 y0;
    OPJ_UINT32 x1;
    OPJ_UINT32 y1;
    OPJ_UINT32 numcomps;
    opj_image_comp_t* comps;
} opj_image_t;

typedef struct {
    opj_image_t* m_private_image;
    opj_image_t* m_output_image;
    opj_cp_t m_cp;
    struct {
        struct {
            OPJ_INT32 m_tile_ind_to_dec;
        } m_decoder;
    } m_specific_param;
    void* m_procedure_list;
} opj_j2k_t;

typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define EVT_ERROR 1

void opj_event_msg(opj_event_mgr_t* p_manager, int event_type, const char* fmt, ...);
void opj_image_destroy(opj_image_t* image);
opj_image_t* opj_image_create0();
void opj_copy_image_header(opj_image_t* src, opj_image_t* dst);
void opj_j2k_setup_decoding_tile(opj_j2k_t* p_j2k, opj_event_mgr_t* p_manager);
OPJ_BOOL opj_j2k_exec(opj_j2k_t* p_j2k, void* procedure_list, opj_stream_private_t* p_stream, opj_event_mgr_t* p_manager);
void* opj_free(void* ptr);

OPJ_INT32 opj_int_ceildiv(OPJ_INT32 a, OPJ_INT32 b);
OPJ_INT32 opj_int_ceildivpow2(OPJ_INT32 a, OPJ_INT32 b);