#include <stdint.h>
#include <assert.h>

#define OPJ_BOOL int
#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define OPJ_BYTE uint8_t
#define OPJ_UINT32 uint32_t
#define OPJ_UNUSED(x) (void)(x)
#define J2K_MS_SOT 0xFF90
#define EVT_ERROR 1

typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

typedef struct opj_j2k_t {
    uint16_t m_current_tile_number;
    struct {
        struct {
            uint8_t m_current_tile_part_number;
        } m_encoder;
    } m_specific_param;
    struct {
        struct {
            uint8_t m_nb_tile_parts;
        } *tcps;
    } m_cp;
} opj_j2k_t;

static void opj_event_msg(opj_event_mgr_t* manager, int event, const char* msg);
static void opj_write_bytes(OPJ_BYTE* p_data, uint32_t value, int n);