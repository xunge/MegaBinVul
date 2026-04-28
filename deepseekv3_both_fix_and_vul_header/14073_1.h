#include <stdint.h>
#include <assert.h>

typedef int OPJ_BOOL;
typedef uint8_t OPJ_BYTE;
typedef uint32_t OPJ_UINT32;

#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define OPJ_UNUSED(x) (void)(x)
#define J2K_MS_SOD 0xFF4F
#define USE_JPWL
#define EVT_ERROR 1

typedef struct opj_j2k_t opj_j2k_t;
typedef struct opj_tcd_t opj_tcd_t;
typedef struct opj_codestream_info_t opj_codestream_info_t;
typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

struct opj_j2k_t {
    struct {
        struct {
            uint32_t m_current_poc_tile_part_number;
            uint32_t m_current_tile_part_number;
        } m_encoder;
    } m_specific_param;
    uint32_t m_current_tile_number;
};

struct opj_tcd_t {
    uint32_t tp_num;
    uint32_t cur_tp_num;
    struct {
        struct {
            uint32_t packno;
        } *tiles;
    } *tcd_image;
};

struct opj_codestream_info_t {
    uint32_t packno;
};

void opj_write_bytes(OPJ_BYTE* p_data, uint32_t value, uint32_t length);
void opj_event_msg(opj_event_mgr_t* p_manager, int event_type, const char* message);
OPJ_BOOL opj_tcd_encode_tile(opj_tcd_t* p_tile_coder, uint32_t tile_number, OPJ_BYTE* p_data, OPJ_UINT32* p_data_written, OPJ_UINT32 remaining_data, opj_codestream_info_t* l_cstr_info, opj_event_mgr_t* p_manager);