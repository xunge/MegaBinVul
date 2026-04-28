#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <assert.h>
#include <time.h>

typedef int kadm5_ret_t;
typedef int krb5_boolean;
#define FALSE 0
#define TRUE 1
typedef int krb5_int32;
typedef unsigned int krb5_kvno;

struct krb5_db_entry {
    int magic;
    int len;
    unsigned int attributes;
    int max_life;
    int max_renewable_life;
    time_t expiration;
    time_t pw_expiration;
    time_t last_success;
    time_t last_failed;
    int fail_auth_count;
    void *princ;
    int mask;
};
typedef struct krb5_db_entry krb5_db_entry;

struct osa_princ_ent_rec {
    int admin_history_kvno;
    int aux_attributes;
    char *policy;
};
typedef struct osa_princ_ent_rec osa_princ_ent_rec;

struct kadm5_policy_ent_rec {
    int pw_max_life;
};
typedef struct kadm5_policy_ent_rec kadm5_policy_ent_rec;

struct krb5_tl_data {
    struct krb5_tl_data *tl_data_next;
};
typedef struct krb5_tl_data krb5_tl_data;

struct krb5_keyblock {
    // keyblock fields
};
typedef struct krb5_keyblock krb5_keyblock;

struct kadm5_principal_ent_t {
    char *principal;
    int n_key_data;
    unsigned int attributes;
    int max_life;
    int max_renewable_life;
    time_t princ_expire_time;
    time_t pw_expiration;
    char *policy;
    int kvno;
    struct krb5_tl_data *tl_data;
};
typedef struct kadm5_principal_ent_t *kadm5_principal_ent_t;

struct krb5_key_salt_tuple {
    int enctype;
    int salttype;
};
typedef struct krb5_key_salt_tuple krb5_key_salt_tuple;

struct kadm5_server_handle_t {
    void *context;
    void *lhandle;
    struct {
        unsigned int flags;
        int max_life;
        int max_rlife;
        time_t expiration;
    } params;
    void *hook_handles;
};
typedef struct kadm5_server_handle_t *kadm5_server_handle_t;

#define KADM5_PRINCIPAL 0x01
#define KADM5_MOD_NAME 0x02
#define KADM5_MOD_TIME 0x04
#define KADM5_LAST_PWD_CHANGE 0x08
#define KADM5_MKVNO 0x10
#define KADM5_AUX_ATTRIBUTES 0x20
#define KADM5_LAST_SUCCESS 0x40
#define KADM5_LAST_FAILED 0x80
#define KADM5_FAIL_AUTH_COUNT 0x100
#define KADM5_KEY_DATA 0x200
#define KADM5_POLICY 0x400
#define KADM5_POLICY_CLR 0x800
#define KADM5_ATTRIBUTES 0x1000
#define KADM5_MAX_LIFE 0x2000
#define KADM5_MAX_RLIFE 0x4000
#define KADM5_PRINC_EXPIRE_TIME 0x8000
#define KADM5_PW_EXPIRATION 0x10000
#define KADM5_TL_DATA 0x20000
#define KADM5_KVNO 0x40000
#define ALL_PRINC_MASK 0x7FFFF

#define KADM5_BAD_MASK 1
#define KADM5_DUP 2
#define KADM5_UNK_PRINC 3

#define KRB5_KDB_MAGIC_NUMBER 0x12345678
#define KRB5_KDB_V1_BASE_LENGTH 100
#define INITIAL_HIST_KVNO 1
#define KADM5_HOOK_STAGE_PRECOMMIT 1
#define KADM5_HOOK_STAGE_POSTCOMMIT 2

#define CHECK_HANDLE(handle) do {} while(0)

struct krb5_keyblock master_keyblock;

/* Function prototypes */
void krb5_clear_error_message(void *context);
void check_1_6_dummy(kadm5_principal_ent_t entry, long mask, int n_ks_tuple, 
                    krb5_key_salt_tuple *ks_tuple, char **password);
kadm5_ret_t kdb_get_entry(kadm5_server_handle_t handle, char *principal, 
                         krb5_db_entry **kdb, osa_princ_ent_rec *adb);
void kdb_free_entry(kadm5_server_handle_t handle, krb5_db_entry *kdb, 
                   osa_princ_ent_rec *adb);
krb5_db_entry *krb5_db_alloc(void *context, void *ptr, size_t size);
kadm5_ret_t get_policy(kadm5_server_handle_t handle, char *policy, 
                      kadm5_policy_ent_rec *polent, krb5_boolean *have_polent);
kadm5_ret_t passwd_check(kadm5_server_handle_t handle, char *password, 
                        kadm5_policy_ent_rec *polent, char *principal);
kadm5_ret_t krb5_timeofday(void *context, krb5_int32 *now);
kadm5_ret_t kadm5_copy_principal(void *context, char *principal, void **princ);
kadm5_ret_t krb5_dbe_update_last_pwd_change(void *context, krb5_db_entry *kdb, 
                                           krb5_int32 now);
kadm5_ret_t krb5_dbe_update_tl_data(void *context, krb5_db_entry *kdb, 
                                   krb5_tl_data *tl_data);
kadm5_ret_t apply_keysalt_policy(kadm5_server_handle_t handle, char *policy, 
                               int n_ks_tuple, krb5_key_salt_tuple *ks_tuple,
                               int *new_n_ks_tuple, krb5_key_salt_tuple **new_ks_tuple);
kadm5_ret_t kdb_get_active_mkey(kadm5_server_handle_t handle, krb5_kvno *act_kvno, 
                              krb5_keyblock **act_mkey);
kadm5_ret_t krb5_dbe_cpw(void *context, krb5_keyblock *act_mkey, 
                        krb5_key_salt_tuple *ks_tuple, int n_ks_tuple, 
                        char *password, int kvno, krb5_boolean b, krb5_db_entry *kdb);
kadm5_ret_t krb5_dbe_crk(void *context, struct krb5_keyblock *keyblock, 
                        krb5_key_salt_tuple *ks_tuple, int n_ks_tuple, 
                        krb5_boolean b, krb5_db_entry *kdb);
kadm5_ret_t krb5_dbe_update_mkvno(void *context, krb5_db_entry *kdb, krb5_kvno act_kvno);
kadm5_ret_t k5_kadm5_hook_create(void *context, void *hook_handles, 
                                int stage, kadm5_principal_ent_t entry, 
                                long mask, int n_ks_tuple, 
                                krb5_key_salt_tuple *ks_tuple, char *password);
kadm5_ret_t kdb_put_entry(kadm5_server_handle_t handle, krb5_db_entry *kdb, 
                         osa_princ_ent_rec *adb);
void krb5_db_free_principal(void *context, krb5_db_entry *kdb);
kadm5_ret_t kadm5_free_policy_ent(void *lhandle, kadm5_policy_ent_rec *polent);