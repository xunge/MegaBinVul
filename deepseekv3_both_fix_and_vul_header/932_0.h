#include <stdlib.h>
#include <string.h>
#include <syslog.h>
#include <time.h>

#define REDIS_SERVERPORT 6379
#define REDIS_DEFAULT_DBNUM 16
#define REDIS_VERBOSE 0
#define REDIS_MAXIDLETIME 0
#define REDIS_HASH_MAX_ZIPMAP_ENTRIES 512
#define REDIS_HASH_MAX_ZIPMAP_VALUE 64
#define REDIS_LIST_MAX_ZIPLIST_ENTRIES 512
#define REDIS_LIST_MAX_ZIPLIST_VALUE 64
#define REDIS_SET_MAX_INTSET_ENTRIES 512
#define REDIS_MAXMEMORY_VOLATILE_LRU 0
#define REDIS_REPL_NONE 0
#define APPENDFSYNC_EVERYSEC 0

struct redisServer {
    int port;
    char *bindaddr;
    char *unixsocket;
    int ipfd;
    int sofd;
    int dbnum;
    int verbosity;
    int maxidletime;
    void *saveparams;
    int loading;
    char *logfile;
    int syslog_enabled;
    char *syslog_ident;
    int syslog_facility;
    int glueoutputbuf;
    int daemonize;
    int appendonly;
    int appendfsync;
    int no_appendfsync_on_rewrite;
    time_t lastfsync;
    int appendfd;
    int appendseldb;
    char *pidfile;
    char *dbfilename;
    char *appendfilename;
    char *requirepass;
    int rdbcompression;
    int activerehashing;
    int maxclients;
    int bpop_blocked_clients;
    long long maxmemory;
    int maxmemory_policy;
    int maxmemory_samples;
    int ds_enabled;
    char *ds_path;
    long long cache_max_memory;
    int cache_blocked_clients;
    int hash_max_zipmap_entries;
    int hash_max_zipmap_value;
    int list_max_ziplist_entries;
    int list_max_ziplist_value;
    int set_max_intset_entries;
    int shutdown_asap;
    int isslave;
    char *masterauth;
    char *masterhost;
    int masterport;
    void *master;
    int replstate;
    int repl_serve_stale_data;
    int vm_enabled;
    char *vm_swap_file;
    int vm_page_size;
    long vm_pages;
    long long vm_max_memory;
    int vm_max_threads;
    int vm_blocked_clients;
    void *commands;
    void *delCommand;
    void *multiCommand;
};

struct redisServer server;

double R_Zero;
double R_PosInf;
double R_NegInf;
double R_Nan;

struct dictType {
    void *dummy;
};

struct dictType commandTableDictType;

char *zstrdup(const char *s) {
    return strdup(s);
}

void updateLRUClock() {}
void resetServerSaveParams() {}
void appendServerSaveParams(int a, int b) {}
void *dictCreate(struct dictType *type, void *privdata) { return NULL; }
void populateCommandTable() {}
void *lookupCommandByCString(const char *s) { return NULL; }