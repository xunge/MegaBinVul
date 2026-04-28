#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define LONG_STRING 1024
#define STRING 256

struct ImapData;
struct Buffer {
    char *data;
    size_t dsize;
};
struct ImapMbox {
    char *mbox;
    char account[LONG_STRING];
};

extern bool ImapCheckSubscribed;
extern bool mx_is_imap(const char *path);
extern int imap_parse_path(const char *path, struct ImapMbox *mx);
extern struct ImapData *imap_conn_find(const char *account, int flags);
extern void imap_fix_path(struct ImapData *idata, const char *mbox, char *buf, size_t buflen);
extern void mutt_buffer_init(struct Buffer *buf);
extern int mutt_parse_rc_line(const char *line, struct Buffer *token, struct Buffer *err);
extern void imap_munge_mbox_name(struct ImapData *idata, char *dest, size_t dlen, const char *src);
extern int imap_exec(struct ImapData *idata, const char *cmd, int flags);
extern void imap_unmunge_mbox_name(struct ImapData *idata, char *s);
extern void mutt_error(const char *msg);
extern void mutt_debug(int level, const char *fmt, ...);
extern void mutt_message(const char *fmt, ...);
extern void FREE(void *ptr);
extern char *mutt_str_strfcpy(char *dest, const char *src, size_t dsize);