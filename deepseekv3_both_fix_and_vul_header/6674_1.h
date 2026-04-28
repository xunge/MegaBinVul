#include <stdint.h>
#include <stddef.h>

typedef int32_t WORD32;
typedef uint32_t UWORD32;

#define IV_FAIL 1
#define IVD_MEM_ALLOC_FAILED 2
#define IVD_FATALERROR 3

typedef struct iv_obj_t iv_obj_t;
typedef struct codec_t codec_t;
typedef struct ihevcd_cxa_create_ip_t ihevcd_cxa_create_ip_t;
typedef struct ihevcd_cxa_create_op_t ihevcd_cxa_create_op_t;

struct iv_obj_t {
    void *pv_codec_handle;
};

struct ihevcd_cxa_create_ip_t {
    struct {
        void (*pf_aligned_free)(void *pv_mem_ctxt, void *pv_buf);
        void *pv_mem_ctxt;
    } s_ivd_create_ip_t;
};

struct ihevcd_cxa_create_op_t {
    struct {
        UWORD32 u4_error_code;
    } s_ivd_create_op_t;
};

WORD32 ihevcd_allocate_static_bufs(iv_obj_t **pps_codec_obj, void *pv_api_ip, void *pv_api_op);
WORD32 ihevcd_free_static_bufs(iv_obj_t *ps_codec_obj);
WORD32 ihevcd_init(codec_t *ps_codec);
void TRACE_INIT(void *);
void STATS_INIT(void);