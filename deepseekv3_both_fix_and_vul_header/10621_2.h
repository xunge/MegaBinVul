#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct {
    char *name;
    int (*cmdPtr)(void *, int, int, char **);
    int mgr;
} CommandEntry;

typedef struct {
    char c_path[256];
} SubHandle;

typedef struct p_fm_config_conx_hdlt {
    SubHandle *sm_hdl;
    SubHandle *pm_hdl;
    SubHandle *fe_hdl;
} *p_fm_config_conx_hdlt;

typedef int fm_mgr_config_errno_t;
#define FM_CONF_OK 0

extern CommandEntry commandList[];
extern int commandListLen;
extern char *fm_mgr_get_error_str(fm_mgr_config_errno_t err);
extern int fm_mgr_config_init(p_fm_config_conx_hdlt *hdl, int instance, char *rem_addr, char *community);
extern int fm_mgr_config_connect(p_fm_config_conx_hdlt hdl);
extern void usage(char *progname);