#include <stddef.h>
#include <stdio.h>

typedef struct AioContext AioContext;
typedef struct QIOChannel QIOChannel;
typedef struct Coroutine Coroutine;

typedef struct NBDClient {
    QIOChannel *ioc;
    Coroutine *recv_coroutine;
    Coroutine *send_coroutine;
    struct NBDClient *next;
} NBDClient;

typedef struct NBDExport {
    const char *name;
    AioContext *ctx;
    struct {
        NBDClient *tqh_first;
        NBDClient **tqh_last;
    } clients;
} NBDExport;

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = ((head)->tqh_first); (var); (var) = ((var)->next))
#define TRACE(fmt, ...) printf(fmt, ##__VA_ARGS__)

static inline void qio_channel_attach_aio_context(QIOChannel *ioc, AioContext *ctx) {}
static inline void aio_co_schedule(AioContext *ctx, Coroutine *co) {}