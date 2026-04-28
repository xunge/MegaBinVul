#include <stdint.h>
#include <stdbool.h>

#define INFINITE 0xFFFFFFFF
#define FALSE false
#define TRUE true

typedef struct _DomainFinalizationReq DomainFinalizationReq;
typedef void* gpointer;
typedef uint32_t guint32;

struct GSList {
    void* data;
    struct GSList* next;
};

extern int finished;
extern struct GSList* domains_to_finalize;
extern void* finalizer_event;
extern void* pending_done_event;
extern void* shutdown_event;
#ifdef MONO_HAS_SEMAPHORES
extern void* finalizer_sem;
#endif

struct MonoDomain;
struct MonoDomain* mono_domain_get(void);
struct MonoDomain* mono_get_root_domain(void);
void mono_console_handle_async_ops(void);
void mono_attach_maybe_start(void);
void mono_finalizer_lock(void);
void mono_finalizer_unlock(void);
void finalize_domain_objects(DomainFinalizationReq* req);
void mono_gc_invoke_finalizers(void);

void g_assert(bool condition);
struct GSList* g_slist_remove(struct GSList* list, void* data);
void WaitForSingleObjectEx(void* handle, uint32_t timeout, bool alertable);
void SetEvent(void* event);