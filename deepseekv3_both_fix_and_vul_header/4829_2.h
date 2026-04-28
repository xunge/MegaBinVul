#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <syslog.h>

typedef struct json_t json_t;

struct swork {
    char *job_id;
    bool clean;
    char **merkle_bin;
};

struct pool {
    struct swork swork;
    char prev_hash[65];
    char bbversion[9];
    char nbit[9];
    char ntime[9];
    size_t coinbase_len;
    size_t n1_len;
    size_t n2size;
    size_t nonce2_offset;
    int merkles;
    unsigned char *header_bin;
    unsigned char *coinbase;
    unsigned char *nonce1bin;
    int pool_no;
    int getwork_requested;
    pthread_rwlock_t data_lock;
    int nonce2;
};

extern char blank_merkle[65];
extern char workpadding[97];
extern int opt_protocol;
extern int opt_debug;
extern int total_getworks;
extern bool opt_work_update;

extern struct pool *current_pool(void);
extern char *__json_array_string(json_t *val, int index);
extern char *json_array_string(json_t *val, int index);
extern json_t *json_array_get(json_t *val, int index);
extern bool json_is_array(json_t *val);
extern bool json_is_true(json_t *val);
extern int json_array_size(json_t *val);
extern bool hex2bin(unsigned char *p, const char *hexstr, size_t len);
extern char *bin2hex(const unsigned char *p, size_t len);
extern void align_len(size_t *len);
extern void cg_wlock(pthread_rwlock_t *lock);
extern void cg_wunlock(pthread_rwlock_t *lock);
extern void applog(int prio, const char *fmt, ...);
extern void quit(int status, const char *fmt, ...);
extern void *alloca(size_t size);
#define unlikely(x) (x)