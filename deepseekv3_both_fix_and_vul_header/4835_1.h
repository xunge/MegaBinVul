#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <syslog.h>
#include <pthread.h>

#define unlikely(x) __builtin_expect(!!(x), 0)

struct pool {
    struct {
        char *job_id;
        char *prev_hash;
        char *bbversion;
        char *nbit;
        char *ntime;
        bool clean;
        size_t cb_len;
        unsigned char **merkle_bin;
        int merkles;
        size_t header_len;
    } swork;
    size_t n1_len;
    size_t n2size;
    unsigned char *nonce1bin;
    unsigned char *coinbase;
    unsigned char *header_bin;
    size_t merkle_offset;
    size_t nonce2_offset;
    int getwork_requested;
    pthread_mutex_t data_lock;
    int nonce2;
};

extern struct pool *current_pool(void);
extern void cg_wlock(pthread_mutex_t *);
extern void cg_wunlock(pthread_mutex_t *);
extern bool hex2bin(unsigned char *, const char *, size_t);
extern void quit(int, const char *);
extern void quithere(int, const char *);
extern void applog(int, const char *, ...);
extern bool opt_protocol;
extern int total_getworks;
extern bool opt_work_update;

typedef struct json_t json_t;
extern json_t *json_array_get(const json_t *, size_t);
extern bool json_is_array(const json_t *);
extern size_t json_array_size(const json_t *);
extern char *json_array_string(const json_t *, size_t);
extern bool json_is_true(const json_t *);

static char blank_merkel[65] = {0};
static char workpadding[193] = {0};

static inline void align_len(size_t *len) {
    *len = (*len + 7) & ~7;
}