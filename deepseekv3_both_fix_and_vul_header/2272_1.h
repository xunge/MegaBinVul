#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <unistd.h>

#define C_ERR 0
#define C_OK 1
#define CLUSTER_SLOTS 16384
#define CLUSTER_PORT_INCR 10000

#define CLUSTER_NODE_MYSELF (1<<0)
#define CLUSTER_NODE_MASTER (1<<1)
#define CLUSTER_NODE_SLAVE (1<<2)
#define CLUSTER_NODE_PFAIL (1<<3)
#define CLUSTER_NODE_FAIL (1<<4)
#define CLUSTER_NODE_HANDSHAKE (1<<5)
#define CLUSTER_NODE_NOADDR (1<<6)

typedef struct clusterNode {
    char *name;
    char ip[46];
    int port;
    int cport;
    int flags;
    unsigned long long configEpoch;
    struct clusterNode *slaveof;
    long long ping_sent;
    long long pong_received;
    long long fail_time;
} clusterNode;

typedef struct clusterState {
    clusterNode *myself;
    unsigned long long currentEpoch;
    unsigned long long lastVoteEpoch;
    clusterNode *migrating_slots_to[CLUSTER_SLOTS];
    clusterNode *importing_slots_from[CLUSTER_SLOTS];
} clusterState;

typedef struct serverState {
    clusterState *cluster;
} serverState;

extern serverState server;
extern clusterNode *myself;

typedef char *sds;

enum {
    LL_WARNING,
    LL_NOTICE
};

void serverLog(int level, const char *fmt, ...);
void serverAssert(int condition);
void serverPanic(const char *msg);
void exit(int status);
clusterNode *clusterLookupNode(const char *name);
clusterNode *createClusterNode(const char *name, int flags);
void clusterAddNode(clusterNode *node);
void clusterNodeAddSlave(clusterNode *master, clusterNode *slave);
void clusterAddSlot(clusterNode *node, int slot);
unsigned long long clusterGetMaxEpoch(void);
sds *sdssplitargs(const char *line, int *argc);
void sdsfreesplitres(sds *tokens, int count);
void *zmalloc(size_t size);
void zfree(void *ptr);
long long mstime(void);