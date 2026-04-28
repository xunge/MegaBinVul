#include <stdlib.h>

#define DROPBEAR_CLI_IMMEDIATE_AUTH 1
#define DROPBEAR_CLI_PUBKEY_AUTH 1

#define TRACE(x) 

struct AuthState {
    int authdone;
};

struct Session {
    struct AuthState authstate;
};

struct CliSes {
    int state;
    int lastauthtype;
    int is_trivial_auth;
};

struct CliOpts {
    int disable_trivial_auth;
    int exit_on_trivial_auth;
};

extern struct Session ses;
extern struct CliSes cli_ses;
extern struct CliOpts cli_opts;

void dropbear_exit(const char* message);
void cli_auth_pubkey_cleanup(void);

#define USERAUTH_SUCCESS_RCVD 1
#define AUTH_TYPE_NONE 0