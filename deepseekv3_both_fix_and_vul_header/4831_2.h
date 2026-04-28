#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <syslog.h>

struct pool {
    char *sockaddr_url;
    char *stratum_port;
    char *stratum_url;
    pthread_mutex_t stratum_lock;
};

extern bool opt_disable_client_reconnect;
extern void applog(int priority, const char *fmt, ...);
extern char* get_pool_name(struct pool *pool);
extern void clear_pool_work(struct pool *pool);
extern void __suspend_stratum(struct pool *pool);
extern bool restart_stratum(struct pool *pool);
extern void pool_failed(struct pool *pool);
extern bool extract_sockaddr(char *address, char **sockaddr_url, char **stratum_port);

typedef struct json_t json_t;
char *json_string_value(json_t *value);
json_t *json_array_get(json_t *array, size_t index);

#define mutex_lock pthread_mutex_lock
#define mutex_unlock pthread_mutex_unlock