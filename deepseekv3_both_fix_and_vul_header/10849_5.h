#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define CHECK_HANDLE(handle) 
#define INITIAL_HIST_KVNO 1
#define KRB5_KDB_MAGIC_NUMBER 0
#define KRB5_KDB_V1_BASE_LENGTH 0
#define ALL_PRINC_MASK 0
#define KADM5_HOOK_STAGE_PRECOMMIT 0
#define KADM5_HOOK_STAGE_POSTCOMMIT 0
#define FALSE 0

typedef int kadm5_ret_t;
typedef int krb5_boolean;
typedef int krb5_kvno;
typedef long krb5_timestamp;

struct krb5_keyblock {
    int dummy;
};

struct krb5_tl_data {
    int tl_data_type;
    struct krb5_tl_data *tl_data_next;
};

struct krb5_key_salt_tuple {
    int dummy;
};

struct kadm5_policy_ent_rec {
    int pw_max_life;
};

struct krb5_db_entry {
    int magic;
    int len;
    int attributes;
    int max_life;
    int max_renewable_life;
    int expiration;
    int pw_expiration;
    int last_success;
    int last_failed;
    int fail_auth_count;
    void *princ;
    int mask;
};

struct osa_princ_ent_rec {
    int admin_history_kvno;
    int aux_attributes;
    char *policy;
};

struct kadm5_principal_ent {
    int n_key_data;
    char *policy;
    int attributes;
    int max_life;
    int max_renewable_life;
    int princ_expire_time;
    int pw_expiration;
    void *principal;
    int kvno;
    struct krb5_tl_data *tl_data;
};

typedef struct krb5_db_entry krb5_db_entry;
typedef struct osa_princ_ent_rec osa_princ_ent_rec;
typedef struct kadm5_policy_ent_rec kadm5_policy_ent_rec;
typedef struct krb5_tl_data krb5_tl_data;
typedef struct krb5_keyblock krb5_keyblock;
typedef struct kadm5_principal_ent *kadm5_principal_ent_t;
typedef struct krb5_key_salt_tuple krb5_key_salt_tuple;

struct kadm5_server_handle {
    void *context;
    void *lhandle;
    void *hook_handles;
    struct {
        int flags;
        int max_life;
        int max_rlife;
        int expiration;
    } params;
};

typedef struct kadm5_server_handle *kadm5_server_handle_t;

enum {
    EINVAL = 22,
    ENOMEM = 12,
    KADM5_UNK_PRINC = 1,
    KADM5_DUP = 2,
    KADM5_BAD_MASK = 3,
    KADM5_BAD_TL_TYPE = 4,
    KADM5_POLICY = 5,
    KADM5_KEY_DATA = 6,
    KADM5_PRINCIPAL = 7,
    KADM5_MOD_NAME = 8,
    KADM5_MOD_TIME = 9,
    KADM5_LAST_PWD_CHANGE = 10,
    KADM5_MKVNO = 11,
    KADM5_AUX_ATTRIBUTES = 12,
    KADM5_LAST_SUCCESS = 13,
    KADM5_LAST_FAILED = 14,
    KADM5_FAIL_AUTH_COUNT = 15,
    KADM5_POLICY_CLR = 16,
    KADM5_ATTRIBUTES = 17,
    KADM5_MAX_LIFE = 18,
    KADM5_MAX_RLIFE = 19,
    KADM5_PRINC_EXPIRE_TIME = 20,
    KADM5_PW_EXPIRATION = 21,
    KADM5_TL_DATA = 22,
    KADM5_KVNO = 23
};

extern struct krb5_keyblock master_keyblock;

static inline krb5_timestamp ts_incr(krb5_timestamp t, int delta) { return t + delta; }

int kdb_get_entry(void*, void*, krb5_db_entry**, osa_princ_ent_rec**);
void kdb_free_entry(void*, krb5_db_entry*, osa_princ_ent_rec*);
int get_policy(void*, char*, kadm5_policy_ent_rec*, int*);
int passwd_check(void*, char*, kadm5_policy_ent_rec*, void*);
int krb5_timeofday(void*, krb5_timestamp*);
int krb5_copy_principal(void*, void*, void**);
int krb5_dbe_update_last_pwd_change(void*, krb5_db_entry*, krb5_timestamp);
int krb5_dbe_update_tl_data(void*, krb5_db_entry*, krb5_tl_data*);
int apply_keysalt_policy(void*, char*, int, krb5_key_salt_tuple*, int*, krb5_key_salt_tuple**);
int kdb_get_active_mkey(void*, krb5_kvno*, krb5_keyblock**);
int krb5_dbe_cpw(void*, krb5_keyblock*, krb5_key_salt_tuple*, int, char*, int, int, krb5_db_entry*);
int krb5_dbe_crk(void*, krb5_keyblock*, krb5_key_salt_tuple*, int, int, krb5_db_entry*);
int krb5_dbe_update_mkvno(void*, krb5_db_entry*, int);
int k5_kadm5_hook_create(void*, void*, int, kadm5_principal_ent_t, long, int, krb5_key_salt_tuple*, char*);
int kdb_put_entry(void*, krb5_db_entry*, osa_princ_ent_rec*);
void krb5_db_free_principal(void*, krb5_db_entry*);
int kadm5_free_policy_ent(void*, kadm5_policy_ent_rec*);
void krb5_clear_error_message(void*);
void check_1_6_dummy(kadm5_principal_ent_t, long, int, krb5_key_salt_tuple*, char**);