#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

typedef struct _User {
    uid_t uid;
    void* daemon;
} User;

typedef struct _AccountsUser AccountsUser;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;

typedef enum {
    ERROR_FAILED
} ErrorType;

#define gboolean bool
#define TRUE true
#define FALSE false
#define gchar char
#define gpointer void*
typedef void (*GCallback)(void);

typedef void (*GDestroyNotify)(void*);

static bool get_caller_uid(GDBusMethodInvocation *context, int *uid) {
    return false;
}

static void throw_error(GDBusMethodInvocation *context, ErrorType error, const char *message) {}

static void daemon_local_check_auth(void* daemon, User *user, const char *action_id, bool allow_interaction, GCallback callback, GDBusMethodInvocation *context, void* user_data, GDestroyNotify destroy_notify) {}

static void user_change_real_name_authorized_cb(User *user, GDBusMethodInvocation *context, void* user_data) {}

static char* g_strdup(const char *str) {
    return str ? strdup(str) : NULL;
}

static void g_free(void *ptr) {
    free(ptr);
}