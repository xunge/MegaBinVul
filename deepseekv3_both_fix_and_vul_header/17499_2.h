#include <sys/types.h>
#include <sys/stat.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <time.h>
#include <utime.h>
#include <fnmatch.h>
#ifdef __CYGWIN__
#include <windows.h>
#include <sys/cygwin.h>
#endif

typedef union {
    struct sockaddr sa;
    struct sockaddr_in sin;
    struct sockaddr_in6 sin6;
} address_t;

struct cmdtab_entry {
    const char *text;
    int need_ident;
    int check_perm;
    int check_dirty;
    int unlink;
    int action;
    int update;
};

struct csync_group {
    char *gname;
    char *myname;
    struct csync_group *next;
};

struct csync_nossl {
    const char *pattern_from;
    const char *pattern_to;
    struct csync_nossl *next;
};

extern struct cmdtab_entry cmdtab[];
extern int csync_compare_mode;
extern int csync_ignore_uid;
extern int csync_ignore_gid;
extern int csync_ignore_mod;
extern FILE *csync_debug_out;
extern int csync_debug_level;
extern char *active_grouplist;
extern struct csync_group *csync_group;
extern int csync_conn_usessl;
extern struct csync_nossl *csync_nossl;
extern char *myhostname;
extern char *cmd_error;

enum {
    CR_ERR_UNKNOWN_COMMAND,
    CR_ERR_PERM_DENIED,
    CR_ERR_PERM_DENIED_FOR_SLAVE,
    CR_ERR_PARENT_DIR_MISSING,
    CR_OK_PATH_NOT_FOUND,
    CR_OK_NOT_FOUND,
    CR_OK_DATA_FOLLOWS,
    CR_ERR_IDENTIFICATION_FAILED,
    CR_ERR_SSL_EXPECTED,
    CR_ERR_GROUP_LIST_ALREADY_SET,
    CR_OK_CU_LATER,
    CR_OK_CMD_FINISHED,
    CR_OK_SEND_DATA,
    CR_ERR_WIN32_EIO_CREATE_DIR
};

enum {
    A_SIG,
    A_MARK,
    A_TYPE,
    A_GETTM,
    A_GETSZ,
    A_FLUSH,
    A_DEL,
    A_PATCH,
    A_MKDIR,
    A_MKCHR,
    A_MKBLK,
    A_MKFIFO,
    A_MKLINK,
    A_MKSOCK,
    A_SETOWN,
    A_SETMOD,
    A_SETIME,
    A_LIST,
    A_DEBUG,
    A_HELLO,
    A_GROUP,
    A_BYE
};

#define SQL(...)
#define SQL_BEGIN(...)
#define SQL_END
#define SQL_V(x) ""

extern void csync_fatal(const char *fmt, ...);
extern void set_peername_from_env(address_t *peername, const char *env_var);
extern int conn_gets(char *line, int size);
extern int setup_tag(char **tag, char *line);
extern char *conn_response(int code);
extern void conn_printf(const char *fmt, ...);
extern char *csync_inet_ntop(address_t *addr);
extern void on_cygwin_lowercase(char *str);
extern int csync_perm(const char *path, const char *host, const char *peer);
extern void csync_mark(const char *path, const char *peer, int mode);
extern int csync_check_dirty(const char *path, const char *peer, int flush);
extern void csync_unlink(const char *path, int mode);
extern int lstat_strict(const char *path, struct stat *st);
extern char *prefixsubst(const char *path);
extern int csync_check_pure(const char *path);
extern char *csync_genchecktxt(struct stat *st, const char *path, int full);
extern void csync_rs_sig(const char *path);
extern int conn_write(const void *buf, int len);
extern void conn_resp(int code);
extern void conn_resp_zero(int code);
extern int csync_file_backup(const char *path);
extern int csync_rs_patch(const char *path);
extern void csync_file_update(const char *path, const char *peer);
extern void csync_debug(int level, const char *fmt, ...);
extern void csync_schedule_commands(const char *path, int mode);
extern void destroy_tag(char **tag);
extern int verify_peername(const char *name, address_t *peername);
extern void split_dirname_basename(char *dirname, char *basename, const char *path);
extern char *url_encode(const char *str);
extern char *url_decode(const char *str);
extern int csync_match_file_host(const char *checktxt, const char *host, const char *peer, const char **extra_tags);