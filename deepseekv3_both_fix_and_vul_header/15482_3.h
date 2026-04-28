#include <stdbool.h>
#include <pwd.h>

struct sudoers_context;
struct sudo_auth {
    const char *name;
    int (*begin_session)(const struct sudoers_context *, struct passwd *, char ***, struct sudo_auth *);
    int flags;
};

extern struct sudo_auth auth_switch[];
extern void debug_decl(const char *, int);
extern int debug_return_int(int);

#define SUDOERS_DEBUG_AUTH 0
#define IS_DISABLED(auth) ((auth)->flags & 0x01)
#define AUTH_SUCCESS 0
#define AUTH_FAILURE 1

typedef struct sudo_auth sudo_auth;