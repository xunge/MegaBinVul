#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

typedef int fm_mgr_config_errno_t;
typedef void* p_hsm_com_client_hdl_t;

typedef enum {
    FM_MGR_SM,
    FM_MGR_PM, 
    FM_MGR_FE
} fm_mgr_type_t;

typedef enum {
    FM_CONF_OK,
    FM_CONF_INIT_ERR,
    FM_CONF_CONX_ERR
} fm_conf_err_t;

#define HSM_FM_SCK_SM "SM_"
#define HSM_FM_SCK_PM "PM_" 
#define HSM_FM_SCK_FE "FE_"
#define HSM_FM_SCK_PREFIX "/tmp/"

typedef struct {
    p_hsm_com_client_hdl_t sm_hdl;
    p_hsm_com_client_hdl_t pm_hdl;
    p_hsm_com_client_hdl_t fe_hdl;
    unsigned int conx_mask;
    int instance;
} fm_config_conx_hdl;

typedef enum {
    HSM_COM_OK
} hsm_com_err_t;

hsm_com_err_t hcom_client_init(p_hsm_com_client_hdl_t*, const char*, const char*, int);
hsm_com_err_t hcom_client_connect(p_hsm_com_client_hdl_t);