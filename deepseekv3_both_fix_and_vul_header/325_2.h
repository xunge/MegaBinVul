#include <stddef.h>

typedef struct apr_pool_t apr_pool_t;
typedef struct apr_array_header_t {
    int nelts;
} apr_array_header_t;

typedef struct am_dir_cfg_rec {
    int enable_mellon;
    const char *varname;
    int secure;
    int merge_env_vars;
    int env_vars_index_start;
    int env_vars_count_in_n;
    const char *cookie_domain;
    const char *cookie_path;
    apr_array_header_t *cond;
    void *envattr;
    const char *userattr;
    const char *idpattr;
    int dump_session;
    int dump_saml_response;
    const char *endpoint_path;
    int session_length;
    const char *no_cookie_error_page;
    const char *no_success_error_page;
    const char *sp_metadata_file;
    const char *sp_private_key_file;
    const char *sp_cert_file;
    apr_array_header_t *idp_metadata;
    const char *idp_public_key_file;
    const char *idp_ca_file;
    const char *idp_ignore;
    const char *sp_entity_id;
    void *sp_org_name;
    void *sp_org_display_name;
    void *sp_org_url;
    const char *login_path;
    const char *discovery_url;
    int probe_discovery_timeout;
    void *probe_discovery_idp;
    void *inherit_server_from;
    void *server_mutex;
    void *server;
    apr_array_header_t *authn_context_class_ref;
    void *do_not_verify_logout_signature;
    int subject_confirmation_data_address_check;
    int post_replay;
    int ecp_send_idplist;
    const char *redirect_domains;
} am_dir_cfg_rec;

#define am_enable_default 0
#define default_cookie_name NULL
#define default_secure_cookie 0
#define default_merge_env_vars 0
#define default_env_vars_index_start 0
#define default_env_vars_count_in_n 0
#define default_user_attribute NULL
#define default_dump_session 0
#define default_dump_saml_response 0
#define default_endpoint_path NULL
#define default_login_path NULL
#define default_redirect_domains NULL
#define APR_THREAD_MUTEX_DEFAULT 0

#define CFG_MERGE(add_cfg, base_cfg, field) \
    ((add_cfg->field != base_cfg->field) ? add_cfg->field : base_cfg->field)

void *apr_palloc(apr_pool_t *p, int size);
void apr_pool_cleanup_register(apr_pool_t *p, void *data, void *cleanup_fn, void *cleanup_fn_arg);
apr_array_header_t *apr_array_copy(apr_pool_t *p, apr_array_header_t *array);
void *apr_hash_copy(apr_pool_t *p, void *hash);
int apr_hash_count(void *hash);
int apr_is_empty_array(apr_array_header_t *array);
int apr_is_empty_table(void *table);
void *apr_table_copy(apr_pool_t *p, void *table);
void apr_thread_mutex_create(void **mutex, int type, apr_pool_t *p);
void auth_mellon_free_server(void *data);
int cfg_can_inherit_lasso_server(am_dir_cfg_rec *cfg);