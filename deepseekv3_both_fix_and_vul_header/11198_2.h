#include <ctype.h>
#include <stddef.h>
#include <time.h>

#define SHORT_STRING 256

struct ImapHeader {
    struct ImapHeaderData *data;
    time_t received;
    long content_length;
};

struct ImapHeaderData {
    unsigned int uid;
};

#define SKIPWS(s) do { while (isspace((unsigned char)*(s))) (s)++; } while (0)

int mutt_str_strncasecmp(const char *a, const char *b, size_t n);
int mutt_str_atoui(const char *s, unsigned int *dst);
int mutt_str_atol(const char *s, long *dst);
char *imap_next_word(char *s);
time_t mutt_date_parse_imap(const char *s);
void mutt_debug(int level, const char *fmt, ...);
void imap_error(const char *location, const char *msg);
char *msg_parse_flags(struct ImapHeader *h, char *s);