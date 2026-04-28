#include <stddef.h>
#include <string.h>

#define LONG_STRING 1024
#define EXACT_ADDRESS

typedef struct _address
{
  char *personal;
  char *mailbox;
  char *val;
  int group;
  struct _address *next;
} ADDRESS;

extern int RFC822Error;

int is_email_wsp(char c);
const char *skip_email_wsp(const char *s);
size_t mutt_strlen(const char *s);
void terminate_buffer(char *buf, size_t len);
void add_addrspec(ADDRESS **top, ADDRESS **last, char *phrase, char *comment, size_t *commentlen, size_t maxlen);
ADDRESS *rfc822_new_address(void);
void rfc822_free_address(ADDRESS **addr);
char *safe_strdup(const char *s);
char *mutt_substrdup(const char *begin, const char *end);
const char *next_token(const char *s, char *buf, size_t *len, size_t maxlen);
const char *parse_quote(const char *s, char *buf, size_t *len, size_t maxlen);
const char *parse_literal(const char *s, char *buf, size_t *len, size_t maxlen);
const char *parse_route_addr(const char *s, char *comment, size_t *commentlen, size_t maxlen, ADDRESS *addr);