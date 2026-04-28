#include <stdio.h>
#include <string.h>

struct Connection {
    int ssf;
};

struct PopAccountData {
    struct Connection *conn;
    int cmd_stls;
    int use_stls;
    char *err_msg;
    unsigned int size;
    int status;
};

enum QuadOption {
    MUTT_ABORT,
    MUTT_YES
};

#define POP_DISCONNECTED 0
#define USE_SSL 1

extern int C_SslForceTls;
extern int C_SslStarttls;

extern int pop_connect(struct PopAccountData *adata);
extern int pop_capabilities(struct PopAccountData *adata, int mode);
extern int pop_query(struct PopAccountData *adata, char *buf, size_t buflen);
extern int pop_authenticate(struct PopAccountData *adata);
extern int mutt_ssl_starttls(struct Connection *conn);
extern void mutt_error(const char *fmt, ...);
extern void mutt_clear_error(void);
extern enum QuadOption query_quadoption(int opt, const char *prompt);
extern char *mutt_str_strfcpy(char *dest, const char *src, size_t dsize);
extern const char *_(const char *str);