#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
#define OPJ_FALSE 0
#define OPJ_TRUE 1

typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;

typedef struct opj_image_comp {
    int resno_decoded;
    OPJ_INT32* data;
    int w;
    int h;
} opj_image_comp;

typedef struct opj_image_t {
    int numcomps;
    opj_image_comp* comps;
} opj_image_t;

typedef struct opj_j2k_t {
    opj_image_t* m_output_image;
    opj_image_t* m_private_image;
    void* m_procedure_list;
} opj_j2k_t;

typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

opj_image_t* opj_image_create0();
void opj_copy_image_header(opj_image_t* src, opj_image_t* dst);
void opj_j2k_setup_decoding(opj_j2k_t* j2k, opj_event_mgr_t* manager);
OPJ_BOOL opj_j2k_exec(opj_j2k_t* j2k, void* procedure_list, opj_stream_private_t* stream, opj_event_mgr_t* manager);
void opj_image_destroy(opj_image_t* image);