#include <stdbool.h>
#include <pwd.h>

struct sudoers_context;
typedef struct sudo_auth {
    const char *name;
    int (*cleanup)(const struct sudoers_context *, struct passwd *, struct sudo_auth *, bool);
} sudo_auth;
extern sudo_auth auth_switch[];

#define SUDOERS_DEBUG_AUTH 0
#define IS_DISABLED(auth) 0
#define AUTH_SUCCESS 0
#define AUTH_ERROR (-1)

#define debug_decl(func, level)
#define debug_return_int(val) return (val)