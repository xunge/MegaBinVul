#include <stddef.h>
#include <stdbool.h>

typedef enum {
    FAIL,
    PASS
} enum_func_status;

#define TSRMLS_DC
#define TSRMLS_CC
#define DBG_ENTER(x)
#define DBG_INF(x)
#define DBG_RETURN(x) return x
#define SET_OOM_ERROR(x)
#define SET_CLIENT_ERROR(x, y, z, w)
#define CONN_SET_STATE(x, y)
#define MYSQLND_ASSEMBLED_PACKET_MAX_SIZE 0
#define CLIENT_SSL 0
#define CLIENT_SSL_VERIFY_SERVER_CERT 0
#define MYSQL_OPT_SSL_VERIFY_SERVER_CERT 0
#define CR_SERVER_GONE_ERROR 0
#define UNKNOWN_SQLSTATE ""
#define CONN_QUIT_SENT 0
#define FALSE false
#define TRUE true

typedef bool zend_bool;

typedef struct _MYSQLND_ERROR_INFO {
    int dummy;
} MYSQLND_ERROR_INFO;

typedef struct _MYSQLND_NET {
    struct {
        int (*set_client_option)(struct _MYSQLND_NET*, int, const char* TSRMLS_DC);
        enum_func_status (*enable_ssl)(struct _MYSQLND_NET* TSRMLS_DC);
    } m;
} MYSQLND_NET;

typedef struct _MYSQLND_PROTOCOL {
    struct {
        void* (*get_auth_packet)(struct _MYSQLND_PROTOCOL*, int TSRMLS_DC);
    } m;
} MYSQLND_PROTOCOL;

typedef struct _MYSQLND_CONN_DATA {
    MYSQLND_ERROR_INFO* error_info;
    MYSQLND_PROTOCOL* protocol;
    MYSQLND_NET* net;
    struct {
        void (*send_close)(struct _MYSQLND_CONN_DATA* TSRMLS_DC);
    } *m;
} MYSQLND_CONN_DATA;

typedef struct _MYSQLND_PACKET_GREET {
    unsigned long server_capabilities;
    unsigned int charset_no;
} MYSQLND_PACKET_GREET;

typedef struct _MYSQLND_OPTIONS {
    const char* charset_name;
} MYSQLND_OPTIONS;

typedef struct _MYSQLND_CHARSET {
    unsigned int nr;
} MYSQLND_CHARSET;

typedef struct _MYSQLND_PACKET_AUTH {
    unsigned long client_flags;
    unsigned long max_packet_size;
    unsigned int charset_no;
} MYSQLND_PACKET_AUTH;

#define PACKET_WRITE(x, y) 0
#define PACKET_FREE(x)
extern const char* mysqlnd_server_gone;
extern const MYSQLND_CHARSET* mysqlnd_find_charset_name(const char*);