#include <stddef.h>

typedef struct request_rec {
    struct {
        void *module_config;
    } *server;
    void *per_dir_config;
} request_rec;

typedef struct apr_pool_t apr_pool_t;

typedef struct apr_array_header_t {
    int nelts;
    void *elts;
} apr_array_header_t;

typedef struct lua_State lua_State;

typedef enum {
    AUTHZ_DENIED,
    AUTHZ_GRANTED,
    AUTHZ_NEUTRAL,
    AUTHZ_GENERAL_ERROR,
    AUTHZ_DENIED_NO_USER
} authz_status;

typedef struct ap_lua_vm_spec ap_lua_vm_spec;
typedef struct ap_lua_server_cfg ap_lua_server_cfg;
typedef struct ap_lua_dir_cfg ap_lua_dir_cfg;

typedef struct {
    const char *name;
    const char *file_name;
    const char *function_name;
    apr_array_header_t *args;
} lua_authz_provider_spec;

typedef struct {
    const lua_authz_provider_spec *spec;
    apr_array_header_t *args;
} lua_authz_provider_func;

#define APLOG_MARK __FILE__, __LINE__, __func__
#define APLOG_ERR 0
#define APLOG_CRIT 0
#define APLOGNO(n) ""

struct module {
    int dummy;
};
extern struct module lua_module;

void *ap_get_module_config(void *conf, struct module *mod);
ap_lua_vm_spec *create_vm_spec(apr_pool_t **pool, request_rec *r, 
                              const ap_lua_dir_cfg *cfg, ap_lua_server_cfg *server_cfg,
                              const char *file_name, void *null1, int null2,
                              const char *function_name, const char *desc);
lua_State *ap_lua_get_lua_state(apr_pool_t *pool, ap_lua_vm_spec *spec, request_rec *r);
void ap_log_rerror(const char *file, int line, const char *func, int level1, 
                  int level2, request_rec *r, const char *fmt, ...);
void ap_lua_release_state(lua_State *L, ap_lua_vm_spec *spec, request_rec *r);
void ap_lua_run_lua_request(lua_State *L, request_rec *r);
int lua_getglobal(lua_State *L, const char *name);
int lua_isfunction(lua_State *L, int index);
int lua_checkstack(lua_State *L, int extra);
void lua_pushstring(lua_State *L, const char *s);
int lua_pcall(lua_State *L, int nargs, int nresults, int errfunc);
const char *lua_tostring(lua_State *L, int index);
int lua_isnumber(lua_State *L, int index);
int lua_tointeger(lua_State *L, int index);

#define APR_ARRAY_IDX(arr, i, type) (((type *)((arr)->elts))[i])