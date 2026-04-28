#include <stdbool.h>
#include <string.h>
#include <stddef.h>

#define CASE_MATCH 0
#define MUTT_ACCT_USER (1 << 0)
#define MUTT_YES 1
#define USE_SSL

enum NntpStatus {
    NNTP_NONE,
    NNTP_OK,
    NNTP_BYE
};

struct Account {
    char host[256];
    char user[256];
    unsigned int flags;
};

struct Connection {
    struct Account account;
};

struct NntpAccountData {
    struct Connection *conn;
    enum NntpStatus status;
    bool hasCAPABILITIES;
    bool hasSTARTTLS;
    int use_tls;
};

extern int mutt_socket_open(struct Connection *conn);
extern int mutt_socket_readln(char *buf, size_t len, struct Connection *conn);
extern int mutt_socket_send(struct Connection *conn, const char *buf);
extern void mutt_socket_close(struct Connection *conn);
extern void mutt_str_remove_trailing_ws(char *buf);
extern void mutt_error(const char *fmt, ...);
extern bool mutt_str_startswith(const char *str, const char *prefix, int flags);
extern int nntp_capabilities(struct NntpAccountData *adata);
extern int nntp_auth(struct NntpAccountData *adata);
extern int nntp_attempt_features(struct NntpAccountData *adata);
extern int nntp_connect_error(struct NntpAccountData *adata);
extern void mutt_message(const char *fmt, ...);
extern void mutt_sleep(int seconds);
extern int mutt_ssl_starttls(struct Connection *conn);
extern int query_quadoption(int opt, const char *prompt);

extern int C_SslForceTls;
extern int C_SslStarttls;

const char *_(const char *str);