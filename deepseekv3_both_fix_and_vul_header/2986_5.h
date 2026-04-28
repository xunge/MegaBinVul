#include <stdlib.h>

#define NOT_SET 0
#define NOT_SET_P NULL

typedef struct apr_pool_t apr_pool_t;

typedef struct directory_config {
    apr_pool_t *mp;
    int is_enabled;
    int reqbody_access;
    int reqintercept_oe;
    int reqbody_buffering;
    int reqbody_inmemory_limit;
    int reqbody_limit;
    int reqbody_no_files_limit;
    int resbody_access;
    void *debuglog_name;
    int debuglog_level;
    void *debuglog_fd;
    int of_limit;
    int if_limit_action;
    int of_limit_action;
    void *of_mime_types;
    int of_mime_types_cleared;
    int cookie_format;
    int argument_separator;
    void *cookiev0_separator;
    int rule_inheritance;
    void *rule_exceptions;
    void *hash_method;
    int auditlog_flag;
    int auditlog_type;
    int max_rule_time;
    int auditlog_dirperms;
    int auditlog_fileperms;
    void *auditlog_name;
    void *auditlog2_name;
    void *auditlog_fd;
    void *auditlog2_fd;
    void *auditlog_storage_dir;
    void *auditlog_parts;
    void *auditlog_relevant_regex;
    void *ruleset;
    void *tmp_dir;
    void *upload_dir;
    int upload_keep_files;
    int upload_validates_files;
    int upload_filemode;
    int upload_file_limit;
    void *tmp_chain_starter;
    void *tmp_default_actionset;
    void *tmp_rule_placeholders;
    void *data_dir;
    void *webappid;
    void *sensor_id;
    void *httpBlkey;
    int content_injection_enabled;
    int stream_inbody_inspection;
    int stream_outbody_inspection;
    void *geo;
    void *gsb;
    void *u_map;
    int cache_trans;
    int cache_trans_incremental;
    int cache_trans_min;
    int cache_trans_max;
    int cache_trans_maxitems;
    void *rule_id_htab;
    void *component_signatures;
    void *request_encoding;
    int disable_backend_compression;
    int col_timeout;
    void *crypto_key;
    int crypto_key_len;
    int crypto_key_add;
    void *crypto_param_name;
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

typedef struct rule_exception rule_exception;
typedef struct hash_method hash_method;

void *apr_pcalloc(apr_pool_t *pool, size_t size);
void *apr_array_make(apr_pool_t *p, int nelts, int elt_size);
void *apr_hash_make(apr_pool_t *pool);