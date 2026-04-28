#include <stdlib.h>
#include <string.h>

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

enum QuadOption {
    MUTT_ABORT,
    MUTT_NO,
    MUTT_YES
};

enum ImapExecResult {
    IMAP_EXEC_SUCCESS,
    IMAP_EXEC_ERROR,
    IMAP_EXEC_FATAL
};

enum ImapCmdResult {
    IMAP_RES_OK
};

enum ImapState {
    IMAP_CONNECTED,
    IMAP_AUTHENTICATED
};

enum ImapCmdFlags {
    IMAP_CMD_SINGLE,
    IMAP_CMD_NO_FLAGS
};

#define IMAP_CAP_STARTTLS (1 << 0)
#define C_SslForceTls 0
#define C_SslStarttls 0
#define USE_SSL 0

extern int mutt_socket_open(struct Connection *conn);
extern int imap_cmd_step(struct ImapAccountData *adata);
extern void imap_close_connection(struct ImapAccountData *adata);
extern int mutt_istr_startswith(const char *str, const char *prefix);
extern int check_capabilities(struct ImapAccountData *adata);
extern enum ImapExecResult imap_exec(struct ImapAccountData *adata, const char *cmd, int flags);
extern void mutt_socket_empty(struct Connection *conn);
extern int mutt_ssl_starttls(struct Connection *conn);
extern void mutt_error(const char *msg);
extern enum QuadOption query_quadoption(int opt, const char *prompt);
extern void imap_error(const char *where, const char *msg);
extern void FREE(void *ptr);
extern const char *_(const char *str);