#include <stddef.h>
#include <stdbool.h>

#define TRUE true
#define NULL ((void*)0)

typedef struct _GFBGraphPhotoPrivate {
    char *source;
} GFBGraphPhotoPrivate;

typedef struct _GFBGraphPhoto GFBGraphPhoto;
typedef struct _GFBGraphAuthorizer GFBGraphAuthorizer;
typedef struct _GError GError;
typedef void GInputStream;
typedef void SoupSession;
typedef void SoupRequester;
typedef void SoupRequest;
typedef void SoupMessage;
typedef void (*GWeakNotify)(void*, void*);

#define GFBGRAPH_IS_PHOTO(obj) (1)
#define GFBGRAPH_IS_AUTHORIZER(obj) (1)
#define GFBGRAPH_PHOTO_GET_PRIVATE(obj) ((GFBGraphPhotoPrivate*)0)
#define G_OBJECT(obj) ((void*)obj)
#define SOUP_SESSION_FEATURE(obj) ((void*)obj)
#define SOUP_REQUEST_HTTP(obj) ((void*)obj)

static inline void* g_return_val_if_fail(int expr, void* val) { if (!expr) return val; return NULL; }
static inline SoupSession* soup_session_sync_new(void) { return NULL; }
static inline SoupRequester* soup_requester_new(void) { return NULL; }
static inline void soup_session_add_feature(SoupSession* s, void* f) {}
static inline SoupRequest* soup_requester_request(SoupRequester* r, char* s, GError** e) { return NULL; }
static inline SoupMessage* soup_request_http_get_message(void* r) { return NULL; }
static inline GInputStream* soup_request_send(SoupRequest* r, void* n, GError** e) { return NULL; }
static inline void g_object_weak_ref(void* o, GWeakNotify n, void* d) {}
static inline void g_object_unref(void* o) {}
static inline void g_clear_object(void** o) {}
static inline void g_object_set(void* o, const char* p, bool v, void* n) {}