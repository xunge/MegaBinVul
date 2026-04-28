#include <stdlib.h>
#include <string.h>

typedef struct IMAP_DATA IMAP_DATA;
typedef struct CONNECTION CONNECTION;

struct CONNECTION {
    int ssf;
};

struct IMAP_DATA {
    CONNECTION *conn;
    int state;
    char *buf;
    unsigned long *capabilities;
    char *capstr;
};

#define IMAP_CONNECTED 0
#define IMAP_AUTHENTICATED 1
#define IMAP_CMD_OK 0
#define STARTTLS 0
#define MUTT_YES 1
#define MUTT_NO 0
#define IMAP_CMD_FAIL_OK 0
#define OPTSSLFORCETLS 0
#define OPT_SSLSTARTTLS 0

int mutt_socket_open(CONNECTION *conn);
int imap_cmd_step(IMAP_DATA *idata);
void imap_close_connection(IMAP_DATA *idata);
int ascii_strncasecmp(const char *s1, const char *s2, size_t n);
int imap_check_capabilities(IMAP_DATA *idata);
int imap_exec(IMAP_DATA *idata, const char *cmd, int flags);
int mutt_ssl_starttls(CONNECTION *conn);
void mutt_error(const char *msg);
void mutt_sleep(int seconds);
void imap_error(const char *where, const char *msg);
int option(int opt);
int query_quadoption(int opt, const char *prompt);
int mutt_bit_isset(unsigned long *bits, int bit);

#define FREE(ptr) free(*(ptr)), *(ptr) = NULL