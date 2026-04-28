#include <stdlib.h>
#include <string.h>

#define HSM_COM_SVR_MAX_PATH 256
#define HSM_COM_OK 0
#define HSM_COM_PATH_ERR 1
#define HSM_COM_NO_MEM 2

#define HSM_COM_C_STATE_IN 0

#define OUT
#define IN

typedef int hsm_com_errno_t;

typedef struct {
    void *scratch;
    size_t scratch_fill;
    size_t scratch_len;
} hsm_com_scratch_t;

typedef struct {
    char s_path[HSM_COM_SVR_MAX_PATH];
    char c_path[HSM_COM_SVR_MAX_PATH];
    void *recv_buf;
    void *send_buf;
    size_t buf_len;
    unsigned int trans_id;
    int client_state;
    hsm_com_scratch_t scr;
} hsm_com_client_hdl_t;

typedef hsm_com_client_hdl_t *p_hsm_com_client_hdl_t;