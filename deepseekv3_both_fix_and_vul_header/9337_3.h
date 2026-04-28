#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef int kadm5_ret_t;
typedef int krb5_boolean;

#define FALSE 0
#define TRUE 1

#define KADM5_PRINCIPAL 0x01
#define KADM5_LAST_PWD_CHANGE 0x02
#define KADM5_MOD_TIME 0x04
#define KADM5_MOD_NAME 0x08
#define KADM5_MKVNO 0x10
#define KADM5_AUX_ATTRIBUTES 0x20
#define KADM5_KEY_DATA 0x40
#define KADM5_LAST_SUCCESS 0x80
#define KADM5_LAST_FAILED 0x100
#define KADM5_POLICY 0x200
#define KADM5_POLICY_CLR 0x400
#define KADM5_ATTRIBUTES 0x800
#define KADM5_MAX_LIFE 0x1000
#define KADM5_PRINC_EXPIRE_TIME 0x2000
#define KADM5_PW_EXPIRATION 0x4000
#define KADM5_MAX_RLIFE 0x8000
#define KADM5_KVNO 0x10000
#define KADM5_TL_DATA 0x20000
#define KADM5_FAIL_AUTH_COUNT 0x40000
#define KADM5_HOOK_STAGE_PRECOMMIT 1
#define KADM5_HOOK_STAGE_POSTCOMMIT 2

#define ALL_PRINC_MASK (KADM5_PRINCIPAL | KADM5_LAST_PWD_CHANGE | \
                       KADM5_MOD_TIME | KADM5_MOD_NAME | \
                       KADM5_MKVNO | KADM5_AUX_ATTRIBUTES | \
                       KADM5_KEY_DATA | KADM5_LAST_SUCCESS | \
                       KADM5_LAST_FAILED | KADM5_POLICY | \
                       KADM5_POLICY_CLR | KADM5_ATTRIBUTES | \
                       KADM5_MAX_LIFE | KADM5_PRINC_EXPIRE_TIME | \
                       KADM5_PW_EXPIRATION | KADM5_MAX_RLIFE | \
                       KADM5_KVNO | KADM5_TL_DATA | KADM5_FAIL_AUTH_COUNT)

#define KADM5_OK 0
#define KADM5_BAD_MASK 1
#define EINVAL 2
#define KADM5_BAD_TL_TYPE 3
#define KADM5_BAD_SERVER_PARAMS 4

#define CHECK_HANDLE(handle) do {} while(0)

struct kadm5_principal_ent_t {
    char *principal;
    char *policy;
    long attributes;
    long max_life;
    time_t princ_expire_time;
    time_t pw_expiration;
    long max_renewable_life;
    int kvno;
    struct krb5_tl_data *tl_data;
    int fail_auth_count;
};

struct krb5_tl_data {
    int tl_data_type;
    struct krb5_tl_data *tl_data_next;
};

struct krb5_db_entry {
    int n_key_data;
    struct {
        int key_data_kvno;
    } *key_data;
    long attributes;
    long max_life;
    time_t expiration;
    time_t pw_expiration;
    long max_renewable_life;
    int fail_auth_count;
    long mask;
};

struct osa_princ_ent_rec {
    long aux_attributes;
    char *policy;
};

struct kadm5_policy_ent_rec {
    time_t pw_max_life;
};

struct kadm5_server_handle_t {
    void *context;
    void *hook_handles;
    void *lhandle;
};

typedef struct kadm5_principal_ent_t *kadm5_principal_ent_t;
typedef struct kadm5_policy_ent_rec kadm5_policy_ent_rec;
typedef struct krb5_db_entry krb5_db_entry;
typedef struct krb5_tl_data krb5_tl_data;
typedef struct osa_princ_ent_rec osa_princ_ent_rec;
typedef struct kadm5_server_handle_t *kadm5_server_handle_t;

extern int kdb_get_entry(kadm5_server_handle_t, void*, krb5_db_entry**, osa_princ_ent_rec*);
extern int get_policy(kadm5_server_handle_t, char*, kadm5_policy_ent_rec*, krb5_boolean*);
extern int krb5_dbe_lookup_last_pwd_change(void*, krb5_db_entry*, time_t*);
extern int krb5_dbe_update_tl_data(void*, krb5_db_entry*, krb5_tl_data*);
extern int k5_kadm5_hook_modify(void*, void*, int, kadm5_principal_ent_t, long);
extern int kdb_put_entry(kadm5_server_handle_t, krb5_db_entry*, osa_princ_ent_rec*);
extern int kadm5_free_policy_ent(void*, kadm5_policy_ent_rec*);
extern void kdb_free_entry(kadm5_server_handle_t, krb5_db_entry*, osa_princ_ent_rec*);
extern void krb5_clear_error_message(void*);