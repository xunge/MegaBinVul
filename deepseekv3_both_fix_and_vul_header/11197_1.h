#include <ctype.h>
#include <stddef.h>

#define IMAP_SELECTED 1
#define IMAP_EXPUNGE_PENDING 1
#define IMAP_NEWMAIL_PENDING 2
#define IMAP_BYE 3

struct ImapData {
    char *buf;
    int state;
    unsigned int reopen;
    unsigned int max_msn;
    char *mailbox;
    unsigned int new_mail_count;
    int status;
};

extern struct ImapData *ImapServernoise;

extern char *imap_next_word(char *s);
extern int mutt_str_strncasecmp(const char *a, const char *b, size_t n);
extern int mutt_str_atoui(const char *str, unsigned int *dst);
extern void mutt_debug(int level, const char *fmt, ...);
extern void mutt_error(const char *fmt, ...);
extern void cmd_parse_expunge(struct ImapData *idata, char *s);
extern void cmd_parse_fetch(struct ImapData *idata, char *s);
extern void cmd_parse_capability(struct ImapData *idata, char *s);
extern void cmd_parse_list(struct ImapData *idata, char *s);
extern void cmd_parse_lsub(struct ImapData *idata, char *s);
extern void cmd_parse_myrights(struct ImapData *idata, char *s);
extern void cmd_parse_search(struct ImapData *idata, char *s);
extern void cmd_parse_status(struct ImapData *idata, char *s);
extern void cmd_parse_enabled(struct ImapData *idata, char *s);
extern void cmd_handle_fatal(struct ImapData *idata);

#define SKIPWS(p) while (*(p) && isspace((unsigned char) *(p))) p++