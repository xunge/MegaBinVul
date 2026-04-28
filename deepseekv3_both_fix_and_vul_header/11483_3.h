#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

struct qb_ipcs_connection_s;
typedef struct qb_ipcs_connection_s qb_ipcs_connection_t;

struct crm_client_s {
    qb_ipcs_connection_t *ipcs;
    int kind;
    unsigned int pid;
    char *id;
    char *user;
};
typedef struct crm_client_s crm_client_t;

#define CRM_DAEMON_USER NULL
#define CRM_CLIENT_IPC 0
#define FALSE 0
#define TRUE 1
#define QB_MAX(a, b) ((a) > (b) ? (a) : (b))

extern int crm_user_lookup(const char *user, uid_t *uid, gid_t *gid);
extern void CRM_LOG_ASSERT(void *ptr);
extern void crm_warn(const char *format, ...);
extern void crm_trace(const char *format, ...);
extern void crm_debug(const char *format, ...);
extern void crm_client_init(void);
extern unsigned int crm_ipcs_client_pid(qb_ipcs_connection_t *c);
extern char *crm_generate_uuid(void);
extern char *uid2username(uid_t uid);
extern void qb_ipcs_connection_auth_set(qb_ipcs_connection_t *c, uid_t uid, gid_t gid, mode_t mode);
extern void g_hash_table_insert(void *table, void *key, void *value);

extern void *client_connections;