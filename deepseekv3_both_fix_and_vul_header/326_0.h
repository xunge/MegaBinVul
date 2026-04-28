#include <stdlib.h>

typedef struct apr_pool_t apr_pool_t;

typedef struct am_cond_t {
    int dummy;
} am_cond_t;

typedef struct am_metadata_t {
    int dummy;
} am_metadata_t;

typedef struct am_dir_cfg_rec {
    int enable_mellon;
    char *varname;
    int secure;
    int merge_env_vars;
    int env_vars_index_start;
    int env_vars_count_in_n;
    void *cond;
    char *cookie_domain;
    char *cookie_path;
    void *envattr;
    char *userattr;
    char *idpattr;
    int dump_session;
    int dump_saml_response;
    char *endpoint_path;
    int session_length;
    char *no_cookie_error_page;
    char *no_success_error_page;
    char *sp_metadata_file;
    char *sp_private_key_file;
    char *sp_cert_file;
    void *idp_metadata;
    char *idp_public_key_file;
    char *idp_ca_file;
    char *idp_ignore;
    char *login_path;
    char *discovery_url;
    int probe_discovery_timeout;
    void *probe_discovery_idp;
    char *sp_entity_id;
    void *sp_org_name;
    void *sp_org_display_name;
    void *sp_org_url;
    void *server_mutex;
    struct am_dir_cfg_rec *inherit_server_from;
    void *server;
    void *authn_context_class_ref;
    int subject_confirmation_data_address_check;
    void *do_not_verify_logout_signature;
    int post_replay;
    int ecp_send_idplist;
    char *redirect_domains;
} am_dir_cfg_rec;

#define APR_THREAD_MUTEX_DEFAULT 0

int am_enable_default;
char *default_cookie_name;
int default_secure_cookie;
int default_merge_env_vars;
int default_env_vars_index_start;
int default_env_vars_count_in_n;
char *default_user_attribute;
int default_dump_session;
int default_dump_saml_response;
char *default_endpoint_path;
char *default_login_path;
int inherit_subject_confirmation_data_address_check;
int inherit_post_replay;
int inherit_ecp_send_idplist;
char *default_redirect_domains;

void *apr_palloc(apr_pool_t *p, size_t size);
void apr_pool_cleanup_register(apr_pool_t *p, void *data, void (*cleanup_fn)(void *), void (*child_cleanup_fn)(void *));
void *apr_array_make(apr_pool_t *p, int nelts, int elt_size);
void *apr_hash_make(apr_pool_t *p);
void *apr_table_make(apr_pool_t *p, int nelts);
void apr_thread_mutex_create(void **mutex, int flags, apr_pool_t *p);
void auth_mellon_free_server(void *data);