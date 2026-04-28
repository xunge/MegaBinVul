#include <stdint.h>

typedef struct opj_cparameters_t {
    int tile_size_on;
    int cp_tdx;
    int cp_tdy;
    char tp_flag;
    int tp_on;
    int cp_tx0;
    int cp_ty0;
    int image_offset_x0;
    int image_offset_y0;
    int cblockw_init;
    int cblockh_init;
    int mode;
    int roi_compno;
    int subsampling_dx;
    int subsampling_dy;
    int irreversible;
    int tcp_numlayers;
    float *tcp_rates;
    int rsiz;
    int numresolution;
    int csty;
    int res_spec;
    int *prcw_init;
    int *prch_init;
    int prog_order;
    uint32_t numpocs;
    void *POC;
    int cp_disto_alloc;
    int max_cs_size;
    int max_comp_size;
} opj_cparameters_t;

typedef struct opj_image_comp {
    int w;
    int h;
    int prec;
    int dx;
    int dy;
} opj_image_comp;

typedef struct opj_image_t {
    int numcomps;
    opj_image_comp *comps;
} opj_image_t;

typedef struct opj_event_mgr_t {
    void (*opj_event_msg)(void*, int, const char*, ...);
} opj_event_mgr_t;

#define OPJ_FALSE 0
#define OPJ_TRUE 1
#define OPJ_PROFILE_CINEMA_2K 1
#define OPJ_PROFILE_CINEMA_4K 2
#define OPJ_CPRL 0
#define OPJ_CINEMA_24_CS 1302083
#define OPJ_CINEMA_24_COMP 1041666
#define EVT_WARNING 1

typedef uint32_t OPJ_UINT32;
typedef float OPJ_FLOAT32;

int opj_j2k_initialise_4K_poc(void *POC, int numresolution);