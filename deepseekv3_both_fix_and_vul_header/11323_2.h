#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <err.h>
#include <locale.h>
#include <stdbool.h>

typedef void* pam_handle_t;

extern pam_handle_t *pamh;
extern int _pam_session_opened;
extern bool caught_signal;
extern bool same_session;

#define PAM_ABORT 1
#define PAM_SUCCESS 0

void cleanup_pam(int retval);
int is_pam_failure(int retval);
void su_catch_sig(int sig);
const char *pam_strerror(pam_handle_t *pamh, int errnum);
int pam_open_session(pam_handle_t *pamh, int flags);