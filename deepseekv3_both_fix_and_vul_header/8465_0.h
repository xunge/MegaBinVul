#include <assert.h>
#include <stdlib.h>

typedef unsigned char OPJ_BYTE;
typedef unsigned int OPJ_UINT32;
typedef int OPJ_BOOL;
#define OPJ_FALSE 0
#define OPJ_TRUE 1

#define J2K_MS_MCO 0xFFD7
#define EVT_ERROR 1

struct opj_stream_private;
struct opj_event_mgr;

typedef struct {
    OPJ_UINT32 m_nb_mcc_records;
    void* m_mcc_records;
} opj_tcp_t;

typedef struct {
    OPJ_UINT32 m_index;
} opj_simple_mcc_decorrelation_data_t;

typedef struct {
    struct {
        struct {
            OPJ_BYTE* m_header_tile_data;
            OPJ_UINT32 m_header_tile_data_size;
        } m_encoder;
    } m_specific_param;
    struct {
        opj_tcp_t* tcps;
    } m_cp;
    OPJ_UINT32 m_current_tile_number;
} opj_j2k_t;

void* opj_realloc(void* ptr, size_t size);
void opj_free(void* ptr);
void opj_event_msg(struct opj_event_mgr* p_manager, int event_type, const char* fmt, ...);
void opj_write_bytes(OPJ_BYTE* p_data, OPJ_UINT32 p_value, OPJ_UINT32 p_nb_bytes);
OPJ_UINT32 opj_stream_write_data(struct opj_stream_private* p_stream, OPJ_BYTE* p_data, OPJ_UINT32 p_size, struct opj_event_mgr* p_manager);