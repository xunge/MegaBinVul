#include <stdint.h>
#include <stdlib.h>

typedef int gint;
typedef struct request_rec {
    const char* args;
    void* pool;
    void* headers_out;
} request_rec;

typedef struct LassoLogout {
    struct {
        const char* remote_providerID;
    } parent;
} LassoLogout;

typedef struct am_cache_entry_t am_cache_entry_t;
typedef struct am_dir_cfg_rec {
    void* do_not_verify_logout_signature;
} am_dir_cfg_rec;

#define APLOG_MARK 0
#define APLOG_ERR 1
#define HTTP_BAD_REQUEST 400
#define HTTP_SEE_OTHER 303
#define OK 0
#define LASSO_DS_ERROR_SIGNATURE_NOT_FOUND 0
#define LASSO_PROFILE_SIGNATURE_VERIFY_HINT_IGNORE 0

static void apr_table_setn(void* table, const char* key, const char* val);
static int apr_hash_get(void* hash, const char* key, int type);