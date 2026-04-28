#include <pthread.h>

#define __user
#define CAP_NET_ADMIN 0
#define EPERM 1
#define EFAULT 2
#define EINVAL 3
#define EBT_SO_GET_INFO 4
#define EBT_SO_GET_INIT_INFO 5
#define EBT_SO_GET_ENTRIES 6
#define EBT_SO_GET_INIT_ENTRIES 7

struct ebt_replace {
    char name[32];
    unsigned int nentries;
    unsigned int entries_size;
    unsigned int valid_hooks;
};

struct ebt_table_private {
    unsigned int nentries;
    unsigned int entries_size;
};

struct ebt_table_info {
    unsigned int nentries;
    unsigned int entries_size;
    unsigned int valid_hooks;
};

struct ebt_table {
    struct ebt_table_private *private;
    struct ebt_table_info *table;
    unsigned int valid_hooks;
};

struct net;
struct sock;

#define BUGPRINT(fmt) 

extern int capable(int cap);
extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern struct net *sock_net(struct sock *sk);
extern void mutex_unlock(pthread_mutex_t *mutex);
extern pthread_mutex_t ebt_mutex;
extern struct ebt_table *find_table_lock(struct net *net, const char *name, int *error, pthread_mutex_t *mutex);
extern int copy_everything_to_user(struct ebt_table *t, void *user, int *len, int cmd);