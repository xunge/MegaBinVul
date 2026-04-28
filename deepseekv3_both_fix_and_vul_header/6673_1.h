#include <stdint.h>
#include <stddef.h>

typedef int32_t WORD32;

#define IV_FAIL 0
#define IV_SUCCESS 1
#define IVD_MEM_ALLOC_FAILED 2
#define IVD_FATALERROR 3

typedef struct ivd_create_op_t {
    uint32_t u4_error_code;
} ivd_create_op_t;

typedef struct ivd_create_ip_t {
    void (*pf_aligned_free)(void *pv_mem_ctxt, void *pv_buf);
    void *pv_mem_ctxt;
} ivd_create_ip_t;

typedef struct ih264d_create_op_t {
    ivd_create_op_t s_ivd_create_op_t;
} ih264d_create_op_t;

typedef struct ih264d_create_ip_t {
    ivd_create_ip_t s_ivd_create_ip_t;
} ih264d_create_ip_t;

typedef struct iv_obj_t {
    void *pv_codec_handle;
} iv_obj_t;

WORD32 ih264d_allocate_static_bufs(iv_obj_t **dec_hdl, void *pv_api_ip, void *pv_api_op);
void ih264d_free_static_bufs(iv_obj_t *dec_hdl);