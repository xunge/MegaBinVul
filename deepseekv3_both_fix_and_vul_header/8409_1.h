#include <mutex>
#include <stddef.h>
#include <pthread.h>

struct fdevent {
    int state;
};

struct asocket {
    int id;
    int fd;
    asocket* peer;
    void (*shutdown)(asocket*);
    void (*close)(asocket*);
    int closing;
    int has_write_error;
    void* pkt_first;
    struct fdevent fde;
};

extern std::recursive_mutex local_socket_list_lock;
extern pthread_mutex_t socket_list_lock;
extern asocket* local_socket_closing_list;

#define D(...)
#define CHECK_EQ(a, b)
#define FDE_READ 0
#define FDE_WRITE 1

void local_socket_close_locked(asocket* s);
void local_socket_destroy(asocket* s);
void fdevent_del(fdevent* fde, int flags);
void remove_socket(asocket* s);
void insert_local_socket(asocket* s, asocket** list);

static inline void adb_mutex_lock(pthread_mutex_t* mutex) {
    pthread_mutex_lock(mutex);
}

static inline void adb_mutex_unlock(pthread_mutex_t* mutex) {
    pthread_mutex_unlock(mutex);
}