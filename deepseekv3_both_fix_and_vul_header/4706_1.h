#include <assert.h>
#include <stdint.h>
#include <stddef.h>

typedef uint8_t OPJ_BYTE;
typedef uint32_t OPJ_UINT32;
typedef int OPJ_BOOL;

#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define OPJ_J2K_MAXRLVLS 33
#define J2K_CCP_CSTY_PRT 0x01
#define EVT_ERROR 1

enum J2K_STATE {
    J2K_STATE_TPH
};

struct opj_event_mgr;
typedef struct opj_event_mgr opj_event_mgr_t;

struct opj_tccp {
    OPJ_UINT32 numresolutions;
    OPJ_UINT32 cblkw;
    OPJ_UINT32 cblkh;
    OPJ_UINT32 cblksty;
    OPJ_UINT32 qmfbid;
    OPJ_UINT32 csty;
    OPJ_UINT32 prcw[OPJ_J2K_MAXRLVLS];
    OPJ_UINT32 prch[OPJ_J2K_MAXRLVLS];
};
typedef struct opj_tccp opj_tccp_t;

struct opj_tcp {
    opj_tccp_t *tccps;
};
typedef struct opj_tcp opj_tcp_t;

struct opj_dec_param {
    OPJ_UINT32 m_reduce;
};

struct opj_decoder {
    OPJ_UINT32 m_state;
    opj_tcp_t *m_default_tcp;
};

struct opj_cp_specific_param_dec {
    struct opj_dec_param m_dec;
};

struct opj_cp {
    opj_tcp_t *tcps;
    struct opj_cp_specific_param_dec m_specific_param;
};
typedef struct opj_cp opj_cp_t;

struct opj_image {
    OPJ_UINT32 numcomps;
};

struct opj_j2k {
    opj_cp_t m_cp;
    OPJ_UINT32 m_current_tile_number;
    struct {
        struct opj_decoder m_decoder;
    } m_specific_param;
    struct opj_image *m_private_image;
    void *cstr_info;
};
typedef struct opj_j2k opj_j2k_t;

static void opj_event_msg(opj_event_mgr_t* mgr, int evt, const char* fmt, ...);
static void opj_read_bytes(OPJ_BYTE* src, void* dst, OPJ_UINT32 num_bytes);