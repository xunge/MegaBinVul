#include <stddef.h>

typedef void *pam_handle_t;
#define PAM_EXTERN extern
#define UNUSED(x) x __attribute__((unused))
#define TAC_PLUS_ACCT_FLAG_START 0

extern short int task_id;
extern short int magic(void);
extern int _pam_account(pam_handle_t *pamh, int argc, const char **argv, int flag, void *null);