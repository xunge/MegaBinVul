#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NOT_SET (-1)
#define NOT_SET_P NULL
#define REQUEST_BODY_FORCEBUF_OFF 0
#define REQUEST_BODY_DEFAULT_INMEMORY_LIMIT 131072
#define REQUEST_BODY_DEFAULT_LIMIT 134217728
#define REQUEST_BODY_NO_FILES_DEFAULT_LIMIT 131072
#define RESPONSE_BODY_DEFAULT_LIMIT 524288
#define REQUEST_BODY_LIMIT_ACTION_REJECT 0
#define RESPONSE_BODY_LIMIT_ACTION_REJECT 0
#define AUDITLOG_SERIAL 0
#define CREATEMODE_DIR 0755
#define CREATEMODE 0644
#define KEEP_FILES_OFF 0
#define MODSEC_CACHE_DISABLED 0
#define HASH_KEYONLY 0
#define HASH_DISABLED 0

typedef size_t apr_size_t;
typedef struct apr_pool_t apr_pool_t;
typedef struct apr_table_t apr_table_t;

typedef struct directory_config {
    int is_enabled;
    int reqbody_access;
    int reqintercept_oe;
    int reqbody_buffering;
    size_t reqbody_inmemory_limit;
    size_t reqbody_limit;
    size_t reqbody_no_files_limit;
    int resbody_access;
    size_t of_limit;
    int if_limit_action;
    int of_limit_action;
    apr_table_t *of_mime_types;
    int of_mime_types_cleared;
    FILE *debuglog_fd;
    char *debuglog_name;
    int debuglog_level;
    int cookie_format;
    char argument_separator;
    char *cookiev0_separator;
    int rule_inheritance;
    int auditlog_flag;
    int auditlog_type;
    int max_rule_time;
    int auditlog_dirperms;
    int auditlog_fileperms;
    FILE *auditlog_fd;
    FILE *auditlog2_fd;
    char *auditlog_name;
    char *auditlog2_name;
    char *auditlog_storage_dir;
    char *auditlog_parts;
    char *auditlog_relevant_regex;
    char *tmp_dir;
    char *upload_dir;
    int upload_keep_files;
    int upload_validates_files;
    int upload_filemode;
    int upload_file_limit;
    char *data_dir;
    char *webappid;
    char *sensor_id;
    char *httpBlkey;
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
    char *request_encoding;
    int disable_backend_compression;
    int col_timeout;
    char *crypto_key;
    int crypto_key_len;
    int crypto_key_add;
    char *crypto_param_name;
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
    apr_pool_t *mp;
} directory_config;

apr_table_t *apr_table_make(apr_pool_t *p, int nelts);
void apr_table_setn(apr_table_t *t, const char *key, const char *val);
char *guess_tmp_dir(apr_pool_t *mp);
char *getkey(apr_pool_t *mp);