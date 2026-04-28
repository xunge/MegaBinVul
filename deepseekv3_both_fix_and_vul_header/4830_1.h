#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RBUFSIZE 1024
#define PACKAGE "unknown"
#define VERSION "0.0"
#define DEFAULT_SOCKWAIT 30
#define SEND_OK 0
#define LOG_DEBUG 0
#define LOG_INFO 1
#define LOG_ERR 2
#define opt_protocol 0

struct pool {
    char *sessionid;
    char *nonce1;
    unsigned char *nonce1bin;
    int n1_len;
    int n2size;
    char *stratum_url;
    char *sockaddr_url;
    bool stratum_active;
    double sdiff;
    int pool_no;
    void *data_lock;
};

typedef struct {
    int line;
    const char *text;
} json_error_t;

typedef void json_t;

static int swork_id = 0;

void applog(int priority, const char *fmt, ...);
bool setup_stratum_socket(struct pool *pool);
void clear_sock(struct pool *pool);
int __stratum_send(struct pool *pool, const char *s, size_t len);
bool socket_full(struct pool *pool, int wait);
char *recv_line(struct pool *pool);
char *get_sessionid(json_t *val);
char *json_array_string(json_t *val, int index);
json_t *json_array_get(json_t *val, int index);
long json_integer_value(json_t *val);
void cg_wlock(void *lock);
void cg_wunlock(void *lock);
void hex2bin(unsigned char *p, const char *hexstr, size_t len);
void quithere(int code, const char *fmt, ...);
void suspend_stratum(struct pool *pool);
json_t *JSON_LOADS(const char *input, json_error_t *error);
json_t *json_object_get(const json_t *json, const char *key);
int json_is_null(const json_t *json);
char *json_dumps(const json_t *json, int flags);
void json_decref(json_t *json);