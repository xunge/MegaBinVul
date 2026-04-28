#include <stdint.h>

#define DROPBEAR_CLI_IMMEDIATE_AUTH 0
#define DROPBEAR_CLI_PUBKEY_AUTH 0

#define TRACE(x)

typedef struct {
    int authdone;
} auth_state;

typedef struct {
    auth_state authstate;
} session;

typedef struct {
    int is_trivial_auth;
    int state;
    int lastauthtype;
} cli_session;

typedef struct {
    int exit_on_trivial_auth;
} cli_options;

extern cli_options cli_opts;
extern cli_session cli_ses;
extern session ses;

enum {
    USERAUTH_SUCCESS_RCVD,
    AUTH_TYPE_NONE
};

void dropbear_exit(const char* msg);
void cli_auth_pubkey_cleanup();