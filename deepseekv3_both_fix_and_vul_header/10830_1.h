#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <time.h>

#define TAIL_REPAIR_TIME_DEFAULT 0
#define LOGGER_WATCHER_BUF_SIZE 0
#define LOGGER_BUF_SIZE 0

enum protocol {
    negotiating_prot
};

struct settings {
    bool use_cas;
    int access;
    int port;
    int udpport;
    char *inter;
    size_t maxbytes;
    int maxconns;
    int verbose;
    time_t oldest_live;
    uint64_t oldest_cas;
    bool evict_to_free;
    char *socketpath;
    double factor;
    int chunk_size;
    int num_threads;
    int num_threads_per_udp;
    char prefix_delimiter;
    bool detail_enabled;
    int reqs_per_event;
    int backlog;
    enum protocol binding_protocol;
    size_t item_size_max;
    size_t slab_page_size;
    size_t slab_chunk_size_max;
    bool sasl;
    bool maxconns_fast;
    bool lru_crawler;
    int lru_crawler_sleep;
    unsigned int lru_crawler_tocrawl;
    bool lru_maintainer_thread;
    bool lru_segmented;
    int hot_lru_pct;
    int warm_lru_pct;
    double hot_max_factor;
    double warm_max_factor;
    bool inline_ascii_response;
    bool temp_lru;
    time_t temporary_ttl;
    int idle_timeout;
    unsigned int hashpower_init;
    bool slab_reassign;
    int slab_automove;
    double slab_automove_ratio;
    int slab_automove_window;
    bool shutdown_command;
    int tail_repair_time;
    bool flush_enabled;
    bool dump_enabled;
    int crawls_persleep;
    size_t logger_watcher_buf_size;
    size_t logger_buf_size;
    bool drop_privileges;
#ifdef MEMCACHED_DEBUG
    bool relaxed_privileges;
#endif
};

static struct settings settings;