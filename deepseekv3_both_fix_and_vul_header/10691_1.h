#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>

struct Host;
struct IpAddress {
    void set(char* ip);
};

struct HostsHash {
    Host* get(u_int16_t vlan_id, IpAddress* ip);
};

struct NetworkInterface {
    Host* getHost(char *host_ip, u_int16_t vlan_id);
    bool isView();
    u_int8_t numSubInterfaces;
    NetworkInterface** subInterfaces;
    HostsHash* hosts_hash;
    HostsHash* get_hosts_hash();
};

struct host_find_info {
    char *host_to_find;
    u_int16_t vlan_id;
    Host *h;
};

void* walker_hosts;
void walker(void* data, void (*callback)(void*, void*), void* user_data);
void find_host_by_name(void* data, void* user_data);