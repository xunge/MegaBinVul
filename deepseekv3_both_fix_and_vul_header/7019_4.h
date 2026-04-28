#include <stdio.h>
#include <time.h>
#include <stdint.h>
#include <sys/types.h>

typedef unsigned int uint;
typedef unsigned long ulong;
typedef uint32_t uint32;

#define SPIDER_SQL_SPACE_LEN 1
#define SPIDER_SQL_SPACE_STR " "
#define HA_ERR_OUT_OF_MEM 1
#define COM_QUERY 0

#define DBUG_ENTER(x)
#define DBUG_PRINT(x, y)
#define DBUG_RETURN(x) return x

struct st_mysql {
    unsigned long thread_id;
    unsigned long long affected_rows;
    unsigned long long insert_id;
    unsigned int server_status;
    unsigned int warning_count;
};

typedef struct st_mysql MYSQL;

struct Security_context {
    const char *user;
    const char *host_or_ip;
};

struct THD {
    uint query_length_var;
    const char *query_var;
    ulong thread_id;
    Security_context *security_ctx;
    
    uint query_length() const { return query_length_var; }
    const char* query() const { return query_var; }
};

struct spider_db_conn {
    const char *tgt_host;
    uint32 tgt_host_length;
    const char *tgt_wrapper;
    uint32 tgt_wrapper_length;
};

struct spider_string {
    void init_calc_mem(int);
    int reserve(uint);
    void q_append(const char *, uint);
    const char *ptr();
    uint length();
    void length(uint);
    const char *c_ptr_safe();
};

class spider_db_mbase {
public:
    int exec_query(const char *query, uint length, int quick_mode);
    spider_db_conn *conn;
    MYSQL *db_conn;
};

extern THD *current_thd;
extern int spider_param_log_result_errors();
extern int spider_param_general_log();
extern int spider_param_dry_access();
extern int spider_param_log_result_error_with_sql();
extern void general_log_write(THD *, int, const char *, uint);
extern int mysql_real_query(MYSQL *, const char *, uint);
extern void print_warnings(struct tm *);
extern void fetch_and_print_warnings(struct tm *);