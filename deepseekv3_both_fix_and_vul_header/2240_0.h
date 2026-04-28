#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <linux/netlink.h>
#include <linux/connector.h>
#include <linux/hyperv.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <syslog.h>
#include <errno.h>

struct sockaddr_nl addr;
char *lic_version;
char *os_build;
char *os_name;
char *os_major;
char *os_minor;
char *processor_arch;
char kvp_send_buffer[1024];
char kvp_recv_buffer[1024];

enum {
    FullyQualifiedDomainName,
    IntegrationServicesVersion,
    NetworkAddressIPv4,
    NetworkAddressIPv6,
    OSBuildNumber,
    OSName,
    OSMajorVersion,
    OSMinorVersion,
    OSVersion,
    ProcessorArchitecture
};

int kvp_get_os_info(void);
int kvp_file_init(void);
int netlink_send(int fd, struct cn_msg *msg);
int kvp_key_add_or_modify(int pool, char *key, int key_size, char *value, int value_size);
int kvp_get_value(int pool, char *key, int key_size, char *value, int value_size);
int kvp_key_delete(int pool, char *key, int key_size);
int kvp_pool_enumerate(int pool, int index, char *key, int key_size, char *value, int value_size);
void kvp_get_domain_name(char *buffer, int length);
void kvp_get_ip_address(int family, char *buffer, int length);