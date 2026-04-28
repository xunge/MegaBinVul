#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct IMAP_DATA IMAP_DATA;
typedef struct CONNECTION CONNECTION;

struct CONNECTION {
    int ssf;
};

struct IMAP_DATA {
    CONNECTION *conn;
    int state;
    char *buf;
    unsigned long capabilities;
    char *capstr;
};

#define IMAP_CONNECTED 1
#define IMAP_AUTHENTICATED 2
#define IMAP_CMD_OK 0
#define IMAP_CMD_FAIL_OK -2
#define STARTTLS (1UL << 0)

#define USE_SSL 1
#define OPTSSLFORCETLS 1
#define OPT_SSLSTARTTLS 2
#define MUTT_YES 1

#define FREE(p) free(*(p)), *(p) = NULL

int mutt_socket_open(CONNECTION *conn);
int imap_cmd_step(IMAP_DATA *idata);
void imap_close_connection(IMAP_DATA *idata);
int imap_check_capabilities(IMAP_DATA *idata);
int imap_exec(IMAP_DATA *idata, const char *cmd, int flags);
int mutt_ssl_starttls(CONNECTION *conn);
void mutt_error(const char *msg);
void mutt_sleep(int seconds);
int query_quadoption(int opt, const char *prompt);
void imap_error(const char *where, const char *msg);

int ascii_strncasecmp(const char *a, const char *b, size_t n);
int option(int opt);
int mutt_bit_isset(unsigned long bits, unsigned long bit);

#define _(msg) (msg)