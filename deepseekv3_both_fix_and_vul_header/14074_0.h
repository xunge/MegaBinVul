#include <assert.h>
#include <stddef.h>

typedef unsigned char OPJ_BYTE;
typedef unsigned int OPJ_UINT32;
typedef int OPJ_BOOL;

#define OPJ_TRUE 1
#define OPJ_FALSE 0
#define OPJ_UNUSED(x) (void)(x)

#define J2K_MS_SOT 0xFF90
#define EVT_ERROR 1

typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

typedef struct opj_j2k_t {
    OPJ_UINT32 m_current_tile_number;
    struct {
        struct {
            OPJ_UINT32 m_current_tile_part_number;
        } m_encoder;
    } m_specific_param;
    struct {
        struct {
            OPJ_UINT32 m_nb_tile_parts;
        } *tcps;
    } m_cp;
} opj_j2k_t;

void opj_write_bytes(OPJ_BYTE *p_data, OPJ_UINT32 p_value, OPJ_UINT32 p_nb_bytes);
void opj_event_msg(opj_event_mgr_t *p_manager, int p_event_type, const char *p_message);