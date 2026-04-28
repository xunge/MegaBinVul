#include <stdbool.h>

#define SUDOERS_DEBUG_AUTH 0
#define IS_DISABLED(auth) (0)
#define AUTH_SUCCESS 0
#define AUTH_FAILURE 1
#define AUTH_ERROR (-1)

typedef struct sudo_auth {
    const char *name;
    int (*end_session)(struct sudo_auth *);
    struct sudo_auth *next;
} sudo_auth;

extern sudo_auth *auth_switch;

#define debug_decl(func, level)
#define debug_return_int(ret) return (ret)