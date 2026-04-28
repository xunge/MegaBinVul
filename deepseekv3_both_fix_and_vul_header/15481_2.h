#include <stdbool.h>
#include <stddef.h>
#include <sys/types.h>
#include <pwd.h>

struct sudoers_context {
    struct {
        char **argv;
    } runas;
};

struct sudo_auth {
    const char *name;
    unsigned int flags;
    int (*init)(const struct sudoers_context *, struct passwd *, struct sudo_auth *);
};

#define AUTH_SUCCESS 0
#define AUTH_FAILURE 1
#define AUTH_ERROR 2

#define MODE_NONINTERACTIVE 0x01

#define FLAG_NONINTERACTIVE 0x01
#define FLAG_DISABLED 0x02
#define FLAG_ONEANDONLY 0x04
#define FLAG_STANDALONE 0x08

#define ISSET(x, y) ((x) & (y))
#define SET(x, y) ((x) |= (y))
#define IS_DISABLED(auth) (ISSET((auth)->flags, FLAG_DISABLED))
#define IS_STANDALONE(auth) (ISSET((auth)->flags, FLAG_STANDALONE))

#define SUDOERS_DEBUG_AUTH 0
#define SLOG_SEND_MAIL 0

extern struct sudo_auth auth_switch[];
extern bool standalone;

void audit_failure(const struct sudoers_context *ctx, char **argv, const char *msg);
void log_warningx(const struct sudoers_context *ctx, int flags, const char *msg);

#define debug_decl(func, flags)
#define debug_return_int(ret) return ret

#define N_(x) x

typedef struct sudo_auth sudo_auth;