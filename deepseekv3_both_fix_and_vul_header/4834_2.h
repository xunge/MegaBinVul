#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RBUFSIZE 1024
#define PACKAGE "unknown"
#define VERSION "unknown"
#define DEFAULT_SOCKWAIT 30
#define SEND_OK 0
#define LOG_DEBUG 0
#define LOG_INFO 1

typedef void* json_t;
typedef struct {
    int line;
    const char *text;
} json_error_t;

struct pool {
    char *sessionid;
    char *nonce1;
    unsigned char *nonce1bin;
    int n1_len;
    int n2size;
    char *stratum_url;
    char *sockaddr_url;
    bool stratum_active;
    struct {
        int diff;
    } swork;
    void *data_lock;
};

extern int swork_id;
extern bool opt_protocol;

#define JSON_LOADS(str, error) NULL
#define JSON_INDENT(indent) 0
#define unlikely(expr) (expr)

void applog(int priority, const char *format, ...);
char *get_pool_name(struct pool *pool);
bool setup_stratum_socket(struct pool *pool);
void clear_sock(struct pool *pool);
int __stratum_send(struct pool *pool, const char *s, size_t len);
bool socket_full(struct pool *pool, int timeout);
char *recv_line(struct pool *pool);
char *get_sessionid(json_t *val);
char *json_array_string(json_t *val, int index);
json_t *json_array_get(json_t *val, int index);
long long json_integer_value(json_t *val);
json_t *json_object_get(json_t *object, const char *key);
int json_is_null(json_t *json);
char *json_dumps(json_t *json, int flags);
void json_decref(json_t *json);
void hex2bin(unsigned char *out, const char *in, size_t len);
void quithere(int code, const char *format, ...);
void suspend_stratum(struct pool *pool);
void cg_wlock(void *lock);
void cg_wunlock(void *lock);