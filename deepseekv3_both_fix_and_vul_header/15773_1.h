#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>

static const char *g_settings_dump_location;
static bool g_settings_privatereports;
static uid_t client_uid;

struct dump_dir {
    const char *dd_dirname;
};

struct strbuf {
    char *buf;
    size_t len;
    size_t alloc;
};

#define FILENAME_COUNT "count"
#define FILENAME_TIME "time"
#define FILENAME_LAST_OCCURRENCE "last_occurrence"

#define DD_OPEN_READONLY 0
#define DD_FAIL_QUIETLY_ENOENT 0
#define DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE 0

static bool dir_is_in_dump_location(const char *dirname);
static bool dir_has_correct_permissions(const char *dirname);
static void error_msg(const char *fmt, ...);
static struct dump_dir *dd_opendir(const char *dirname, int flags);
static bool problem_dump_dir_is_complete(struct dump_dir *dd);
static void dd_close(struct dump_dir *dd);
static bool dump_dir_accessible_by_uid(const char *dirname, uid_t uid);
static int safe_read(int fd, void *buf, size_t count);
static int safe_waitpid(pid_t pid, int *status, int options);
static void perror_msg(const char *fmt, ...);
static void log(const char *fmt, ...);
static int prefixcmp(const char *str, const char *prefix);
static char *xstrdup(const char *s);
static struct strbuf *strbuf_new(void);
static void strbuf_append_str(struct strbuf *sb, const char *str);
static void strbuf_clear(struct strbuf *sb);
static void strbuf_free(struct strbuf *sb);
static char *dd_load_text_ext(struct dump_dir *dd, const char *filename, int flags);
static void dd_save_text(struct dump_dir *dd, const char *filename, const char *text);
static char *xasprintf(const char *fmt, ...);
static void dd_sanitize_mode_and_owner(struct dump_dir *dd);
static void log_notice(const char *fmt, ...);
static void log_warning(const char *fmt, ...);
static void delete_dump_dir(const char *dirname);
static pid_t spawn_event_handler_child(const char *dirname, const char *handler, int *fd_out);
static void xmove_fd(int fd_from, int fd_to);