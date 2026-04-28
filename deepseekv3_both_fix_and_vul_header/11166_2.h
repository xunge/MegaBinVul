#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct _PolkitBackendSessionMonitor PolkitBackendSessionMonitor;
typedef struct _PolkitIdentity PolkitIdentity;
typedef struct _PolkitSubject PolkitSubject;
typedef struct _GError GError;

#define POLKIT_IS_UNIX_PROCESS(subject) (0)
#define POLKIT_IS_SYSTEM_BUS_NAME(subject) (0)
#define POLKIT_IS_UNIX_SESSION(subject) (0)
#define POLKIT_UNIX_PROCESS(subject) ((void*)0)
#define POLKIT_SYSTEM_BUS_NAME(subject) ((void*)0)
#define POLKIT_UNIX_SESSION(subject) ((void*)0)
#define POLKIT_ERROR 0
#define POLKIT_ERROR_FAILED 0
#define TRUE true
#define FALSE false

typedef bool gboolean;
typedef unsigned int guint32;
typedef int gint;

static inline gint polkit_unix_process_get_uid(void* process) { return -1; }
static inline gint polkit_unix_process_get_racy_uid__(void* process, GError** error) { return -1; }
static inline PolkitIdentity* polkit_unix_user_new(uid_t uid) { return NULL; }
static inline PolkitIdentity* polkit_system_bus_name_get_user_sync(void* bus_name, void* unused, GError** error) { return NULL; }
static inline const char* polkit_unix_session_get_session_id(void* session) { return NULL; }
static inline int sd_session_get_uid(const char* session, uid_t* uid) { return -1; }
static inline void g_set_error(GError** error, int domain, int code, const char* format, ...) {}
static inline void g_propagate_error(GError** dest, GError* src) {}