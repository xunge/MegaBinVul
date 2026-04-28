#include <stdbool.h>
#include <sys/types.h>
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
typedef void (*GCallback)(void);

static gboolean get_caller_uid(GDBusMethodInvocation *context, int *uid) {
    return FALSE;
}

static void throw_error(GDBusMethodInvocation *context, ErrorType error, const gchar *message) {
}

static void daemon_local_check_auth(void* daemon, User *user, const gchar *action_id, 
                                  gboolean allow_interaction, GCallback callback, 
                                  GDBusMethodInvocation *context, void* user_data, 
                                  GDestroyNotify destroy_notify) {
}

static void user_change_email_authorized_cb(void *user, void *context, void *user_data) {
}

static char* g_strdup(const char* str) {
    return strdup(str);
}

static void g_free(void* ptr) {
    free(ptr);
}