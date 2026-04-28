#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct NBDClient NBDClient;
typedef struct NBDExport NBDExport;
typedef struct QIOChannelSocket QIOChannelSocket;
typedef struct QCryptoTLSCreds QCryptoTLSCreds;
typedef struct NBDClientNewData NBDClientNewData;
typedef struct QIOChannel QIOChannel;
typedef struct Object Object;

struct NBDClient {
    int refcount;
    NBDExport *exp;
    QCryptoTLSCreds *tlscreds;
    char *tlsaclname;
    QIOChannelSocket *sioc;
    QIOChannel *ioc;
    bool can_read;
    void (*close)(NBDClient *);
};

struct NBDClientNewData {
    NBDClient *client;
    void *co;
};

#define g_new(type, n) ((type *)malloc(sizeof(type) * (n)))
#define g_malloc0(size) calloc(1, size)
#define g_strdup(str) strdup(str)
#define OBJECT(obj) ((Object *)(obj))
#define QIO_CHANNEL(obj) ((QIOChannel *)(obj))

void object_ref(Object *obj);
void *qemu_coroutine_create(void (*entry)(void *), void *opaque);
void qemu_coroutine_enter(void *co);
void nbd_co_client_start(void *opaque);