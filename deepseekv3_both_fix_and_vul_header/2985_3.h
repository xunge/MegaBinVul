#include <stdlib.h>
#include <stddef.h>

#define NOT_SET (-1)
#define NOT_SET_P NULL

typedef struct apr_pool_t apr_pool_t;
typedef struct apr_array_header_t apr_array_header_t;
typedef struct apr_table_t apr_table_t;
typedef size_t apr_size_t;

typedef struct directory_config {
    int is_enabled;
    int reqbody_access;
    int reqbody_buffering;
    int reqbody_inmemory_limit;
    int reqbody_limit;
    int reqbody_no_files_limit;
    int resbody_access;
    int of_limit;
    int if_limit_action;
    int of_limit_action;
    int reqintercept_oe;
    apr_table_t *of_mime_types;
    int of_mime_types_cleared;
    const char *debuglog_name;
    void *debuglog_fd;
    int debuglog_level;
    int cookie_format;
    int argument_separator;
    void *cookiev0_separator;
    int rule_inheritance;
    struct msre_ruleset *ruleset;
    apr_array_header_t *rule_exceptions;
    apr_array_header_t *hash_method;
    int auditlog_flag;
    int auditlog_type;
    int max_rule_time;
    int auditlog_dirperms;
    int auditlog_fileperms;
    void *auditlog_fd;
    const char *auditlog_name;
    void *auditlog2_fd;
    const char *auditlog2_name;
    const char *auditlog_storage_dir;
    apr_array_header_t *auditlog_parts;
    void *auditlog_relevant_regex;
    const char *tmp_dir;
    const char *upload_dir;
    int upload_keep_files;
    int upload_validates_files;
    int upload_filemode;
    int upload_file_limit;
    const char *data_dir;
    const char *webappid;
    const char *sensor_id;
    const char *httpBlkey;
    int content_injection_enabled;
    int stream_inbody_inspection;
    int stream_outbody_inspection;
    void *geo;
    void *gsb;
    void *u_map;
    int cache_trans;
    int cache_trans_incremental;
    apr_size_t cache_trans_min;
    apr_size_t cache_trans_max;
    apr_size_t cache_trans_maxitems;
    apr_array_header_t *component_signatures;
    const char *request_encoding;
    int disable_backend_compression;
    int col_timeout;
    const char *crypto_key;
    int crypto_key_len;
    int crypto_key_add;
    const char *crypto_param_name;
    int hash_is_enabled;
    int hash_enforcement;
    int crypto_hash_href_rx;
    int crypto_hash_faction_rx;
    int crypto_hash_location_rx;
    int crypto_hash_iframesrc_rx;
    int crypto_hash_framesrc_rx;
    int crypto_hash_href_pm;
    int crypto_hash_faction_pm;
    int crypto_hash_location_pm;
    int crypto_hash_iframesrc_pm;
    int crypto_hash_framesrc_pm;
    int xml_external_entity;
} directory_config;

struct msre_ruleset {
    void *engine;
    apr_array_header_t *phase_request_headers;
    apr_array_header_t *phase_request_body;
    apr_array_header_t *phase_response_headers;
    apr_array_header_t *phase_response_body;
    apr_array_header_t *phase_logging;
};

directory_config *create_directory_config(apr_pool_t *mp, void *arg);
apr_table_t *apr_table_overlay(apr_pool_t *p, const apr_table_t *overlay, const apr_table_t *base);
struct msre_ruleset *msre_ruleset_create(void *engine, apr_pool_t *mp);
void copy_rules(apr_pool_t *mp, struct msre_ruleset *src, struct msre_ruleset *dst, apr_array_header_t *exceptions);
apr_array_header_t *apr_array_copy(apr_pool_t *p, const apr_array_header_t *arr);
apr_array_header_t *apr_array_append(apr_pool_t *p, const apr_array_header_t *first, const apr_array_header_t *second);
void apr_array_cat(apr_array_header_t *dst, const apr_array_header_t *src);