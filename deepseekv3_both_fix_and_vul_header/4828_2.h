#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

struct pool {
    char *sockaddr_url;
    char *stratum_port;
    char *stratum_url;
    int pool_no;
    void *stratum_lock;
};

typedef struct json_t {
    int type;
    void *data;
} json_t;

extern json_t *json_array_get(json_t *json, size_t index);
extern char *json_string_value(json_t *json);
extern void applog(int priority, const char *format, ...);
extern bool extract_sockaddr(char *address, char **sockaddr_url, char **stratum_port);
extern void clear_pool_work(struct pool *pool);
extern void __suspend_stratum(struct pool *pool);
extern bool restart_stratum(struct pool *pool);
extern void pool_failed(struct pool *pool);
extern void mutex_lock(void *lock);
extern void mutex_unlock(void *lock);