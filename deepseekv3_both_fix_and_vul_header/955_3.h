#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define ZTS
#define TSRMLS_FETCH()
#define TSRMLS_C
#define ZEND_WIN32
#define SIZEOF_LONG 8
#define SUCCESS 0
#define ACCEL_LOG_WARNING 0
#define ACCEL_LOG_DEBUG 0
#define ACCEL_RESTART_OOM 0
#define ACCEL_RESTART_HASH 1
#define ACCEL_RESTART_USER 2
#define PHP_5_3_X_API_NO 0
#define ZEND_EXTENSION_API_NO 0

struct _zend_accel_hash_entry {
    char *key;
    unsigned int key_length;
};

typedef struct _zend_accel_hash_entry zend_accel_hash_entry;

struct _zend_accel_hash {
    zend_accel_hash_entry **hash_table;
    zend_accel_hash_entry *hash_entries;
    unsigned int num_entries;
    unsigned int num_direct_entries;
    unsigned int max_num_entries;
};

typedef struct {
    int enabled;
    struct {
        int validate_root;
        int interned_strings_buffer;
    } accel_directives;
    unsigned long root_hash;
    time_t request_time;
    void *cache_opline;
    void *cache_persistent_script;
    int include_path_check;
    int include_path_key;
    int counted;
    int internal_functions_count;
    int function_table;
    void *cwd;
} ZCG;

typedef struct {
    int restart_pending;
    int restart_reason;
    int oom_restarts;
    int hash_restarts;
    int manual_restarts;
    int accelerator_enabled;
    int cache_status_before_restart;
    time_t last_restart_time;
    struct _zend_accel_hash hash;
    struct _zend_accel_hash include_paths;
} ZCSG;

#define ZCG(name) (zend_globals_cache.name)
#define ZCSG(name) (zend_shared_globals.name)

extern ZCG zend_globals_cache;
extern ZCSG zend_shared_globals;

int accel_startup_ok;
double sapi_get_request_time();
int tsrm_thread_id();
void zend_accel_error(int, const char *, ...);
void accel_unlock_all();
void zend_shared_alloc_lock();
int accel_is_inactive();
void accel_restart_enter();
void zend_reset_cache_vars();
void zend_accel_hash_clean(struct _zend_accel_hash *);
unsigned int zend_inline_hash_func(const char *, unsigned int);
void accel_interned_strings_restore_state();
void zend_shared_alloc_restore_state();
void accel_restart_leave();
void zend_shared_alloc_unlock();
int zend_hash_num_elements(int *);

#define SHM_UNPROTECT()
#define SHM_PROTECT()