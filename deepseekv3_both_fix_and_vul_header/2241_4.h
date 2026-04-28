#include <sys/socket.h>
#include <sys/poll.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/syslog.h>
#include <netinet/in.h>
#include <linux/netlink.h>
#include <linux/connector.h>
#include <linux/hyperv.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

struct sockaddr_nl addr;
char kvp_send_buffer[1024];
char kvp_recv_buffer[1024];
int in_hand_shake;
char *lic_version;
char os_build[64];
char os_name[64];
char os_major[64];
char os_minor[64];
char os_version[64];
char processor_arch[64];

#define KVP_INDEX_FQDN 0
#define KVP_INDEX_ISV 1
#define KVP_INDEX_IPV4 2
#define KVP_INDEX_IPV6 3
#define KVP_INDEX_OSBUILD 4
#define KVP_INDEX_OSNAME 5
#define KVP_INDEX_OSMAJOR 6
#define KVP_INDEX_OSMINOR 7
#define KVP_INDEX_OSVERSION 8
#define KVP_INDEX_ARCH 9

#define CN_KVP_IDX 0x9
#define CN_KVP_VAL 0x1

/* KVP operation types */
#define KVP_OP_REGISTER1 1
#define KVP_OP_SET 2
#define KVP_OP_GET 3
#define KVP_OP_DELETE 4
#define KVP_OP_ENUMERATE 5
#define KVP_OP_GET_IP_INFO 6
#define KVP_OP_SET_IP_INFO 7

/* KVP pool types */
#define KVP_POOL_AUTO 0
#define KVP_POOL_EXTERNAL 1
#define KVP_POOL_GUEST 2

/* KVP status codes */
#define HV_S_OK 0
#define HV_S_CONT 1
#define HV_E_FAIL 2
#define HV_GUID_NOTFOUND 3

/* KVP index names */
#define FullyQualifiedDomainName KVP_INDEX_FQDN
#define IntegrationServicesVersion KVP_INDEX_ISV
#define NetworkAddressIPv4 KVP_INDEX_IPV4
#define NetworkAddressIPv6 KVP_INDEX_IPV6
#define OSBuildNumber KVP_INDEX_OSBUILD
#define OSName KVP_INDEX_OSNAME
#define OSMajorVersion KVP_INDEX_OSMAJOR
#define OSMinorVersion KVP_INDEX_OSMINOR
#define OSVersion KVP_INDEX_OSVERSION
#define ProcessorArchitecture KVP_INDEX_ARCH