#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <stddef.h>
#include <pthread.h>

struct NBDClient;
struct QIOChannel;
struct QEMUCoroutine;

typedef struct NBDRequestData {
    struct NBDClient *client;
    void *data;
} NBDRequestData;

typedef struct NBDClient {
    struct QIOChannel *ioc;
    pthread_mutex_t send_lock;
    struct QEMUCoroutine *send_coroutine;
} NBDClient;

typedef struct NBDReply {
    // reply fields would be defined here
} NBDReply;

#define EIO 5