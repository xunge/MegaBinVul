#include <stdlib.h>

#define __exit

struct net {
    void *proc_net;
};

extern struct net init_net;

void remove_proc_subtree(const char *name, void *proc_net);