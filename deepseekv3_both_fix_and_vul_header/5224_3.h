#include <stddef.h>

#define APR_HOOK_MIDDLE 0
#define APR_HOOK_FIRST 0
#define APR_HOOK_REALLY_LAST 0
#define ENABLE_DIAGNOSTICS

typedef struct apr_pool_t apr_pool_t;

void ap_hook_access_checker(void (*)(), void *, void *, int);
void ap_hook_check_user_id(void (*)(), void *, void *, int);
void ap_hook_post_config(void (*)(), void *, void *, int);
void ap_hook_child_init(void (*)(), void *, void *, int);
void ap_hook_create_request(void (*)(), void *, void *, int);
void ap_hook_handler(void (*)(), void *, const char * const *, int);
void ap_hook_open_logs(void (*)(), void *, void *, int);
void ap_hook_log_transaction(void (*)(), void *, void *, int);

void am_auth_mellon_user();
void am_check_uid();
void am_global_init();
void am_child_init();
void am_create_request();
void am_handler();
void am_diag_log_init();
void am_diag_finalize_request();