#include <assert.h>
#include <stdint.h>
#include <stddef.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef int32_t OPJ_INT32;
typedef unsigned char OPJ_BYTE;
typedef int64_t OPJ_OFF_T;

#define OPJ_FALSE 0
#define OPJ_TRUE 1

#define J2K_MS_SOT 0xff90
#define J2K_MS_EOC 0xffd9
#define J2K_MS_SOD 0xff93
#define J2K_STATE_EOC 0x0004
#define J2K_STATE_TPHSOT 0x0100
#define J2K_STATE_NEOC 0x0008
#define J2K_STATE_TPH 0x0200

typedef struct opj_j2k_t {
    struct {
        struct {
            struct {
                OPJ_UINT32 m_state;
                OPJ_BOOL m_can_decode;
                OPJ_BOOL m_skip_data;
                OPJ_UINT32 m_sot_length;
                OPJ_UINT32 m_header_data_size;
                OPJ_BYTE* m_header_data;
                OPJ_UINT32 m_last_sot_read_pos;
                OPJ_BOOL m_nb_tile_parts_correction_checked;
                OPJ_BOOL m_nb_tile_parts_correction;
            } m_decoder;
        } m_specific_param;
        OPJ_UINT32 m_current_tile_number;
        struct {
            OPJ_UINT32 tw;
            OPJ_UINT32 th;
            struct opj_tcp_t* tcps;
        } m_cp;
        void* cstr_index;
        struct opj_tcd_t* m_tcd;
    };
} opj_j2k_t;

typedef struct opj_stream_private_t opj_stream_private_t;
typedef struct opj_event_mgr_t opj_event_mgr_t;

typedef struct opj_tcp_t {
    void* m_data;
    OPJ_UINT32 m_nb_tile_parts;
} opj_tcp_t;

typedef struct opj_tcd_t {
    struct {
        struct {
            OPJ_INT32 x0;
            OPJ_INT32 y0;
            OPJ_INT32 x1;
            OPJ_INT32 y1;
            OPJ_UINT32 numcomps;
        }* tiles;
    }* tcd_image;
} opj_tcd_t;

typedef struct opj_dec_memory_marker_handler_t {
    OPJ_UINT32 id;
    OPJ_UINT32 states;
    OPJ_BOOL (*handler)(opj_j2k_t*, OPJ_BYTE*, OPJ_UINT32, opj_event_mgr_t*);
} opj_dec_memory_marker_handler_t;

enum {
    EVT_ERROR,
    EVT_WARNING,
    EVT_INFO
};