#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef unsigned int guint;
typedef int gint;
typedef char gchar;
typedef int gboolean;
typedef void* gpointer;
typedef uint64_t guint64;
typedef const char* gconstpointer;

#define FALSE 0
#define TRUE 1
#define _(x) x
#define G_GUINT64_FORMAT "lu"
#define PACKAGE_VERSION "1.0"

typedef struct _GError {
    int domain;
    int code;
    char* message;
} GError;

typedef struct _PolkitAuthority PolkitAuthority;
typedef struct _PolkitAuthorizationResult PolkitAuthorizationResult;
typedef struct _PolkitSubject PolkitSubject;
typedef struct _PolkitDetails PolkitDetails;
typedef struct _PolkitAgentListener PolkitAgentListener;

typedef enum {
    POLKIT_CHECK_AUTHORIZATION_FLAGS_NONE,
    POLKIT_CHECK_AUTHORIZATION_FLAGS_ALLOW_USER_INTERACTION
} PolkitCheckAuthorizationFlags;

#define POLKIT_AGENT_REGISTER_FLAGS_RUN_IN_THREAD (1 << 0)

#define G_GNUC_BEGIN_IGNORE_DEPRECATIONS
#define G_GNUC_END_IGNORE_DEPRECATIONS

PolkitDetails* polkit_details_new(void);
void polkit_details_insert(PolkitDetails* details, const char* key, const char* value);
char** polkit_details_get_keys(PolkitDetails* details);
const char* polkit_details_lookup(PolkitDetails* details, const char* key);
PolkitSubject* polkit_unix_process_new_for_owner(int pid, guint64 start_time, unsigned int uid);
PolkitSubject* polkit_unix_process_new_full(int pid, guint64 start_time);
PolkitSubject* polkit_unix_process_new(int pid);
PolkitSubject* polkit_system_bus_name_new(const char* name);
PolkitAuthority* polkit_authority_get_sync(void* cancellable, GError** error);
PolkitAuthorizationResult* polkit_authority_check_authorization_sync(PolkitAuthority* authority, PolkitSubject* subject, const char* action_id, PolkitDetails* details, PolkitCheckAuthorizationFlags flags, void* cancellable, GError** error);
int polkit_authorization_result_get_is_authorized(PolkitAuthorizationResult* result);
int polkit_authorization_result_get_is_challenge(PolkitAuthorizationResult* result);
int polkit_authorization_result_get_dismissed(PolkitAuthorizationResult* result);
PolkitDetails* polkit_authorization_result_get_details(PolkitAuthorizationResult* result);
PolkitAgentListener* polkit_agent_text_listener_new(void* session, GError** error);
gpointer polkit_agent_listener_register(PolkitAgentListener* listener, int flags, PolkitSubject* subject, const char* object_path, void* cancellable, GError** error);
void polkit_agent_listener_unregister(gpointer handle);
void g_object_unref(void* object);
void g_free(void* mem);
char* g_strdup(const char* str);
void g_strfreev(char** str_array);
int g_strcmp0(const char* str1, const char* str2);
void g_set_prgname(const char* prgname);
const char* g_get_prgname(void);
void g_printerr(const char* format, ...);
void g_print(const char* format, ...);
void g_error_free(GError* error);
void help(void);
int do_list_or_revoke_temp_authz(gboolean revoke);
char* escape_str(const char* str);