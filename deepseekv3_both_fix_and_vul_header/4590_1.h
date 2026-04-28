#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

typedef enum {
    FAIL,
    PASS
} enum_func_status;

typedef unsigned char zend_uchar;
typedef int zend_bool;
#define TRUE 1
#define FALSE 0

typedef struct _MYSQLND_CONN_DATA MYSQLND_CONN_DATA;
typedef struct _MYSQLND_PACKET_GREET MYSQLND_PACKET_GREET;
typedef struct _MYSQLND_OPTIONS MYSQLND_OPTIONS;
typedef struct _MYSQLND_ERROR_INFO MYSQLND_ERROR_INFO;
typedef struct st_mysqlnd_authentication_plugin st_mysqlnd_authentication_plugin;

struct _MYSQLND_PACKET_GREET {
    const char *auth_protocol;
    const zend_uchar *auth_plugin_data;
    size_t auth_plugin_data_len;
    unsigned int charset_no;
};

struct _MYSQLND_CONN_DATA {
    MYSQLND_ERROR_INFO *error_info;
    zend_uchar *auth_plugin_data;
    size_t auth_plugin_data_len;
    zend_bool persistent;
    struct {
        void (*set_client_option)(MYSQLND_CONN_DATA *, int, const char *);
    } *m;
};

struct _MYSQLND_ERROR_INFO {
    int error_no;
};

struct st_mysqlnd_authentication_plugin {
    struct {
        zend_uchar *(*get_auth_data)(void *, size_t *, MYSQLND_CONN_DATA *, const char *, const char *, size_t, const zend_uchar *, size_t, const MYSQLND_OPTIONS *, unsigned long);
    } methods;
};

#define TSRMLS_DC
#define TSRMLS_CC
#define DBG_ENTER(x)
#define DBG_INF(x)
#define DBG_INF_FMT(...)
#define DBG_RETURN(x) return x
#define SET_CLIENT_ERROR(...)
#define SET_OOM_ERROR(...)
#define MYSQLND_OPT_AUTH_PROTOCOL 0
#define UNKNOWN_SQLSTATE ""
#define CR_NOT_IMPLEMENTED 0
#define E_WARNING 0

static char* mnd_pestrdup(const char *s, zend_bool dummy) {
    return strdup(s);
}

static void* mnd_pemalloc(size_t size, zend_bool dummy) {
    return malloc(size);
}

static void mnd_pefree(void *ptr, zend_bool dummy) {
    free(ptr);
}

static int mnd_sprintf(char **str, size_t dummy, const char *format, ...) {
    va_list args;
    va_start(args, format);
    int len = vsnprintf(NULL, 0, format, args);
    va_end(args);
    
    *str = malloc(len + 1);
    if (!*str) return -1;
    
    va_start(args, format);
    vsprintf(*str, format, args);
    va_end(args);
    
    return len;
}

static void mnd_sprintf_free(char *str) {
    free(str);
}

#define mnd_emalloc malloc
#define mnd_efree free