#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/prctl.h>
#include <signal.h>
#include <fcntl.h>
#include <grp.h>
#include <syslog.h>
#include <stdint.h>

typedef unsigned int guint;
typedef int gint;
typedef int gboolean;
typedef void* gpointer;
typedef char gchar;
typedef uint64_t guint64;

#define FALSE 0
#define TRUE 1
#define PACKAGE_VERSION "1.0"
#define GETTEXT_PACKAGE "pkexec"
#define LOG_WARNING 4
#define LOG_NOTICE 5

struct passwd *pw;
struct passwd pwstruct;
gchar *original_user_name;
gchar *original_cwd;
gchar *command_line;

typedef struct {
    void **pdata;
    unsigned int len;
} GPtrArray;

typedef struct {
    char *message;
} GError;

typedef struct {
    int dummy;
} PolkitAuthority;
typedef struct {
    int dummy;
} PolkitAuthorizationResult;
typedef struct {
    int dummy;
} PolkitSubject;
typedef struct {
    int dummy;
} PolkitDetails;
typedef struct {
    int dummy;
} PolkitAgentListener;

#define POLKIT_UNIX_PROCESS(x) ((void*)x)
#define POLKIT_CHECK_AUTHORIZATION_FLAGS_ALLOW_USER_INTERACTION 1
#define POLKIT_AGENT_REGISTER_FLAGS_RUN_IN_THREAD 1
#define GINT_TO_POINTER(i) ((gpointer)(long)(i))

typedef void (*GFunc)(void* data, void* user_data);

void g_printerr(const char *format, ...);
char *g_strdup(const char *str);
char *g_get_user_name(void);
char *g_get_current_dir(void);
char *g_strerror(int errnum);
void g_print(const char *format, ...);
void g_assert(int condition);
char *g_find_program_in_path(const char *program);
void g_free(void *ptr);
GPtrArray *g_ptr_array_new(void);
void g_ptr_array_add(GPtrArray *array, void *data);
void *g_ptr_array_free(GPtrArray *array, int free_segment);
char *g_strjoinv(const char *separator, char **str_array);
char *g_getenv(const char *variable);
char *g_get_home_dir(void);
char *g_build_filename(const char *first_element, ...);
int g_setenv(const char *variable, const char *value, int overwrite);
char *g_strdup_printf(const char *format, ...);
int g_strcmp0(const char *str1, const char *str2);
void g_error_free(GError *error);
void g_object_unref(void *object);
void g_ptr_array_foreach(GPtrArray *array, GFunc func, void *user_data);

PolkitSubject *polkit_unix_process_new_for_owner(pid_t pid, guint64 start_time, uid_t uid);
guint polkit_unix_process_get_pid(void *process);
gint polkit_unix_process_get_uid(void *process);
guint64 polkit_unix_process_get_start_time(void *process);
PolkitAuthority *polkit_authority_get_sync(void *cancellable, GError **error);
PolkitAuthorizationResult *polkit_authority_check_authorization_sync(PolkitAuthority *authority,
                                                                    PolkitSubject *subject,
                                                                    const char *action_id,
                                                                    PolkitDetails *details,
                                                                    int flags,
                                                                    void *cancellable,
                                                                    GError **error);
gboolean polkit_authorization_result_get_is_authorized(PolkitAuthorizationResult *result);
gboolean polkit_authorization_result_get_is_challenge(PolkitAuthorizationResult *result);
gboolean polkit_authorization_result_get_dismissed(PolkitAuthorizationResult *result);
PolkitDetails *polkit_details_new(void);
void polkit_details_insert(PolkitDetails *details, const char *key, const char *value);
PolkitAgentListener *polkit_agent_text_listener_new(void *cancellable, GError **error);
gpointer polkit_agent_listener_register(PolkitAgentListener *listener,
                                        int flags,
                                        PolkitSubject *subject,
                                        const char *object_path,
                                        void *cancellable,
                                        GError **error);
void polkit_agent_listener_unregister(gpointer handle);
void g_assert_not_reached(void);

int validate_environment_variable(const char *key, const char *value);
void usage(int argc, char *argv[]);
void log_message(int priority, gboolean log_to_stderr, const char *message);
int set_close_on_exec(int fd, void *data);
int fdwalk(int (*func)(int fd, void *data), void *data);
const char *N_(const char *msgid);