#include <sys/socket.h>
#include <pthread.h>
#include <string.h>
#include <assert.h>

enum try_read_result {
    READ_DATA_RECEIVED,
    READ_NO_DATA_RECEIVED
};

struct stats {
    pthread_mutex_t mutex;
    size_t bytes_read;
};

struct thread {
    struct stats stats;
};

typedef struct conn {
    int sfd;
    char *rbuf;
    size_t rsize;
    size_t rbytes;
    char *rcurr;
    struct sockaddr_storage request_addr;
    socklen_t request_addr_size;
    unsigned short request_id;
    struct thread *thread;
} conn;