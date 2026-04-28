#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

struct sockaddr_ec {
    unsigned short sec_family;
    struct {
        unsigned char station;
        unsigned char net;
    } addr;
};

struct ec_device {
    unsigned char station;
    unsigned char net;
    struct ec_device *ec_ptr;
};

struct net_device {
    struct ec_device *ec_ptr;
    char name[IFNAMSIZ];
};

struct socket;

#define __user
#define GFP_KERNEL 0
#define CAP_NET_ADMIN 0
#define capable(x) (1)
#define kzalloc(size, flags) malloc(size)
#define dev_put(dev) 
#define mutex_lock(lock) pthread_mutex_lock(lock)
#define mutex_unlock(lock) pthread_mutex_unlock(lock)
#define copy_from_user(to, from, size) (0)
#define copy_to_user(to, from, size) (0)
#define dev_get_by_name(net, name) NULL

static struct net_device *net2dev_map[256];
static pthread_mutex_t econet_mutex = PTHREAD_MUTEX_INITIALIZER;