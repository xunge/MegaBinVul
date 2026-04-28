#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <pwd.h>

struct sudoers_context;
struct sudoers_parse_tree;
struct defaults_list;
struct cmndspec;

struct cmnd_info {
    char *cmnd_path;
    struct stat cmnd_stat;
    int status;
};

struct sudo_nss {
    int (*query)(struct sudoers_context *, struct sudo_nss *, struct passwd *);
    struct sudoers_parse_tree *parse_tree;
    struct {
        struct sudo_nss *tqe_next;
    } entries;
};

struct sudo_nss_list {
    struct sudo_nss *tqh_first;
};

struct sudoers_context {
    struct {
        char *cmnd;
        struct stat *cmnd_stat;
        struct passwd *pw;
    } user;
};

typedef int (*sudoers_lookup_callback_fn_t)(void);

#define FLAG_NO_USER 0x01
#define FLAG_NO_HOST 0x02
#define VALIDATE_ERROR 0x04
#define VALIDATE_SUCCESS 0x08
#define VALIDATE_FAILURE 0x10
#define UNSPEC -1
#define ALLOW 1
#define SETDEF_GENERIC 0
#define PERM_RUNAS 0
#define SUDOERS_DEBUG_PARSER 0

#define SET(a, b) ((a) |= (b))
#define debug_decl(a, b)
#define debug_return_uint(a) return (a)

unsigned int sudoers_lookup_pseudo(struct sudo_nss_list *snl, struct sudoers_context *ctx,
    time_t now, sudoers_lookup_callback_fn_t callback, void *cb_data, int pwflag);
bool set_perms(struct sudoers_context *ctx, int perm);
int sudoers_lookup_check(struct sudo_nss *nss, struct sudoers_context *ctx,
    unsigned int *validated, struct cmnd_info *info, time_t now,
    sudoers_lookup_callback_fn_t callback, void *cb_data, struct cmndspec **cs,
    struct defaults_list **defs);
bool sudo_nss_can_continue(struct sudo_nss *nss, int m);
bool update_defaults(struct sudoers_context *ctx, struct sudoers_parse_tree *parse_tree,
    struct defaults_list *defs, int type, bool quiet);
bool apply_cmndspec(struct sudoers_context *ctx, struct cmndspec *cs);
bool restore_perms(void);

#define TAILQ_FOREACH(var, head, field) \
    for ((var) = (head)->tqh_first; (var); (var) = (var)->field.tqe_next)