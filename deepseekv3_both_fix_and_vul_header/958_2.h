#include <stdlib.h>
#include <stdbool.h>

#define CMDLOG_LOGIN 0
#define ASASL_NEED_LOG (1 << 0)
#define IRCD_SASL_USE_PUID (1 << 0)
#define MU_NOBURSTLOGIN (1 << 0)
#define MU_PENDINGLOGIN (1 << 1)

typedef struct mowgli_list_t mowgli_list_t;
typedef struct entity_t entity_t;

struct mowgli_list_t {
    unsigned int length;
};

struct entity_t {
    char *name;
};

typedef struct myuser_t {
    entity_t ent;
    mowgli_list_t logins;
    unsigned int flags;
} myuser_t;

typedef struct sasl_session_t {
    char *username;
    char *authzid;
    int flags;
} sasl_session_t;

typedef struct hook_user_login_check_t {
    void *si;
    myuser_t *mu;
    bool allowed;
} hook_user_login_check_t;

typedef struct metadata_t metadata_t;
typedef struct ircd_t {
    int flags;
} ircd_t;

struct me_t {
    int maxlogins;
};

extern myuser_t *myuser_find_by_nick(const char *nick);
extern void *sasl_sourceinfo_create(sasl_session_t *p);
extern void hook_call_user_can_login(hook_user_login_check_t *req);
extern void sasl_logcommand(sasl_session_t *p, myuser_t *mu, int cmdlog, const char *format, ...);
extern entity_t *entity(myuser_t *mu);
extern metadata_t *metadata_find(myuser_t *mu, const char *key);
extern bool may_impersonate(myuser_t *source_mu, myuser_t *target_mu);
extern char *sstrdup(const char *str);
extern ircd_t *ircd;
extern struct me_t me;

#define MOWGLI_LIST_LENGTH(list) ((list)->length)