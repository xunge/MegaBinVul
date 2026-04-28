#include <mutex>
#include <stddef.h>
#include <pthread.h>

struct asocket {
    unsigned id;
    asocket* peer;
    asocket* next;
};

extern std::recursive_mutex local_socket_list_lock;
extern pthread_mutex_t socket_list_lock;
extern asocket local_socket_list;

#define adb_mutex_lock pthread_mutex_lock
#define adb_mutex_unlock pthread_mutex_unlock