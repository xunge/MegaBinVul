#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/un.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>

struct sockaddr_storage;
struct Socket {
    int getType();
};
struct String {
    size_t length() const;
    const char* data() const;
    const char* c_str() const;
};
namespace req {
    template<typename T>
    class ptr {
    public:
        T* operator->();
        operator T*() { return operator->(); }
    };
};

bool php_set_inet_addr(struct sockaddr_in*, const char*, Socket*);
bool php_set_inet6_addr(struct sockaddr_in6*, const char*, Socket*);
void raise_warning(const char*, ...);