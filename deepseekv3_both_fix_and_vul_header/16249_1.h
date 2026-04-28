#include <stdlib.h>
#include <stdint.h>
#include <syslog.h>

typedef void *pam_handle_t;
#define PAM_EXTERN extern
#define UNUSED(x) x __attribute__((unused))
#define TAC_PLUS_ACCT_FLAG_START 0

extern short int task_id;
extern int _pam_account(pam_handle_t *, int, const char **, int, void *);
extern unsigned int magic(void);