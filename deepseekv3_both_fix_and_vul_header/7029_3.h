#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

typedef struct modsec_rec modsec_rec;
typedef struct msre_var msre_var;
typedef struct msre_rule msre_rule;
typedef struct multipart_part multipart_part;
typedef struct msc_regex_t msc_regex_t;
typedef struct apr_table_t apr_table_t;
typedef struct apr_pool_t apr_pool_t;
typedef struct multipart_data multipart_data;
typedef struct apr_array_header_t apr_array_header_t;
typedef struct txcfg txcfg;

enum {
    MULTIPART_FILE,
    PCRE_ERROR_NOMATCH
};

struct modsec_rec {
    multipart_data *mpd;
    txcfg *txcfg;
    int debuglog_level;
    void (*msr_log)(modsec_rec *, int, const char *);
};

struct msre_var {
    char *param;
    void *param_data;
    char *value;
    size_t value_len;
    char *name;
};

struct multipart_part {
    int type;
    char *tmp_file_name;
    char *name;
    size_t length;
};

struct multipart_data {
    apr_array_header_t *parts;
};

struct apr_array_header_t {
    void *elts;
    int nelts;
};

struct txcfg {
    int debuglog_level;
};

int msc_regexec(msc_regex_t *regex, const char *name, size_t len, char **error_msg);
char *log_escape_nq(apr_pool_t *pool, const char *str);
void *apr_pcalloc(apr_pool_t *pool, size_t size);
void *apr_pmemdup(apr_pool_t *pool, const void *m, size_t n);
char *apr_psprintf(apr_pool_t *pool, const char *fmt, ...);
void apr_table_addn(apr_table_t *t, const char *key, const void *val);
void msr_log(modsec_rec *msr, int level, const char *message);