#include <mutex>
#include <pthread.h>

struct asocket;
struct atransport;

extern std::recursive_mutex local_socket_list_lock;
extern asocket local_socket_list;

void local_socket_close(asocket* s);
void local_socket_close_locked(asocket* s);

struct asocket {
    asocket* next;
    asocket* peer;
    atransport* transport;
};

extern asocket local_socket_list;
extern pthread_mutex_t socket_list_lock;

#define adb_mutex_lock pthread_mutex_lock
#define adb_mutex_unlock pthread_mutex_unlock