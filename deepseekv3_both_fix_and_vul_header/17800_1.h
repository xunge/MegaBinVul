#include <stdbool.h>
#include <stdlib.h>

struct Connection {
    int ssf;
};

struct ImapAccountData {
    struct Connection *conn;
    int state;
    char *buf;
    unsigned int capabilities;
    char *capstr;
};

enum ImapState {
    IMAP_CONNECTED,
    IMAP_AUTHENTICATED
};

enum ImapExecResult {
    IMAP_EXEC_SUCCESS,
    IMAP_EXEC_ERROR,
    IMAP_EXEC_FATAL
};

enum ImapRes {
    IMAP_RES_OK
};

enum QuadOption {
    MUTT_ABORT,
    MUTT_YES,
    MUTT_NO
};

#define CASE_IGNORE 0
#define IMAP_CMD_NO_FLAGS 0
#define IMAP_CAP_STARTTLS (1 << 0)

extern int mutt_socket_open(struct Connection *conn);
extern int imap_cmd_step(struct ImapAccountData *adata);
extern void imap_close_connection(struct ImapAccountData *adata);
extern bool mutt_str_startswith(const char *str, const char *prefix, int flags);
extern int check_capabilities(struct ImapAccountData *adata);
extern enum ImapExecResult imap_exec(struct ImapAccountData *adata, const char *cmd, int flags);
extern int mutt_ssl_starttls(struct Connection *conn);
extern void mutt_error(const char *msg);
extern enum QuadOption query_quadoption(int opt, const char *prompt);
extern int mutt_yesorno(const char *prompt, int opt);
extern void imap_error(const char *where, const char *msg);
extern void FREE(void *ptr);

extern int C_SslForceTls;
extern int C_SslStarttls;