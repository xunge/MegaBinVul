#include <stdbool.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>

typedef void (*GDestroyNotify)(void*);

typedef struct _User {
    uid_t uid;
    void *daemon;
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

static bool get_caller_uid(GDBusMethodInvocation *context, int *uid) {
    *uid = getuid();
    return true;
}

static void throw_error(GDBusMethodInvocation *context, ErrorType error, const char *message) {
    // Empty implementation
}

static void daemon_local_check_auth(void *daemon, User *user, const char *action_id, bool allow_interaction,
                                  void (*callback)(User*, GDBusMethodInvocation*, void*),
                                  GDBusMethodInvocation *context, void *user_data, GDestroyNotify destroy_notify) {
    if (callback) {
        callback(user, context, user_data);
    }
    if (destroy_notify) {
        destroy_notify(user_data);
    }
}

static void user_change_x_session_authorized_cb(User *user, GDBusMethodInvocation *context, void *user_data) {
    // Empty implementation
}

static char *g_strdup(const char *str) {
    return strdup(str);
}

static void g_free(void *ptr) {
    free(ptr);
}