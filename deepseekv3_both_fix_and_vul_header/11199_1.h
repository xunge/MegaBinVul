#include <limits.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct ImapData {
    int status;
    char *buf;
    void *cmddata;
    int cmdtype;
    struct {
        struct {
            void *account;
        } *conn;
    };
};

struct Buffy {
    struct Buffy *next;
    int magic;
    char *path;
    short new;
    int msg_count;
    int msg_unread;
};

struct ImapMbox {
    char *mbox;
    struct {
        void *account;
    } account;
};

struct ImapStatus {
    unsigned int uidvalidity;
    unsigned int uidnext;
    int messages;
    int recent;
    int unseen;
    char *name;
};

extern struct Buffy *Incoming;
extern short MailCheckRecent;

#define IMAP_CMD_CONTINUE 0
#define IMAP_FATAL 1
#define IMAP_CT_STATUS 2
#define MUTT_IMAP 3
#define REDRAW_SIDEBAR 4
#define USE_SIDEBAR 1

#define mutt_debug(level, ...) 
#define mutt_str_strncmp(a, b, n) strncmp(a, b, n)
#define mutt_str_strdup(s) strdup(s)
#define mutt_str_strlen(s) strlen(s)
#define SKIPWS(s) while (*(s) && isspace(*(s))) (s)++
#define FREE(p) free(*(p)); *(p) = NULL

static char *imap_next_word(char *s);
static int imap_get_literal_count(char *s, unsigned int *len);
static int imap_cmd_step(struct ImapData *idata);
static void imap_unmunge_mbox_name(struct ImapData *idata, char *s);
static struct ImapStatus *imap_mboxcache_get(struct ImapData *idata, char *s, int flag);
static int imap_parse_path(char *path, struct ImapMbox *mx);
static void imap_fix_path(struct ImapData *idata, char *src, char *dest, size_t dlen);
static int imap_mxcmp(char *a, char *b);
static void mutt_menu_set_current_redraw(int redraw);
static int imap_account_match(void *a, void *b);