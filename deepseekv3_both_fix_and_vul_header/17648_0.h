#include <stdlib.h>
#include <string.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

#define CHARSET_NAME_LEN 64
#define CR_MALFORMED_PACKET 2007

typedef struct st_mysql {
    ulong affected_rows;
    ulong insert_id;
    unsigned int server_status;
    unsigned int warning_count;
    char *info;
    char *db;
    struct {
        uchar *read_pos;
    } net;
    unsigned long server_capabilities;
    struct {
        struct {
            void *list;
            void *current;
        } session_state[8];
    } *extension;
    struct {
        const char *csname;
    } *charset;
} MYSQL;

typedef struct st_list {
    void *data;
    struct st_list *next;
} LIST;

typedef struct st_mysql_lex_string {
    char *str;
    size_t length;
} MYSQL_LEX_STRING;

typedef enum enum_session_state_type {
    SESSION_TRACK_SCHEMA,
    SESSION_TRACK_STATE_CHANGE,
    SESSION_TRACK_TRANSACTION_CHARACTERISTICS,
    SESSION_TRACK_SYSTEM_VARIABLES,
    SESSION_TRACK_BEGIN,
    SESSION_TRACK_END
} enum_session_state_type;

typedef struct st_mariadb_charset_info {
    const char *csname;
} MARIADB_CHARSET_INFO;

#define CLIENT_SESSION_TRACKING (1UL << 23)
#define SERVER_SESSION_STATE_CHANGED (1 << 14)

typedef int my_bool;

#define CR_OUT_OF_MEMORY 2006
#define SQLSTATE_UNKNOWN "HY000"

ulong net_field_length_ll(uchar **packet);
unsigned short uint2korr(const uchar *pos);
size_t net_field_length(uchar **packet);
void *ma_multi_malloc(int flags, ...);
void ma_clear_session_state(MYSQL *mysql);
void SET_CLIENT_ERROR(MYSQL *mysql, int errcode, const char *sqlstate, unsigned int errmsg);
LIST *list_add(LIST *root, LIST *element);
LIST *list_reverse(LIST *list);
MARIADB_CHARSET_INFO *mysql_find_charset_name(const char *name);