#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdbool.h>

struct dump_dir;
typedef void GDBusMethodInvocation;

extern struct dump_dir *dd_opendir(const char *dir, int flags);
extern bool dump_dir_accessible_by_uid(const char *dir, uid_t uid);
extern char *xasprintf(const char *format, ...);
extern void return_InvalidProblemDir_error(GDBusMethodInvocation *invocation, const char *problem_id);
extern void log_notice(const char *format, ...);
extern const char *_(const char *str);

#define FILENAME_TIME "time"
#define FILENAME_UID "uid"

void g_dbus_method_invocation_return_dbus_error(GDBusMethodInvocation *invocation, const char *error_name, const char *error_message);