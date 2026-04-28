#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>

#define CONFIG_BINDADDR_MAX 16
#define CONFIG_MIN_HZ 1
#define CONFIG_MAX_HZ 500
#define CONFIG_AUTHPASS_MAX_LEN 512
#define AOF_ON 1
#define AOF_OFF 0
#define REPL_STATE_CONNECT 1
#define LL_WARNING 1
#define INT_MIN (-2147483647-1)
#define DICT_OK 0
#define CLIENT_TYPE_MASTER 0

typedef char *sds;

struct redisServer {
    int maxidletime;
    int tcpkeepalive;
    int protected_mode;
    int port;
    int tcp_backlog;
    char *bindaddr[CONFIG_BINDADDR_MAX];
    int bindaddr_count;
    char *unixsocket;
    mode_t unixsocketperm;
    int verbosity;
    char *logfile;
    int syslog_enabled;
    char *syslog_ident;
    int syslog_facility;
    int dbnum;
    int maxclients;
    long long maxmemory;
    int maxmemory_policy;
    int maxmemory_samples;
    int lfu_log_factor;
    int lfu_decay_time;
    char *masterhost;
    int masterport;
    int repl_state;
    int repl_ping_slave_period;
    int repl_timeout;
    int repl_disable_tcp_nodelay;
    int repl_diskless_sync;
    int repl_diskless_sync_delay;
    int repl_backlog_time_limit;
    char *masterauth;
    int repl_serve_stale_data;
    int repl_slave_ro;
    int rdb_compression;
    int rdb_checksum;
    int activerehashing;
    int lazyfree_lazy_eviction;
    int lazyfree_lazy_expire;
    int lazyfree_lazy_server_del;
    int repl_slave_lazy_flush;
    int daemonize;
    int hz;
    int aof_state;
    char *aof_filename;
    int aof_no_fsync_on_rewrite;
    int aof_fsync;
    int aof_rewrite_perc;
    long long aof_rewrite_min_size;
    int aof_rewrite_incremental_fsync;
    int aof_load_truncated;
    int aof_use_rdb_preamble;
    char *requirepass;
    char *pidfile;
    char *rdb_filename;
    long hash_max_ziplist_entries;
    long hash_max_ziplist_value;
    int list_max_ziplist_size;
    int list_compress_depth;
    long set_max_intset_entries;
    long zset_max_ziplist_entries;
    long zset_max_ziplist_value;
    long hll_sparse_max_bytes;
    int cluster_enabled;
    char *cluster_configfile;
    char *cluster_announce_ip;
    int cluster_announce_port;
    int cluster_announce_bus_port;
    int cluster_require_full_coverage;
    long long cluster_node_timeout;
    int cluster_migration_barrier;
    int cluster_slave_validity_factor;
    long long lua_time_limit;
    long long slowlog_log_slower_than;
    long long latency_monitor_threshold;
    long long slowlog_max_len;
    struct {
        unsigned long long hard_limit_bytes;
        unsigned long long soft_limit_bytes;
        int soft_limit_seconds;
    } client_obuf_limits[10];
    int stop_writes_on_bgsave_err;
    int slave_priority;
    char *slave_announce_ip;
    int slave_announce_port;
    int repl_min_slaves_to_write;
    int repl_min_slaves_max_lag;
    int notify_keyspace_events;
    int supervised_mode;
    int sentinel_mode;
    void *commands;
};

struct redisCommand {
    char *name;
};

struct dict {
    void *privdata;
    int (*keyCompare)(void *privdata, const void *key1, const void *key2);
    unsigned int (*keyHash)(const void *key);
    void *(*keyDup)(void *privdata, const void *key);
    void *(*valDup)(void *privdata, const void *obj);
    void (*keyDestructor)(void *privdata, void *key);
    void (*valDestructor)(void *privdata, void *obj);
    int rehashidx;
    int iterators;
    void *table[2];
};

extern struct redisServer server;

sds *sdssplitlen(const char *s, int len, const char *sep, int seplen, int *count);
sds sdstrim(sds s, const char *cset);
sds *sdssplitargs(const char *line, int *argc);
void sdsfreesplitres(sds *tokens, int count);
void sdstolower(sds s);
int yesnotoi(char *s);
int configEnumGetValue(void *enum_obj, char *name);
void serverLog(int level, const char *fmt, ...);
void zfree(void *ptr);
void *zstrdup(const char *s);
long long memtoll(const char *p, int *err);
void appendServerSaveParams(int seconds, int changes);
void resetServerSaveParams();
int pathIsBaseName(char *path);
int getClientTypeByName(char *name);
int keyspaceEventsStringToFlags(char *classes);
void queueLoadModule(char *path, char **argv, int argc);
char *sentinelHandleConfiguration(char **argv, int argc);
void loadServerConfig(char *filename, char *options);
void resizeReplicationBacklog(long long size);
struct redisCommand *lookupCommand(char *name);
int dictDelete(struct dict *d, const void *key);
int dictAdd(struct dict *d, void *key, void *val);
void serverAssert(int condition);
sds sdsnew(const char *init);
size_t sdslen(const sds s);
sds sdsdup(const sds s);
void sdsfree(sds s);
sds sdsempty(void);
sds sdscatprintf(sds s, const char *fmt, ...);

static struct {
    const char *name;
    int val;
} loglevel_enum[] = {
    {"debug", 0},
    {"verbose", 1},
    {"notice", 2},
    {"warning", 3},
    {NULL, 0}
};

static struct {
    const char *name;
    int val;
} syslog_facility_enum[] = {
    {"user", 0},
    {"local0", 16},
    {"local1", 17},
    {"local2", 18},
    {"local3", 19},
    {"local4", 20},
    {"local5", 21},
    {"local6", 22},
    {"local7", 23},
    {NULL, 0}
};

static struct {
    const char *name;
    int val;
} maxmemory_policy_enum[] = {
    {"volatile-lru", 0},
    {"allkeys-lru", 1},
    {"volatile-random", 2},
    {"allkeys-random", 3},
    {"volatile-ttl", 4},
    {"noeviction", 5},
    {NULL, 0}
};

static struct {
    const char *name;
    int val;
} aof_fsync_enum[] = {
    {"no", 0},
    {"always", 1},
    {"everysec", 2},
    {NULL, 0}
};

static struct {
    const char *name;
    int val;
} supervised_mode_enum[] = {
    {"no", 0},
    {"upstart", 1},
    {"systemd", 2},
    {"auto", 3},
    {NULL, 0}
};