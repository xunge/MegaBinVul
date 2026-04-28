#include <stdbool.h>
#include <time.h>
#include <stdarg.h>

typedef struct mowgli_node_t {
    void *data;
    struct mowgli_node_t *next;
    struct mowgli_node_t *prev;
} mowgli_node_t;

struct sasl_session {
    char pendingeid[1];
    char authzeid[1];
    char authzid[1];
    struct {
        char *name;
    } *mechptr;
};

struct user {
    char *nick;
    struct myuser *myuser;
};

struct myuser {
    char *uid;
    time_t lastlogin;
    struct {
        mowgli_node_t *head;
    } logins;
};

struct entity {
    char *name;
};

extern struct {
    char *nick;
} *saslsvs;

#define MOWGLI_FUNC_NAME __func__
#define LG_INFO 0
#define LOGIN_CANCELLED_STR "Login cancelled"
#define CMDLOG_ADMIN 0
#define CMDLOG_LOGIN 0
#define CURRTIME time(NULL)
#define MOWGLI_ITER_FOREACH(node, head) for (mowgli_node_t *(node) = (head); (node) != NULL; (node) = (node)->next)

bool is_soper(struct myuser *mu);
void slog(int level, const char *format, ...);
void notice(const char *source, const char *target, const char *text, ...);
struct myuser *myuser_find_uid(const char *uid);
void logcommand_user(void *svs, struct user *u, int cmdlog, const char *format, ...);
bool ircd_on_logout(struct user *u, const char *name);
void myuser_login(void *svs, struct user *u, struct myuser *mu, bool flag);
struct entity *entity(struct myuser *mu);
void mowgli_node_delete(mowgli_node_t *n, void *list);
void mowgli_node_free(mowgli_node_t *n);