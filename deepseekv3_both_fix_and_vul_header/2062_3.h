#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#define FALSE false
#define TRUE true

typedef struct _User {
    uid_t uid;
    void* daemon;
} User;

typedef struct _AccountsUser AccountsUser;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;

typedef enum {
    ERROR_FAILED
} ErrorType;

typedef bool gboolean;
typedef char gchar;
typedef void (*GDestroyNotify)(void*);

static gboolean get_caller_uid(GDBusMethodInvocation *context, int *uid) {
    return TRUE;
}

static void throw_error(GDBusMethodInvocation *context, ErrorType error, const gchar *message) {
}

static void daemon_local_check_auth(void* daemon, User *user, const gchar *action_id, gboolean allow_interaction, 
                                  void (*callback)(User*, GDBusMethodInvocation*, void*),
                                  GDBusMethodInvocation *context, void* user_data, GDestroyNotify destroy_notify) {
    callback(user, context, user_data);
}

static void user_change_location_authorized_cb(User *user, GDBusMethodInvocation *context, void* user_data) {
}

static char* g_strdup(const char* str) {
    return str ? strdup(str) : NULL;
}

static void g_free(void* ptr) {
    free(ptr);
}