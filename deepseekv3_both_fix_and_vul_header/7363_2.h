#include <stdlib.h>
#include <string.h>

struct error_obj {
    int status;
    const char *func_name;
    const char *error_msg;
};

struct pam_response {
    char *resp;
    int resp_retcode;
};

struct pam_conv {
    int (*conv)(int, const struct pam_message **, struct pam_response **, void *);
    void *appdata_ptr;
};

typedef void *pam_handle_t;

#define PAM_SUCCESS 0
#define PAM_SILENT 1
#define PAM_DISALLOW_NULL_AUTHTOK 2
#define PAM_AUTH_ERR 3
#define PAM_USER_UNKNOWN 4
#define PAM_NEW_AUTHTOK_REQD 5

int pam_start(const char *service_name, const char *user, const struct pam_conv *pam_conversation, pam_handle_t **pamh);
int pam_authenticate(pam_handle_t *pamh, int flags);
int pam_acct_mgmt(pam_handle_t *pamh, int flags);
int pam_end(pam_handle_t *pamh, int pam_status);
const char *pam_strerror(pam_handle_t *pamh, int errnum);
int conv_func(int num_msg, const struct pam_message **msg, struct pam_response **resp, void *appdata_ptr);