#include <stdbool.h>
#include <stdio.h>

typedef unsigned int ImapCmdFlags;
typedef int ImapExecResult;
typedef int ImapResult;

enum ImapStatus {
    IMAP_FATAL
};

enum LogLevel {
    LL_DEBUG1
};

struct Connection {
    struct {
        char *host;
    } account;
};

struct ImapAccountData {
    struct Connection *conn;
    int status;
    char *buf;
    void *nextcmd;
    void *lastcmd;
};

extern int C_ImapPollTimeout;

#define IMAP_CMD_SINGLE (1 << 0)
#define IMAP_CMD_POLL (1 << 1)
#define IMAP_CMD_QUEUE (1 << 2)

#define IMAP_EXEC_FATAL (-1)
#define IMAP_EXEC_ERROR (0)
#define IMAP_EXEC_SUCCESS (1)

#define IMAP_RES_CONTINUE (0)
#define IMAP_RES_NO (1)
#define IMAP_RES_OK (2)

int cmd_start(struct ImapAccountData *adata, const char *cmdstr, ImapCmdFlags flags);
void cmd_handle_fatal(struct ImapAccountData *adata);
int mutt_socket_poll(struct Connection *conn, int timeout);
void mutt_error(const char *fmt, ...);
void mutt_debug(enum LogLevel level, const char *fmt, ...);
void mutt_sig_allow_interrupt(bool allow);
int imap_cmd_step(struct ImapAccountData *adata);