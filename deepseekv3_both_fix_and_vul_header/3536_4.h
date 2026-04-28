#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef int apr_status_t;

typedef struct modsec_rec {
    void *mp;
    int request_content_length;
    void *request_headers;
    int reqbody_chunked;
    int reqbody_should_exist;
    char *request_content_type;
    int msc_reqbody_storage;
    int msc_reqbody_spilltodisk;
    char *msc_reqbody_processor;
    struct {
        int reqbody_inmemory_limit;
        int reqbody_buffering;
        int cookie_format;
        int debuglog_level;
        char *argument_separator;
    } *txcfg;
    void *arguments;
    char *query_string;
    int urlencoded_error;
    void *arguments_to_sanitize;
    void *request_headers_to_sanitize;
    void *response_headers_to_sanitize;
    void *pattern_to_sanitize;
    void *removed_targets;
    void *request_cookies;
    void *matched_vars;
    void *perf_rules;
    void *tx_vars;
    void *geo_vars;
    void *collections_original;
    void *collections;
    void *collections_dirty;
    void *tcache;
    int tcache_items;
    void *matched_rules;
    struct msc_string *matched_var;
    int highest_severity;
    void *removed_rules;
    void *removed_rules_tag;
    void *removed_rules_msg;
} modsec_rec;

typedef struct msc_string {
    char *data;
    size_t len;
} msc_string;

typedef struct apr_array_header_t {
    void *elts;
    int nelts;
} apr_array_header_t;

typedef struct apr_table_entry_t {
    char *key;
    char *val;
} apr_table_entry_t;

#define MSC_REQBODY_MEMORY 0
#define MSC_REQBODY_DISK 1
#define REQUEST_BODY_FORCEBUF_OFF 0
#define COOKIES_V0 0

/* Dummy declarations for APR functions */
void modsecurity_tx_cleanup(void *);
#define apr_pool_cleanup_null NULL
void apr_pool_cleanup_register(void*, void*, void (*)(void*), void (*)(void*));
void* apr_table_get(void*, const char*);
void* apr_table_make(void*, int);
void apr_table_clear(void*);
void* apr_table_elts(void*);
char* apr_pstrdup(void*, const char*);
void parse_cookies_v0(void*, const char*, void*, const char*);
void parse_cookies_v1(void*, const char*, void*);
void* apr_array_make(void*, int, size_t);
void* apr_pcalloc(void*, size_t);
void msr_log(void*, int, const char*);
int parse_arguments(void*, const char*, size_t, const char*, const char*, void*, int*);