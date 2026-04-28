#include <stddef.h>

#define AUTHZ_PROVIDER_NAME_NOTE "lua_authz_provider_name"
#define APR_HASH_KEY_STRING 0

typedef struct cmd_parms cmd_parms;
typedef struct apr_pool_t apr_pool_t;
typedef struct apr_hash_t apr_hash_t;
typedef struct apr_array_header_t apr_array_header_t;

struct cmd_parms {
    apr_pool_t *pool;
    apr_pool_t *temp_pool;
};

typedef struct lua_authz_provider_spec lua_authz_provider_spec;
typedef struct lua_authz_provider_func lua_authz_provider_func;

struct lua_authz_provider_func {
    lua_authz_provider_spec *spec;
    apr_array_header_t *args;
};

struct lua_authz_provider_spec {
    apr_array_header_t *args;
};

extern void *apr_pcalloc(apr_pool_t *, size_t);
extern void apr_pool_userdata_get(void **, const char *, apr_pool_t *);
extern void *apr_hash_get(apr_hash_t *, const char *, int);
extern apr_array_header_t *apr_array_make(apr_pool_t *, int, size_t);
extern const char *ap_getword_conf(apr_pool_t *, const char **);
extern void ap_assert(int);

#define APR_ARRAY_PUSH(arr, type) *(type *)apr_array_push(arr)

static apr_hash_t *lua_authz_providers;