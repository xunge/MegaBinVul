#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>

typedef enum {
    PolkitNo,
    PolkitYes
} PolkitAuthorizationResult;

#define DD_STAT_OWNED_BY_UID (1 << 0)
#define DD_STAT_ACCESSIBLE_BY_UID (1 << 1)
#define DD_OPEN_READONLY (1 << 0)
#define DD_FAIL_QUIETLY_EACCES (1 << 1)
#define DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE (1 << 0)
#define DD_FAIL_QUIETLY_ENOENT (1 << 1)

struct dump_dir;
struct _GDBusConnection;
struct _GDBusMethodInvocation;
struct _GVariant;
struct _GVariantBuilder;
struct _GList;
struct _GMainLoop;

typedef struct _GDBusConnection GDBusConnection;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVariant GVariant;
typedef struct _GVariantBuilder GVariantBuilder;
typedef struct _GList GList;
typedef struct _GMainLoop GMainLoop;
typedef void* gpointer;
typedef char gchar;
typedef long glong;
typedef int gboolean;

struct _GList {
    gpointer data;
    GList *next;
    GList *prev;
};

#define G_VARIANT_TYPE_ARRAY ((const char *)"a{ss}")

extern int g_strcmp0(const char *str1, const char *str2);
extern GVariant *g_variant_get_child_value(GVariant *variant, size_t index);
extern void g_dbus_method_invocation_return_dbus_error(GDBusMethodInvocation *invocation, const char *error_name, const char *error_message);
extern GVariant *g_variant_new(const char *format_string, ...);
extern void g_dbus_method_invocation_return_value(GDBusMethodInvocation *invocation, GVariant *parameters);
extern void g_variant_get(GVariant *variant, const char *format_string, ...);
extern void g_variant_get_child(GVariant *variant, size_t index, const char *format_string, ...);
extern void g_variant_unref(GVariant *variant);
extern GVariantBuilder *g_variant_builder_new(const char *type_string);
extern void g_variant_builder_add(GVariantBuilder *builder, const char *format_string, ...);
extern void g_variant_builder_unref(GVariantBuilder *builder);
extern void g_main_loop_quit(GMainLoop *loop);

extern const char *_(const char *str);

extern uid_t get_caller_uid(GDBusConnection *connection, GDBusMethodInvocation *invocation, const gchar *caller);
extern char *handle_new_problem(GVariant *parameters, uid_t caller_uid, char **error);
extern GList *get_problem_dirs_for_uid(uid_t uid, const char *dump_location);
extern GVariant *variant_from_string_list(GList *list);
extern void list_free_with_free(GList *list);
extern PolkitAuthorizationResult polkit_check_authorization_dname(const gchar *caller, const gchar *action);
extern GList *get_problem_dirs_not_accessible_by_uid(uid_t uid, const char *dump_location);
extern bool allowed_problem_dir(const char *dir);
extern int dd_openfd(const char *path);
extern int fdump_dir_stat_for_uid(int dir_fd, uid_t uid);
extern struct dump_dir *dd_fdopendir(int dir_fd, const char *path, int flags);
extern int dd_chown(struct dump_dir *dd, uid_t uid);
extern void dd_close(struct dump_dir *dd);
extern bool fdump_dir_accessible_by_uid(int dir_fd, uid_t uid);
extern GList *string_list_from_variant(GVariant *array);
extern char *dd_load_text_ext(struct dump_dir *dd, const char *element, int flags);
extern bool str_is_correct_filename(const char *name);
extern struct dump_dir *open_directory_for_modification_of_element(GDBusMethodInvocation *invocation, uid_t caller_uid, const char *problem_id, const char *element);
extern long dd_get_item_size(struct dump_dir *dd, const char *element);
extern double get_dirsize(const char *path);
extern void dd_save_text(struct dump_dir *dd, const char *element, const char *value);
extern int dd_delete_item(struct dump_dir *dd, const char *element);
extern int dd_delete(struct dump_dir *dd);
extern GList *get_problem_dirs_for_element_in_time(uid_t uid, const char *element, const char *value, glong from, glong to);
extern void reset_timeout();
extern void log_notice(const char *format, ...);
extern void perror_msg(const char *format, ...);
extern void error_msg(const char *format, ...);
extern void log_info(const char *format, ...);
extern char *xasprintf(const char *format, ...);
extern void free(void *ptr);
extern void return_InvalidProblemDir_error(GDBusMethodInvocation *invocation, const char *dir_name);

extern const char *g_settings_dump_location;
extern double g_settings_nMaxCrashReportsSize;
extern GMainLoop *loop;