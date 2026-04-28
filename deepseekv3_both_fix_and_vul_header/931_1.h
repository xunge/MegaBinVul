#include <sys/types.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define REDIS_VERSION "0.0.0"
#define REDIS_REPL_CONNECTED 1
#define REDIS_REPL_TRANSFER 2

typedef char *sds;

struct redisServer {
    time_t stat_starttime;
    unsigned long lruclock;
    pid_t bgsavechildpid;
    pid_t bgrewritechildpid;
    long long dirty;
    time_t lastsave;
    long long stat_numconnections;
    long long stat_numcommands;
    long long stat_expiredkeys;
    long long stat_evictedkeys;
    long long stat_keyspace_hits;
    long long stat_keyspace_misses;
    size_t hash_max_zipmap_entries;
    size_t hash_max_zipmap_value;
    int loading;
    off_t loading_total_bytes;
    off_t loading_loaded_bytes;
    time_t loading_start_time;
    int dbnum;
    struct {
        void *dict;
        void *expires;
    } *db;
    void *clients;
    void *slaves;
    int bpop_blocked_clients;
    void *pubsub_channels;
    void *pubsub_patterns;
    char *masterhost;
    int masterport;
    int replstate;
    struct {
        time_t lastinteraction;
    } *master;
    long repl_transfer_left;
    time_t repl_transfer_lastio;
    int ds_enabled;
    unsigned long long cache_max_memory;
    unsigned long cache_blocked_clients;
    int vm_enabled;
    unsigned long long vm_max_memory;
    unsigned long long vm_page_size;
    unsigned long long vm_pages;
    unsigned long long vm_stats_used_pages;
    unsigned long long vm_stats_swapped_objects;
    unsigned long long vm_stats_swapins;
    unsigned long long vm_stats_swapouts;
    void *io_newjobs;
    void *io_processing;
    void *io_processed;
    unsigned long io_active_threads;
    unsigned long vm_blocked_clients;
    int appendonly;
};

extern struct redisServer server;

sds sdsempty(void);
sds sdscatprintf(sds s, const char *fmt, ...);
char *bytesToHuman(char *s, unsigned long long n);
size_t zmalloc_used_memory(void);
size_t zmalloc_get_rss(void);
float zmalloc_get_fragmentation_ratio(void);
char *aeGetApiName(void);
char *redisGitSHA1(void);
char *redisGitDirty(void);
int listLength(void *list);
int dictSize(void *dict);
void lockThreadedIO(void);
void unlockThreadedIO(void);