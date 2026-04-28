#include <stddef.h>

typedef struct gs_param_list_s gs_param_list;
typedef struct iparam_list_s iparam_list;
typedef const char *gs_param_name;

typedef struct {
    int *presult;
} iparam_loc;

typedef enum {
    gs_param_policy_ignore,
    gs_param_policy_consult_user
} gs_param_policy_t;

enum {
    gs_error_configurationerror
};

#define return_error(code) return (code)

int ref_param_read(iparam_list *iplist, gs_param_name pkey, iparam_loc *loc, int type);
gs_param_policy_t ref_param_read_get_policy(gs_param_list *plist, gs_param_name pkey);