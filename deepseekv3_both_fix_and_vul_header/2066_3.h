#include <stdbool.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

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
} ErrorCode;

typedef bool gboolean;
typedef char gchar;
typedef void (*GDestroyNotify)(void*);

static bool get_caller_uid(GDBusMethodInvocation *context, int *uid) {
    return false;
}

static void throw_error(GDBusMethodInvocation *context, ErrorCode error, const gchar *message) {
}

static void daemon_local_check_auth(void* daemon, User *user, const gchar *action_id, 
                                  bool allow_interaction, void (*callback)(), 
                                  GDBusMethodInvocation *context, void* user_data, 
                                  GDestroyNotify destroy_notify) {
}

static void user_change_language_authorized_cb(User *user, GDBusMethodInvocation *context, void* user_data) {
}

static char* g_strdup(const char* str) {
    return str ? strdup(str) : NULL;
}

static void g_free(void* ptr) {
    free(ptr);
}