#include <stdint.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <time.h>

typedef struct _agooCon *agooCon;
typedef struct _agooErr *agooErr;
typedef struct _agooBind *agooBind;

struct _agooCon {
    int sock;
    uint64_t id;
    double timeout;
    agooBind bind;
    void *loop;
    pthread_mutex_t res_lock;
    char remote[INET6_ADDRSTRLEN];
};

#define AGOO_CALLOC calloc
#define AGOO_ERR_MEM(err, msg)
#define CON_TIMEOUT 30

double dtime(void) {
    return (double)clock() / CLOCKS_PER_SEC;
}