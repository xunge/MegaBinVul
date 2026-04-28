#include <mutex>
#include <stdint.h>

struct asocket {
    uint32_t id;
};

extern std::recursive_mutex local_socket_list_lock;
extern uint32_t local_socket_next_id;
extern asocket* local_socket_list;

extern void insert_local_socket(asocket* s, asocket** list);
extern void fatal(const char* msg);

extern void adb_mutex_lock(void* mutex);
extern void adb_mutex_unlock(void* mutex);
extern void* socket_list_lock;