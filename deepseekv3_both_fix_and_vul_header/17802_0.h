#include <stdbool.h>

struct Connection
{
  int ssf;
  struct
  {
    unsigned int flags;
  } account;
};

enum QuadOption
{
  MUTT_NO,
  MUTT_YES,
  MUTT_ABORT
};

#define SMTP_CAP_STARTTLS (1 << 0)
#define SMTP_CAP_AUTH (1 << 1)
#define MUTT_ACCT_USER (1 << 0)

extern bool C_SslForceTls;
extern enum QuadOption C_SslStarttls;
extern unsigned int Capabilities;

int mutt_socket_open(struct Connection *conn);
int smtp_get_resp(struct Connection *conn);
int smtp_helo(struct Connection *conn, bool esmtp);
int mutt_socket_send(struct Connection *conn, const char *buf);
int mutt_ssl_starttls(struct Connection *conn);
int smtp_auth(struct Connection *conn);
void mutt_error(const char *msg);
const char *_(const char *str);
enum QuadOption query_quadoption(enum QuadOption opt, const char *prompt);