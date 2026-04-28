#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

enum {
    STATE_NOTHING,
    KEX_NOTHING
};

struct cli_session {
    int state;
    int kex_state;
    int tty_raw_mode;
    int winchange;
    int stdincopy;
    int stdinflags;
    int stdoutcopy;
    int stdoutflags;
    int stderrcopy;
    int stderrflags;
    int retval;
    pid_t proxy_cmd_pid;
    void* lastprivkey;
    int lastauthtype;
    int is_trivial_auth;
};

struct session {
    void (*remoteclosed)(void);
    void (*extra_session_cleanup)(void);
    void* packettypes;
    int isserver;
#if DROPBEAR_KEX_FIRST_FOLLOWS
    void (*send_kex_first_guess)(void);
#endif
};

extern struct cli_session cli_ses;
extern struct session ses;

void cli_remoteclosed(void);
void cli_session_cleanup(void);
void cli_send_kex_first_guess(void);
void TRACE(const char* fmt, ...);
void* cli_packettypes;