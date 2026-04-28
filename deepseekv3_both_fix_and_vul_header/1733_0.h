#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct buf {
    unsigned char *payload;
    unsigned char *writepayload;
};

struct cli_opts {
    char *username;
    char *remotehost;
};

struct cli_ses {
    int interact_request_received;
    int is_trivial_auth;
};

struct session {
    struct buf payload;
    struct buf writepayload;
};

extern struct cli_opts cli_opts;
extern struct cli_ses cli_ses;
extern struct session ses;

#define DROPBEAR_MAX_CLI_INTERACT_PROMPTS 100
#define SSH_MSG_USERAUTH_INFO_RESPONSE 61

#define TRACE(x)
#define CHECKCLEARTOWRITE()
#define cleantext(x)
#define m_free(x) free(x)
#define m_strdup(x) strdup(x)
#define m_burn(x, y) memset(x, 0, y)
#define dropbear_exit(x) exit(1)
#define buf_getstring(x, y) NULL
#define buf_eatstring(x)
#define buf_getint(x) 0
#define buf_getbool(x) 0
#define buf_putbyte(x, y)
#define buf_putint(x, y)
#define buf_putstring(x, y, z)
#define encrypt_packet()
#define getpass_or_cancel(x) NULL
#define get_response(x) NULL