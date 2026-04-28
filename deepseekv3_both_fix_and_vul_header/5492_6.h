#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <limits.h>
#include <stdint.h>

typedef struct lua_State lua_State;
typedef struct apr_socket_t apr_socket_t;
typedef int apr_status_t;
typedef size_t apr_size_t;
typedef uint64_t apr_uint64_t;
typedef off_t apr_off_t;
typedef struct apr_pool_t apr_pool_t;

struct conn_rec {
    apr_socket_t *socket;
    void *ssl;
    apr_pool_t *pool;
};

struct request_rec {
    struct conn_rec *connection;
    apr_pool_t *pool;
};

#define APR_SUCCESS 0
#define APR_SIZE_T_FMT "zu"
#define APR_OFF_T_FMT "ld"
#define APLOG_MARK __FILE__,__LINE__,0
#define APLOG_DEBUG 0
#define APLOG_TRACE1 0
#define HUGE_STRING_LEN 8192

void lua_pushlstring(lua_State *L, const char *s, size_t len);
void lua_pushboolean(lua_State *L, int b);

struct request_rec *ap_lua_check_request_rec(lua_State *L, int index);
int ap_lua_ssl_is_https(struct conn_rec *c);
apr_status_t lua_websocket_readbytes(struct conn_rec *c, char *buf, int len);
void *apr_pcalloc(apr_pool_t *pool, size_t size);
apr_socket_t *ap_get_conn_socket(struct conn_rec *c);
apr_status_t apr_socket_recv(apr_socket_t *sock, char *buf, apr_size_t *len);
apr_status_t apr_socket_send(apr_socket_t *sock, const char *buf, apr_size_t *len);
void *apr_palloc(apr_pool_t *pool, size_t size);
uint64_t ap_ntoh64(const void *buf);
void ap_log_rerror(const char *file, int line, int module_index, int level, 
                  int status, const struct request_rec *r, const char *fmt, ...);

typedef struct request_rec request_rec;
typedef struct conn_rec conn_rec;