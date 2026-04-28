#include <pthread.h>
#include <time.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef int gboolean;
typedef int64_t gint64;

typedef struct {
    char *repo_id;
    gint64 expire_time;
    char *email;
} TokenInfo;

typedef struct {
    void *token_cache;
    pthread_mutex_t token_cache_lock;
    void *repo_mgr;
} HttpServer;

typedef struct {
    void *headers_in;
} evhtp_request_t;

#define EVHTP_RES_BADREQ 400
#define EVHTP_RES_FORBIDDEN 403
#define EVHTP_RES_OK 200
#define TOKEN_EXPIRE_TIME 3600

static inline const char *evhtp_kv_find(void *headers, const char *key) { return NULL; }
static inline void evhtp_send_reply(evhtp_request_t *req, int code) {}
static inline void *g_hash_table_lookup(void *table, const char *key) { return NULL; }
static inline char *g_strdup(const char *str) { return str ? strdup(str) : NULL; }
static inline void *seaf_repo_manager_get_email_by_token(void *mgr, const char *repo, const char *token) { return NULL; }
static inline void g_hash_table_remove(void *table, const char *key) {}
static inline void *g_new0(size_t size, int count) { return calloc(count, size); }
#define g_new0(type, count) ((type*)calloc(count, sizeof(type)))
static inline void g_hash_table_insert(void *table, char *key, void *value) {}

extern HttpServer *seaf;