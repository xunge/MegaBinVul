#include <time.h>
#include <string.h>
#include <stdlib.h>

struct connection_info {
    const char *db;
    unsigned int db_length;
    unsigned long query_id;
    const char *query;
    unsigned int query_length;
    int log_always;
    const char *user;
    unsigned int user_length;
    const char *host;
    unsigned int host_length;
    const char *ip;
    unsigned int ip_length;
};

static unsigned long query_counter;
static unsigned int events;
static char *big_buffer;
static size_t big_buffer_alloced;
static int query_log_limit;
static const char *servhost;
static unsigned int servhost_len;
static const char *keywords_to_skip[1];
static const char *not_ddl_keywords[1];
static const char *ddl_keywords[1];
static const char *dml_keywords[1];
static const char *dml_no_select_keywords[1];
static const char *dcl_keywords[1];
static const char *passwd_keywords[1];

#define MAX_KEYWORD 32
#define EVENT_QUERY_ALL 0x01
#define EVENT_QUERY 0x02
#define EVENT_QUERY_DDL 0x04
#define EVENT_QUERY_DML 0x08
#define EVENT_QUERY_DML_NO_SELECT 0x10
#define EVENT_QUERY_DCL 0x20

enum sql_command_type {
    SQLCOM_GRANT = 1,
    SQLCOM_CREATE_USER = 2,
    SQLCOM_CHANGE_MASTER = 3,
    SQLCOM_CREATE_SERVER = 4,
    SQLCOM_ALTER_SERVER = 5,
    SQLCOM_SET_OPTION = 6
};

static size_t log_header(char *message, size_t message_size, const time_t *ev_time,
                        const char *servhost, unsigned int servhost_len,
                        const char *user, unsigned int user_length,
                        const char *host, unsigned int host_length,
                        const char *ip, unsigned int ip_length,
                        unsigned long thd_id, long long query_id, const char *type);

static int filter_query_type(const char *query, const char *keywords[]);
static int get_next_word(const char *query, char *fword);
static int my_snprintf(char *str, size_t size, const char *format, ...);
static int escape_string(const char *src, unsigned int src_len,
                        char *dst, unsigned int dst_len);
static int escape_string_hide_passwords(const char *src, unsigned int src_len,
                                       char *dst, unsigned int dst_len,
                                       const char *kw1, unsigned int kw1_len,
                                       const char *kw2, unsigned int kw2_len,
                                       int skip_quotes);
static int write_log(const char *message, size_t size, int take_lock);
static void flogger_mutex_lock(void *lock);
static void flogger_mutex_unlock(void *lock);
static void *lock_bigbuffer;