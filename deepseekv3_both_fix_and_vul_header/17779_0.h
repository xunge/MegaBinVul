#include <pthread.h>

typedef struct _rfbClient rfbClient;
typedef struct _rfbClientIterator rfbClientIterator;
typedef rfbClient* rfbClientPtr;
typedef rfbClientIterator* rfbClientIteratorPtr;

struct _rfbClient {
    int sock;
    rfbClient* next;
};

struct _rfbClientIterator {
    rfbClient* next;
    int closedToo;
    struct _rfbScreenInfo* screen;
};

struct _rfbScreenInfo {
    rfbClient* clientHead;
};

extern pthread_mutex_t rfbClientListMutex;

#define LOCK(mutex) pthread_mutex_lock(&(mutex))
#define UNLOCK(mutex) pthread_mutex_unlock(&(mutex))

void rfbDecrClientRef(rfbClient* cl);
void rfbIncrClientRef(rfbClient* cl);