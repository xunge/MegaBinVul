#include <mutex>

struct atransport;
struct asocket {
    asocket* next;
    asocket* peer;
    atransport* transport;
    void (*close)(asocket* s);
};

extern std::recursive_mutex local_socket_list_lock;
extern asocket local_socket_list;
void local_socket_close(asocket* s);