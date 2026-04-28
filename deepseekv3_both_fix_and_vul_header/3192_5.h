#include <pthread.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

#define CAP_NET_ADMIN 0
#define EPERM 1
#define EINVAL 22
#define EFAULT 14
#define ERESTARTSYS 512
#define ESRCH 3

#define IP_VS_BASE_CTL 0
#define IP_VS_SO_GET_MAX 100
#define IP_VS_SO_GET_VERSION 1
#define IP_VS_SO_GET_INFO 2
#define IP_VS_SO_GET_SERVICES 3
#define IP_VS_SO_GET_SERVICE 4
#define IP_VS_SO_GET_DESTS 5
#define IP_VS_SO_GET_TIMEOUT 6
#define IP_VS_SO_GET_DAEMON 7
#define GET_CMDID(cmd) (cmd)
#define NVERSION(ver) 0,0,0
#define IP_VS_VERSION_CODE 0
#define IP_VS_CONN_TAB_SIZE 0
#define IP_VS_IFNAME_MAXLEN 16
#define IP_VS_STATE_MASTER 1
#define IP_VS_STATE_BACKUP 2
#define AF_INET 2

static unsigned int ip_vs_num_services;
static char ip_vs_master_mcast_ifn[IP_VS_IFNAME_MAXLEN];
static char ip_vs_backup_mcast_ifn[IP_VS_IFNAME_MAXLEN];
static int ip_vs_master_syncid;
static int ip_vs_backup_syncid;
static int ip_vs_sync_state;
static pthread_mutex_t __ip_vs_mutex = PTHREAD_MUTEX_INITIALIZER;

struct sock;
#define __user
#define capable(x) 1
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)
#define copy_from_user(dst, src, len) 0
#define copy_to_user(dst, src, len) 0
#define mutex_lock_interruptible(m) 0
#define mutex_unlock(m) 
#define strlcpy strncpy

struct ip_vs_getinfo {
    int version;
    int size;
    unsigned int num_services;
};

struct ip_vs_service_entry {
    int fwmark;
    int protocol;
    unsigned int addr;
    unsigned short port;
};

struct ip_vs_get_services {
    unsigned int num_services;
};

struct ip_vs_dest_entry {
    // dummy structure
};

struct ip_vs_get_dests {
    unsigned int num_dests;
};

struct ip_vs_timeout_user {
    // dummy structure
};

struct ip_vs_daemon_user {
    int state;
    char mcast_ifn[IP_VS_IFNAME_MAXLEN];
    int syncid;
};

union nf_inet_addr {
    unsigned int ip;
};

struct ip_vs_service {
    // dummy structure
};

static int get_arglen[] = {0};

static int __ip_vs_get_service_entries(struct ip_vs_get_services *get, void *user) { return 0; }
static int __ip_vs_get_dest_entries(struct ip_vs_get_dests *get, void *user) { return 0; }
static struct ip_vs_service *__ip_vs_svc_fwm_get(int af, int fwmark) { return NULL; }
static struct ip_vs_service *__ip_vs_service_get(int af, int protocol, union nf_inet_addr *addr, unsigned short port) { return NULL; }
static void ip_vs_copy_service(struct ip_vs_service_entry *entry, struct ip_vs_service *svc) {}
static void ip_vs_service_put(struct ip_vs_service *svc) {}
static void __ip_vs_get_timeouts(struct ip_vs_timeout_user *t) {}