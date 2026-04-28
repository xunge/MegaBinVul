#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dlfcn.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#endif

#define RTLD_DEFAULT ((void *)0)

typedef unsigned int uint;
typedef unsigned long long ulonglong;

static const char *serv_ver;
static int mysql_57_started;
static int maria_above_5;
static int started_mysql;
static int mode;
static int mode_readonly;
static char servhost[256];
static uint servhost_len;
static void *int_mysql_data_home;
static const char default_home[] = "";
static const char *incl_users;
static const char *excl_users;
static int init_done;
static int logging;

#define PLUGIN_STR_VERSION ""
#define PLUGIN_DEBUG_VERSION ""

struct loc_system_variables {
    int query_cache_type;
};

typedef struct {
    int header;
    unsigned long thread_id;
    unsigned long query_id;
    unsigned int db_length;
    unsigned int user_length;
    unsigned int host_length;
    unsigned int ip_length;
    const char *query;
    unsigned int query_length;
} ci_buffer;

static ci_buffer ci_disconnect_buffer;
static const char empty_str[] = "";

#define HAVE_PSI_INTERFACE
#define FLOGGER_NO_PSI
#define PSI_server ((void*)0)
#define mutex_key_list ((void*)0)
#define key_LOCK_operations 0
static void *lock_operations;
static void *lock_atomic;
static void *lock_bigbuffer;

#define MY_MUTEX_INIT_FAST 0

#define EVENT_TABLE 0
#define FILTER(x) (0)

static void logger_init_mutexes(void) {}
static void flogger_mutex_init(int key, void *mutex, int flags) {}
static void *incl_user_coll;
static void *excl_user_coll;
static void coll_init(void *coll) {}
static void error_header(void) {}
static void update_incl_users(void *a, void *b, void *c, const char **d) {}
static void update_excl_users(void *a, void *b, void *c, const char **d) {}
static void start_logging(void) {}

extern const char *server_version;