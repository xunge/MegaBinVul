#include <stdint.h>

typedef uint8_t OPJ_BYTE;
typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

#define OPJ_FALSE 0
#define OPJ_TRUE 1

struct opj_event_mgr;

typedef struct opj_stream_private_t {
    // 空结构体定义，仅用于声明指针
} opj_stream_private_t;

typedef struct opj_tcp_t {
    OPJ_UINT32 numpocs;
} opj_tcp_t;

typedef struct opj_tcd_t {
    OPJ_UINT32 cur_pino;
} opj_tcd_t;

typedef struct opj_cp_t {
    OPJ_UINT32 rsiz;
    opj_tcp_t* tcps;
} opj_cp_t;

typedef struct opj_j2k_t {
    struct {
        struct {
            OPJ_UINT32 m_current_tile_part_number;
            OPJ_UINT32 m_current_poc_tile_part_number;
        } m_encoder;
    } m_specific_param;
    OPJ_UINT32 m_current_tile_number;
    opj_tcd_t* m_tcd;
    opj_cp_t m_cp;
} opj_j2k_t;

#define OPJ_IS_CINEMA(rsiz) ((rsiz) == 0)