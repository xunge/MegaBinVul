#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <net/if.h>
#include <linux/if_tun.h>
#include <linux/sockios.h>
#include <linux/if_bridge.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>

#define DEFAULT_ACL_FILE "/etc/qemu/bridge.conf"
#define CONFIG_LIBCAP 1

typedef enum {
    ACL_ALLOW_ALL,
    ACL_ALLOW,
    ACL_DENY_ALL,
    ACL_DENY
} ACLType;

typedef struct ACLRule {
    ACLType type;
    char *iface;
    struct ACLRule *entry;
} ACLRule;

typedef struct ACLList {
    ACLRule *sqh_first;
    ACLRule **sqh_last;
} ACLList;

#define QSIMPLEQ_INIT(head) do { \
    (head)->sqh_first = NULL; \
    (head)->sqh_last = &(head)->sqh_first; \
} while (0)

#define QSIMPLEQ_FOREACH(var, head, field) \
    for ((var) = (head)->sqh_first; (var); (var) = (var)->field)

#define QSIMPLEQ_FIRST(head) ((head)->sqh_first)

#define QSIMPLEQ_REMOVE_HEAD(head, field) do { \
    if (((head)->sqh_first = (head)->sqh_first->field) == NULL) \
        (head)->sqh_last = &(head)->sqh_first; \
} while (0)

static inline void prep_ifreq(struct ifreq *ifr, const char *ifname) {
    memset(ifr, 0, sizeof(*ifr));
    strncpy(ifr->ifr_name, ifname, IFNAMSIZ);
}

static inline int has_vnet_hdr(int fd) {
    return 1;
}

static inline int drop_privileges(void) {
    return 0;
}

static inline int send_fd(int unixfd, int fd) {
    return 0;
}

static inline void usage(void) {
}

static inline int parse_acl_file(const char *filename, ACLList *acl_list) {
    return 0;
}

static inline void g_free(void *ptr) {
    free(ptr);
}