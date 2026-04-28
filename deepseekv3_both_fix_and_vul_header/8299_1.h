#include <assert.h>
#include <stdint.h>

typedef int OPJ_BOOL;
typedef uint32_t OPJ_UINT32;
typedef uint8_t OPJ_BYTE;
typedef int32_t OPJ_INT32;

#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define OPJ_J2K_MAXBANDS 33
#define J2K_CCP_QNTSTY_SIQNT 0
#define J2K_CCP_QNTSTY_NOQNT 1
#define J2K_STATE_TPH 0
#define EVT_ERROR 0
#define EVT_WARNING 1

typedef struct {
    OPJ_INT32 expn;
    OPJ_INT32 mant;
} opj_stepsize_t;

typedef struct {
    OPJ_UINT32 qntsty;
    OPJ_UINT32 numgbits;
    opj_stepsize_t stepsizes[OPJ_J2K_MAXBANDS];
} opj_tccp_t;

typedef struct {
    opj_tccp_t* tccps;
} opj_tcp_t;

typedef struct {
    opj_tcp_t* tcps;
    OPJ_BOOL correct;
} opj_cp_t;

typedef struct {
    OPJ_UINT32 numcomps;
} opj_image_t;

typedef struct {
    OPJ_UINT32 m_current_tile_number;
    opj_cp_t m_cp;
    opj_image_t* m_private_image;
    struct {
        struct {
            OPJ_UINT32 m_state;
            opj_tcp_t* m_default_tcp;
        } m_decoder;
    } m_specific_param;
} opj_j2k_t;

typedef struct {
    void (*opj_event_msg)(void*, int, const char*, ...);
} opj_event_mgr_t;

void opj_read_bytes(OPJ_BYTE* p_src, OPJ_UINT32* p_dest, OPJ_UINT32 p_nb_bytes);