#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <unistd.h>
#include <grp.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <stdbool.h>
#include <stdio.h>

extern const char *g_settings_dump_location;
extern bool g_settings_privatereports;
extern long client_uid;

struct dump_dir {
    char *dd_dirname;
};

struct strbuf {
    char *buf;
};

int dir_is_in_dump_location(const char *dirname);
void error_msg(const char *fmt, ...);
struct dump_dir *dd_opendir(const char *dirname, int flags);
bool problem_dump_dir_is_complete(struct dump_dir *dd);
void dd_close(struct dump_dir *dd);
bool dump_dir_accessible_by_uid(const char *dirname, long uid);
int spawn_event_handler_child(const char *dirname, const char *handler, int *child_stdout_fd);
struct strbuf *strbuf_new();
void strbuf_append_str(struct strbuf *sb, const char *str);
void strbuf_clear(struct strbuf *sb);
void strbuf_free(struct strbuf *sb);
void log(const char *fmt, ...);
int prefixcmp(const char *str, const char *prefix);
char *xstrdup(const char *str);
int safe_waitpid(pid_t pid, int *status, int options);
void perror_msg(const char *fmt, ...);
char *dd_load_text_ext(struct dump_dir *dd, const char *filename, int flags);
void dd_save_text(struct dump_dir *dd, const char *filename, const char *data);
char *xasprintf(const char *fmt, ...);
void dd_sanitize_mode_and_owner(struct dump_dir *dd);
void log_notice(const char *fmt, ...);
void log_warning(const char *fmt, ...);
void delete_dump_dir(const char *dirname);
void xmove_fd(int fd_from, int fd_to);
int safe_read(int fd, void *buf, size_t count);

#define FILENAME_COUNT "count"
#define FILENAME_TIME "time"
#define FILENAME_LAST_OCCURRENCE "last_occurrence"
#define DD_OPEN_READONLY 0
#define DD_FAIL_QUIETLY_ENOENT 0
#define DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE 0