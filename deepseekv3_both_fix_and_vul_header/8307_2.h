#include <sys/types.h>
#include <pwd.h>
#include <string.h>

#define MAX_PASSWORD_LEN 1024
#define USE_SHADOW 1
#define HAS_SHADOW_EXPIRE 1
#define KRB5 1
#define HAVE_CYGWIN 0
#define USE_PAM 1
#define PERMIT_YES 1

typedef void* HANDLE;
#define INVALID_HANDLE_VALUE ((HANDLE)(-1))

typedef struct Authctxt {
    struct passwd *pw;
    int valid;
    int force_pwchange;
} Authctxt;

struct options {
    int permit_root_login;
    int permit_empty_passwd;
    int kerberos_authentication;
    int use_pam;
} options;

int auth_krb5_password(Authctxt *authctxt, const char *password);
int auth_shadow_pwexpired(Authctxt *authctxt);
int sys_auth_passwd(Authctxt *authctxt, const char *password);
void disable_forwarding(void);
int sshpam_auth_passwd(Authctxt *authctxt, const char *password);
HANDLE cygwin_logon_user(struct passwd *pw, const char *password);
void cygwin_set_impersonation_token(HANDLE hToken);