#include <stddef.h>
#include <stdint.h>
#include <linux/capability.h>
#include <linux/errno.h>
#include <linux/sched.h>
#include <linux/socket.h>
#include <linux/in.h>

#define MAX_ARG_LEN 256
#define SET_CMDID(cmd) (cmd - IP_VS_BASE_CTL)

#define IP_VS_BASE_CTL 64
#define IP_VS_SO_SET_MAX 87

static unsigned int set_arglen[IP_VS_SO_SET_MAX - IP_VS_BASE_CTL + 1];
static struct {
    int lock;
} __ip_vs_mutex;

#define __user
#define capable(x) (1)
#define copy_from_user(to, from, n) (0)
#define mutex_lock_interruptible(x) (0)
#define mutex_unlock(x) 
#define pr_err(fmt, ...) 
#define ntohs(x) (x)

struct ip_vs_service_user {
    int af;
    unsigned protocol;
    union {
        uint32_t ip;
    } addr;
    unsigned short port;
    unsigned fwmark;
    char sched_name[16];
};

struct ip_vs_service_user_kern {
    int af;
    unsigned protocol;
    union {
        uint32_t ip;
    } addr;
    unsigned short port;
    unsigned fwmark;
    char sched_name[16];
};

struct ip_vs_service {
    unsigned protocol;
};

struct ip_vs_dest_user {
    union {
        uint32_t ip;
    } addr;
    unsigned short port;
};

struct ip_vs_dest_user_kern {
    union {
        uint32_t ip;
    } addr;
    unsigned short port;
};

struct ip_vs_timeout_user {
    int tcp_timeout;
    int tcp_fin_timeout;
    int udp_timeout;
};

struct ip_vs_daemon_user {
    int state;
    char mcast_ifn[16];
    int syncid;
};

#define CAP_NET_ADMIN 12
#define EPERM 1
#define EINVAL 22
#define EFAULT 14
#define ESRCH 3
#define EEXIST 17
#define ERESTARTSYS 512

#define IP_VS_SO_SET_FLUSH 65
#define IP_VS_SO_SET_TIMEOUT 66
#define IP_VS_SO_SET_STARTDAEMON 67
#define IP_VS_SO_SET_STOPDAEMON 68
#define IP_VS_SO_SET_ADD 69
#define IP_VS_SO_SET_EDIT 70
#define IP_VS_SO_SET_DEL 71
#define IP_VS_SO_SET_ZERO 72
#define IP_VS_SO_SET_ADDDEST 73
#define IP_VS_SO_SET_EDITDEST 74
#define IP_VS_SO_SET_DELDEST 75

static inline void ip_vs_use_count_inc(void) {}
static inline void ip_vs_use_count_dec(void) {}
static inline int ip_vs_flush(void) { return 0; }
static inline int ip_vs_set_timeout(struct ip_vs_timeout_user *t) { return 0; }
static inline int start_sync_thread(int state, char *ifn, int syncid) { return 0; }
static inline int stop_sync_thread(int state) { return 0; }
static inline void ip_vs_copy_usvc_compat(struct ip_vs_service_user_kern *dst, 
                                        struct ip_vs_service_user *src) {}
static inline void ip_vs_copy_udest_compat(struct ip_vs_dest_user_kern *dst,
                                         struct ip_vs_dest_user *src) {}
static inline int ip_vs_zero_all(void) { return 0; }
static inline struct ip_vs_service *__ip_vs_service_get(int af, unsigned proto, 
                                                       void *addr, unsigned port) { return NULL; }
static inline struct ip_vs_service *__ip_vs_svc_fwm_get(int af, unsigned fwmark) { return NULL; }
static inline int ip_vs_add_service(struct ip_vs_service_user_kern *u, struct ip_vs_service **svc) { return 0; }
static inline int ip_vs_edit_service(struct ip_vs_service *svc, struct ip_vs_service_user_kern *u) { return 0; }
static inline int ip_vs_del_service(struct ip_vs_service *svc) { return 0; }
static inline int ip_vs_zero_service(struct ip_vs_service *svc) { return 0; }
static inline int ip_vs_add_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest) { return 0; }
static inline int ip_vs_edit_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest) { return 0; }
static inline int ip_vs_del_dest(struct ip_vs_service *svc, struct ip_vs_dest_user_kern *udest) { return 0; }
static inline void ip_vs_service_put(struct ip_vs_service *svc) {}