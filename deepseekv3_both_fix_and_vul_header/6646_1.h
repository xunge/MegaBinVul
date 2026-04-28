#include <stddef.h>

struct net {
    int nsid_lock;
    void *netns_ids;
};

void rcu_read_lock(void);
void rcu_read_unlock(void);
void spin_lock_bh(int *lock);
void spin_unlock_bh(int *lock);
void *idr_find(void *idr, int id);
void get_net(struct net *net);