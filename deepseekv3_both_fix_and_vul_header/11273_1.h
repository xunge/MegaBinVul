#include <stddef.h>
#include <sys/queue.h>

typedef struct NBDExport NBDExport;
typedef struct NBDClient NBDClient;
typedef struct QIOChannel QIOChannel;

struct NBDClient {
    QIOChannel *ioc;
    TAILQ_ENTRY(NBDClient) next;
};

struct NBDExport {
    const char *name;
    void *ctx;
    TAILQ_HEAD(client_head, NBDClient) clients;
};

#define QTAILQ_FOREACH(var, head, field) TAILQ_FOREACH(var, head, field)
#define TRACE(fmt, ...)