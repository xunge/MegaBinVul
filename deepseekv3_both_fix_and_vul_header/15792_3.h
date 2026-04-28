#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _GMainLoop GMainLoop;
typedef struct _GDBusConnection GDBusConnection;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVariant GVariant;
typedef struct _GVariantBuilder GVariantBuilder;
typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;
typedef char gchar;
typedef void* gpointer;
typedef long glong;
typedef int gboolean;

typedef enum {
    PolkitYes,
    PolkitNo,
    PolkitChallenge
} PolkitAuthorizationResult;

typedef struct dump_dir dump_dir;

#define DD_OPEN_READONLY 0
#define DD_FAIL_QUIETLY_EACCES 0
#define DD_FAIL_QUIETLY_ENOENT 0
#define DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE 0

#define DD_STAT_OWNED_BY_UID 0
#define DD_STAT_ACCESSIBLE_BY_UID 0

#define G_VARIANT_TYPE_ARRAY 0
#define G_VARIANT_TYPE_TUPLE 0

extern GMainLoop *loop;
extern char *g_settings_dump_location;
extern double g_settings_nMaxCrashReportsSize;

extern void reset_timeout(void);
extern uid_t get_caller_uid(GDBusConnection *connection, GDBusMethodInvocation *invocation, const gchar *caller);
extern void log_notice(const char *format, ...);
extern char *handle_new_problem(GVariant *value, uid_t caller_uid, char **error);
extern GList *get_problem_dirs_for_uid(uid_t uid, const char *dump_location);
extern GVariant *variant_from_string_list(GList *list);
extern void list_free_with_free(GList *list);
extern PolkitAuthorizationResult polkit_check_authorization_dname(const char *caller, const char *action);
extern GList *get_problem_dirs_not_accessible_by_uid(uid_t uid, const char *dump_location);
extern int allowed_problem_dir(const char *problem_dir);
extern void return_InvalidProblemDir_error(GDBusMethodInvocation *invocation, const char *problem_dir);
extern int dd_openfd(const char *path);
extern int fdump_dir_stat_for_uid(int dir_fd, uid_t uid);
extern struct dump_dir *dd_fdopendir(int dir_fd, const char *path, int flags);
extern int dd_chown(struct dump_dir *dd, uid_t uid);
extern int fdump_dir_accessible_by_uid(int dir_fd, uid_t uid);
extern GList *string_list_from_variant(GVariant *variant);
extern char *dd_load_text_ext(struct dump_dir *dd, const char *name, int flags);
extern struct dump_dir *open_directory_for_modification_of_element(GDBusMethodInvocation *invocation, uid_t caller_uid, const char *problem_id, const char *element);
extern long dd_get_item_size(struct dump_dir *dd, const char *element);
extern double get_dirsize(const char *path);
extern void dd_save_text(struct dump_dir *dd, const char *name, const char *value);
extern int dd_delete_item(struct dump_dir *dd, const char *name);
extern int dd_delete(struct dump_dir *dd);
extern GList *get_problem_dirs_for_element_in_time(uid_t uid, const char *element, const char *value, glong timestamp_from, glong timestamp_to);
extern void perror_msg(const char *format, ...);
extern void error_msg(const char *format, ...);
extern void log_info(const char *format, ...);
extern char *xasprintf(const char *format, ...);

/* GLib/GIO function declarations */
extern int g_strcmp0(const char *str1, const char *str2);
extern GVariant *g_variant_get_child_value(GVariant *value, size_t index);
extern void g_dbus_method_invocation_return_dbus_error(GDBusMethodInvocation *invocation, const char *error_name, const char *error_message);
extern GVariant *g_variant_new(const char *format_string, ...);
extern void g_dbus_method_invocation_return_value(GDBusMethodInvocation *invocation, GVariant *parameters);
extern void g_variant_get(GVariant *value, const char *format_string, ...);
extern void g_variant_get_child(GVariant *value, size_t index, const char *format_string, ...);
extern void g_variant_unref(GVariant *value);
extern GVariantBuilder *g_variant_builder_new(int type);
extern void g_variant_builder_add(GVariantBuilder *builder, const char *format_string, ...);
extern void g_variant_builder_unref(GVariantBuilder *builder);
extern void g_main_loop_quit(GMainLoop *loop);
extern void dd_close(struct dump_dir *dd);
extern const char *_(const char *msgid);