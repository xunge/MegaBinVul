#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>

typedef bool gboolean;
typedef char gchar;

struct _GError;
typedef struct _GError GError;

struct _GList {
    void *data;
    struct _GList *next;
};
typedef struct _GList GList;

struct _GObject {
    int ref_count;
};
typedef struct _GObject GObject;

struct _PolkitBackendAuthority;
typedef struct _PolkitBackendAuthority PolkitBackendAuthority;

struct _PolkitBackendInteractiveAuthority;
typedef struct _PolkitBackendInteractiveAuthority PolkitBackendInteractiveAuthority;

struct _PolkitBackendInteractiveAuthorityPrivate {
    void *session_monitor;
};
typedef struct _PolkitBackendInteractiveAuthorityPrivate PolkitBackendInteractiveAuthorityPrivate;

struct _PolkitIdentity;
typedef struct _PolkitIdentity PolkitIdentity;

struct _PolkitSubject;
typedef struct _PolkitSubject PolkitSubject;

typedef struct {
    GList *identities;
    gboolean is_authenticated;
    PolkitIdentity *authenticated_identity;
} AuthenticationSession;

#define FALSE false
#define TRUE true

#define POLKIT_BACKEND_INTERACTIVE_AUTHORITY(obj) ((PolkitBackendInteractiveAuthority*)obj)
#define POLKIT_IDENTITY(obj) ((PolkitIdentity*)obj)
#define POLKIT_BACKEND_INTERACTIVE_AUTHORITY_GET_PRIVATE(obj) ((PolkitBackendInteractiveAuthorityPrivate*)obj)

#define POLKIT_ERROR 0
#define POLKIT_ERROR_FAILED 1