#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>
#include <assert.h>

typedef struct token_t {
    char *value;
    size_t length;
} token_t;

typedef struct item {
    unsigned int it_flags;
    size_t nkey;
    size_t nbytes;
    size_t nsuffix;
    char *data;
} item;

typedef struct conn {
    int sfd;
    item **ilist;
    int isize;
    item **icurr;
    int ileft;
    char **suffixlist;
    int suffixsize;
    char **suffixcurr;
    int suffixleft;
    struct thread_data *thread;
    int transport;
    int msgcurr;
} conn;

typedef struct slab_stats {
    int get_hits;
} slab_stats;

typedef struct thread_stats {
    pthread_mutex_t mutex;
    slab_stats *slab_stats;
    int get_cmds;
    int get_misses;
} thread_stats;

typedef struct thread_data {
    thread_stats stats;
    void *suffix_cache;
} thread_data;

typedef struct settings {
    bool detail_enabled;
    bool inline_ascii_response;
    int verbose;
} settings_t;

typedef struct stats {
    int malloc_fails;
} stats_t;

#define KEY_TOKEN 1
#define KEY_MAX_LENGTH 250
#define MAX_TOKENS 10
#define DO_UPDATE 1
#define ITEM_CHUNKED 1
#define ITEM_key(it) ((it)->data)
#define ITEM_get_cas(it) 0
#define ITEM_suffix(it) ((it)->data + (it)->nkey)
#define ITEM_data(it) ((it)->data + (it)->nkey + (it)->nsuffix)
#define ITEM_clsid(it) 0
#define MEMCACHED_COMMAND_GET(sfd, key, nkey, nbytes, cas)
#define IS_UDP(transport) 0

extern settings_t settings;
extern stats_t stats;
extern void STATS_LOCK();
extern void STATS_UNLOCK();

extern void out_string(conn *c, const char *str);
extern void item_remove(item *it);
extern item *item_get(const char *key, size_t nkey, conn *c, int do_update);
extern void stats_prefix_record_get(const char *key, size_t nkey, bool found);
extern char *do_cache_alloc(void *cache);
extern int make_ascii_get_suffix(char *suffix, item *it, bool return_cas);
extern int add_iov(conn *c, const void *buf, int len);
extern int add_chunked_item_iovs(conn *c, item *it, int bytes);
extern void out_of_memory(conn *c, const char *str);
extern size_t tokenize_command(char *command, token_t *tokens, const size_t max_tokens);
extern int build_udp_headers(conn *c);
extern void conn_set_state(conn *c, int state);

enum conn_states {
    conn_mwrite
};