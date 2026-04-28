#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef bool gboolean;
typedef char gchar;
typedef void* gpointer;
typedef void (*GDestroyNotify)(void*);

#define TRUE true
#define FALSE false
#define ERROR_FAILED 0

typedef struct _User {
    uid_t uid;
    void* daemon;
} User;

typedef struct _AccountsUser AccountsUser;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;

static gboolean get_caller_uid(GDBusMethodInvocation *context, int *uid) { return FALSE; }
static void throw_error(GDBusMethodInvocation *context, int error, const gchar *message) {}
static void daemon_local_check_auth(void *daemon, 
                                   User *user, 
                                   const gchar *action_id, 
                                   gboolean allow_interaction, 
                                   void (*callback)(), 
                                   GDBusMethodInvocation *context, 
                                   gpointer data, 
                                   GDestroyNotify destroy_notify) {}
static void user_change_icon_file_authorized_cb() {}

static gchar* g_strdup(const gchar *str) {
    return str ? strdup(str) : NULL;
}

static void g_free(void *ptr) {
    free(ptr);
}