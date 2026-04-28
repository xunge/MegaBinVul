#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct virtio_input {
    pthread_mutex_t mtx;
    void *event_queue;
    int fd;
    char *evdev;
    char *serial;
};