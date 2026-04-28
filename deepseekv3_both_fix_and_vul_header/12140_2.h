#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct lua_State lua_State;

typedef struct conn {
    struct LIBEVENT_THREAD *thread;
    struct resp *resp;
    int tag;
    int proxy_coro_ref;
    void *item;
    bool item_malloced;
    void *ritem;
    size_t rlbytes;
    size_t sbytes;
} conn;

typedef struct LIBEVENT_THREAD {
    struct proxy_hook *proxy_hooks;
    lua_State *L;
    struct proxy_ctx *proxy_ctx;
    struct proxy_int_stats *proxy_int_stats;
    struct {
        uint64_t proxy_conn_requests;
        uint64_t proxy_req_active;
    } stats;
} LIBEVENT_THREAD;

typedef struct proxy_hook {
    int lua_ref;
    struct proxy_hook_tagged *tagged;
} proxy_hook;

typedef struct proxy_hook_tagged {
    int lua_ref;
    int tag;
} proxy_hook_tagged;

typedef struct proxy_ctx {
    uint64_t active_req_limit;
} proxy_ctx_t;

typedef struct mcp_parser_t {
    int command;
    int cmd_type;
    bool has_space;
    int keytoken;
    uint32_t klen;
    uint32_t vlen;
    uint32_t tokens[10];
    char *request;
} mcp_parser_t;

typedef struct mcp_request_t {
    mcp_parser_t pr;
    bool ascii_multiget;
} mcp_request_t;

typedef struct proxy_int_stats {
    uint64_t *counters;
} proxy_int_stats;

typedef struct resp {
    char wbuf[1024];
} resp;

enum conn_states {
    conn_closing,
    conn_swallow,
    conn_nread,
    conn_new_cmd
};

enum cmd_types {
    CMD_TYPE_GET
};

#define KEY_MAX_LENGTH 250
#define MAX_CMD_PREFIX 100
#define MCP_REQUEST_MAXLEN 8192
#define ENDLEN 5
#define ENDSTR "END\r\n"
#define PROCESS_MULTIGET true
#define PROXY_CLIENT_ERROR "CLIENT_ERROR"
#define PROXY_SERVER_ERROR "SERVER_ERROR"
#define LUA_REGISTRYINDEX (-10000)

#define WSTAT_INCR(thread, stat, val)
#define WSTAT_DECR(thread, stat, val) 
#define WSTAT_L(thread) 
#define WSTAT_UL(thread) 
#define P_DEBUG(fmt, ...) 

int process_request(mcp_parser_t *pr, char *command, size_t cmdlen);
bool resp_start(conn *c);
void proxy_out_errstring(struct resp *resp, const char *error_type, const char *message);
void conn_set_state(conn *c, enum conn_states state);
void process_command_ascii(conn *c, char *command);
uint32_t _process_request_next_key(mcp_parser_t *pr);
void resp_add_iov(struct resp *resp, char *buf, size_t len);
bool proxy_bufmem_checkadd(LIBEVENT_THREAD *thr, size_t size);
mcp_request_t *mcp_new_request(lua_State *L, mcp_parser_t *pr, char *command, size_t cmdlen);
void proxy_run_coroutine(lua_State *L, struct resp *resp, void *arg1, conn *c);
int luaL_ref(lua_State *L, int registry_index);
void lua_settop(lua_State *L, int index);
lua_State *lua_newthread(lua_State *L);
lua_State *lua_tothread(lua_State *L, int index);
void lua_rawgeti(lua_State *L, int registry_index, int ref);