#include <pthread.h>
#include <sys/socket.h>
#include <unistd.h>
#include <stdlib.h>

extern int netlink_socket;
extern pthread_barrier_t notify_barrier;
extern void *(*notification_function)(void *);

#define NOTIFY_COOKIE_LEN 16
#define NOTIFY_WOKENUP 0
#define NOTIFY_REMOVED 1

union notify_data {
    char raw[NOTIFY_COOKIE_LEN];
    pthread_attr_t *attr;
};

ssize_t __recv(int sockfd, void *buf, size_t len, int flags);
int __pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void *), void *arg);
int __pthread_barrier_wait(pthread_barrier_t *barrier);
int __pthread_attr_destroy(pthread_attr_t *attr);