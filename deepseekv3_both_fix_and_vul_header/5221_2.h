#include <sys/types.h>
#include <unistd.h>
#include <pthread.h>

typedef int gboolean;
typedef struct _GVfsBackendAdmin GVfsBackendAdmin;
typedef struct _GVfsJob GVfsJob;
typedef struct _GVfsJobDBus GVfsJobDBus;
typedef struct _GError GError;
typedef struct _GDBusMethodInvocation GDBusMethodInvocation;
typedef struct _GDBusConnection GDBusConnection;
typedef struct _GCredentials GCredentials;
typedef struct _PolkitSubject PolkitSubject;
typedef struct _PolkitAuthorizationResult PolkitAuthorizationResult;

#define G_VFS_JOB_DBUS(job) ((GVfsJobDBus*)job)
#define FALSE 0
#define TRUE 1
#define G_IO_ERROR 1
#define G_IO_ERROR_PERMISSION_DENIED 2
#define POLKIT_CHECK_AUTHORIZATION_FLAGS_ALLOW_USER_INTERACTION 1

struct _GVfsJobDBus {
    GDBusMethodInvocation *invocation;
};

struct _GVfsBackendAdmin {
    void *authority;
    pthread_mutex_t polkit_mutex;
};

GDBusConnection* g_dbus_method_invocation_get_connection(GDBusMethodInvocation*);
GCredentials* g_dbus_connection_get_peer_credentials(GDBusConnection*);
pid_t g_credentials_get_unix_pid(GCredentials*, GError**);
uid_t g_credentials_get_unix_user(GCredentials*, GError**);
void g_vfs_job_failed_from_error(GVfsJob*, GError*);
void g_error_free(GError*);
void g_mutex_lock(pthread_mutex_t*);
void g_mutex_unlock(pthread_mutex_t*);
PolkitSubject* polkit_unix_process_new_for_owner(pid_t, int, uid_t);
PolkitAuthorizationResult* polkit_authority_check_authorization_sync(void*, PolkitSubject*, const char*, void*, int, void*, GError**);
void g_object_unref(void*);
gboolean polkit_authorization_result_get_is_authorized(PolkitAuthorizationResult*);
gboolean polkit_authorization_result_get_is_challenge(PolkitAuthorizationResult*);
void g_vfs_job_failed_literal(GVfsJob*, int, int, const char*);
const char* _(const char*);