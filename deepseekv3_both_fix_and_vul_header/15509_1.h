#include <sys/epoll.h>
#include <cstddef>

typedef enum {
    CONTEXT_READ_OVER
} ContextStatus;

typedef struct {
    struct {
        void *ptr;
    } data;
} EventData;

typedef struct {
    void (*handle_readable_event)(EventData);
} EventSystem;

typedef struct {
    ContextStatus _ctx_status;
} EpollContext;

typedef struct {
    EventSystem *es;
    EventData event;
} TaskData;