#include <stdlib.h>
#include <string.h>

#define OUT
#define IN
#define OPTIONAL

typedef int fm_mgr_config_errno_t;
#define FM_CONF_OK 0
#define FM_CONF_NO_MEM 1
#define FM_CONF_INIT_ERR 2

typedef enum {
    FM_MGR_SM,
    FM_MGR_PM,
    FM_MGR_FE
} fm_mgr_type_t;

typedef struct fm_config_conx_hdl {
    int instance;
} fm_config_conx_hdl;

typedef fm_config_conx_hdl* p_fm_config_conx_hdlt;

fm_mgr_config_errno_t fm_mgr_config_mgr_connect(fm_config_conx_hdl* hdl, fm_mgr_type_t type);