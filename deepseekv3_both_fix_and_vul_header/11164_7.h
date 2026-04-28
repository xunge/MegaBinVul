#include <stdlib.h>
#include <string.h>

#define G_GNUC_UNUSED
#define gchar char
#define g_free free
#define g_strdup strdup
#define g_object_unref(ptr) ((void)0)
#define POLKIT_BACKEND_AUTHORITY(authority) ((void*)authority)

typedef struct _PolkitBackendInteractiveAuthorityPrivate PolkitBackendInteractiveAuthorityPrivate;
typedef struct _PolkitSubject PolkitSubject;
typedef struct _PolkitIdentity PolkitIdentity;
typedef struct _PolkitAuthorizationResult PolkitAuthorizationResult;
typedef struct _PolkitBackendInteractiveAuthority PolkitBackendInteractiveAuthority;
typedef struct _PolkitBackendSessionMonitor PolkitBackendSessionMonitor;

struct _PolkitBackendInteractiveAuthorityPrivate {
    PolkitBackendSessionMonitor *session_monitor;
};

#define POLKIT_BACKEND_INTERACTIVE_AUTHORITY_GET_PRIVATE(obj) \
    ((PolkitBackendInteractiveAuthorityPrivate*)malloc(sizeof(PolkitBackendInteractiveAuthorityPrivate)))

char* polkit_subject_to_string(PolkitSubject* subject);
char* polkit_identity_to_string(PolkitIdentity* identity);
int polkit_authorization_result_get_is_authorized(PolkitAuthorizationResult* result);
PolkitIdentity* polkit_backend_session_monitor_get_user_for_subject_4arg(PolkitBackendSessionMonitor* monitor, 
                                                                        PolkitSubject* subject, 
                                                                        void* unused1, 
                                                                        void* unused2);
PolkitIdentity* polkit_backend_session_monitor_get_user_for_subject_3arg(PolkitBackendSessionMonitor* monitor,
                                                                       PolkitSubject* subject,
                                                                       void* unused1);
void polkit_backend_authority_log(void* authority, const char* format, ...);
char* _polkit_subject_get_cmdline(PolkitSubject* subject);