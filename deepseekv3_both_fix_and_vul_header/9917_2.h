#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

typedef struct {
    pthread_mutex_t lock;
} CRITICAL_SECTION;

void InitializeCriticalSection(CRITICAL_SECTION*);
void* CreateEvent(void*, bool, bool, void*);

CRITICAL_SECTION handle_section;
CRITICAL_SECTION allocator_section;
CRITICAL_SECTION finalizer_mutex;
CRITICAL_SECTION reference_queue_mutex;

void* finalizer_event;
void* pending_done_event;
void* shutdown_event;
void* gc_thread;

bool gc_disabled;

struct {
    void* entries;
} gc_handles[2];

#define HANDLE_NORMAL 0
#define HANDLE_PINNED 1

#define MONO_GC_REGISTER_ROOT_FIXED(x)
#define MONO_SEM_INIT(x, y)
#define MONO_HAS_SEMAPHORES
#define g_assert_not_reached() abort()
#define TRUE true
#define FALSE false

void mono_gc_base_init(void);
int mono_gc_is_disabled(void);
void* mono_thread_create_internal(void*, void*, void*, bool);
void* mono_domain_get(void);
void ves_icall_System_Threading_Thread_SetName_internal(void*, void*);
void* mono_string_new(void*, const char*);
void* finalizer_thread(void*);