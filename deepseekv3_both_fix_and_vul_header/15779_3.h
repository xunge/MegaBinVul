#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

typedef struct _GDBusConnection GDBusConnection;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GVariant GVariant;
typedef struct _GVariantBuilder GVariantBuilder;
typedef struct _GVariantType GVariantType;
typedef struct _GList {
    void *data;
    struct _GList *next;
    struct _GList *prev;
} GList;
typedef struct _GMainLoop GMainLoop;
typedef void* gpointer;
typedef char gchar;
typedef int gboolean;
typedef long glong;

typedef enum {
    DD_STAT_OWNED_BY_UID = 1 << 0,
    DD_STAT_ACCESSIBLE_BY_UID = 1 << 1
} DDStatFlags;

typedef enum {
    DD_OPEN_READONLY = 1 << 0,
    DD_FAIL_QUIETLY_EACCES = 1 << 1
} DDOpenFlags;

typedef enum {
    DD_LOAD_TEXT_RETURN_NULL_ON_FAILURE = 1 << 0,
    DD_FAIL_QUIETLY_ENOENT = 1 << 1,
    DD_FAIL_QUIETLY_EACCES_FLAG = 1 << 2
} DDLoadTextFlags;

struct dump_dir;

#define _(String) (String)
#define G_VARIANT_TYPE_ARRAY ((const GVariantType*)"a*")

extern void reset_timeout(void);
extern uid_t get_caller_uid(GDBusConnection *connection, GDBusMethodInvocation *invocation, const gchar *caller);
extern void log_notice(const char *format, ...);
extern void log_info(const char *format, ...);
extern char *handle_new_problem(GVariant *parameters, uid_t caller_uid, char **error);
extern GList *get_problem_dirs_for_uid(uid_t uid, const char *dump_location);
extern GVariant *variant_from_string_list(GList *list);
extern void list_free_with_free(GList *list);
extern const char *g_settings_dump_location;
extern int polkit_check_authorization_dname(const char *caller, const char *action);
typedef enum { PolkitYes } PolkitResult;
extern GList *get_problem_dirs_not_accessible_by_uid(uid_t uid, const char *dump_location);
extern int allowed_problem_dir(const char *problem_dir);
extern void return_InvalidProblemDir_error(GDBusMethodInvocation *invocation, const char *problem_dir);
extern int dump_dir_stat_for_uid(const char *problem_dir, uid_t uid);
extern void perror_msg(const char *format, ...);
extern struct dump_dir *dd_opendir(const char *dir, int flags);
extern int dd_chown(struct dump_dir *dd, uid_t uid);
extern void dd_close(struct dump_dir *dd);
extern int dump_dir_accessible_by_uid(const char *dir, uid_t uid);
extern GList *string_list_from_variant(GVariant *variant);
extern char *dd_load_text_ext(struct dump_dir *dd, const char *name, int flags);
extern struct dump_dir *open_directory_for_modification_of_element(GDBusMethodInvocation *invocation, uid_t caller_uid, const char *problem_id, const char *element);
extern const double g_settings_nMaxCrashReportsSize;
extern long dd_get_item_size(struct dump_dir *dd, const char *element);
extern double get_dirsize(const char *dir);
extern int dd_save_text(struct dump_dir *dd, const char *name, const char *value);
extern int dd_delete_item(struct dump_dir *dd, const char *name);
extern void delete_dump_dir(const char *dir);
extern GList *get_problem_dirs_for_element_in_time(uid_t uid, const char *element, const char *value, glong timestamp_from, glong timestamp_to);
extern GMainLoop *loop;

/* GLib-like function declarations */
extern int g_strcmp0(const char *str1, const char *str2);
extern GVariant *g_variant_get_child_value(GVariant *variant, size_t index);
extern void g_dbus_method_invocation_return_dbus_error(GDBusMethodInvocation *invocation, const char *error_name, const char *error_message);
extern GVariant *g_variant_new(const char *format_string, ...);
extern void g_dbus_method_invocation_return_value(GDBusMethodInvocation *invocation, GVariant *parameters);
extern void g_variant_get(GVariant *variant, const char *format_string, ...);
extern void g_variant_get_child(GVariant *variant, size_t index, const char *format_string, ...);
extern void g_variant_unref(GVariant *variant);
extern GVariantBuilder *g_variant_builder_new(const GVariantType *type);
extern void g_variant_builder_add(GVariantBuilder *builder, const char *format_string, ...);
extern void g_variant_builder_unref(GVariantBuilder *builder);
extern void g_main_loop_quit(GMainLoop *loop);
extern char *xasprintf(const char *format, ...);