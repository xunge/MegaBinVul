#include <signal.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define AUTH_FAILURE 0
#define AUTH_SUCCESS 1
#define AUTH_INTR 2
#define AUTH_NONINTERACTIVE 3
#define AUTH_ERROR 4

#define FLAG_DISABLED (1 << 0)
#define FLAG_BAD_PASSWORD (1 << 1)
#define FLAG_NO_USER_INPUT (1 << 2)

#define SUDOERS_DEBUG_AUTH 0
#define SLOG_SEND_MAIL 0
#define SUDO_CONV_PROMPT_ECHO_OFF 0

#define IS_DISABLED(auth) ((auth)->flags & FLAG_DISABLED)
#define IS_NONINTERACTIVE(auth) ((auth)->flags & FLAG_NO_USER_INPUT)
#define SET(var, flag) ((var) |= (flag))
#define FALLTHROUGH

struct sudoers_context {
    struct {
        const char **argv;
    } runas;
};

struct passwd;

struct sudo_conv_callback;

struct sudo_auth {
    const char *name;
    int (*setup)(const struct sudoers_context *, struct passwd *, char **, struct sudo_auth *);
    int (*verify)(const struct sudoers_context *, struct passwd *, const char *, struct sudo_auth *, struct sudo_conv_callback *);
    int flags;
    int status;
};

extern struct sudo_auth auth_switch[];
extern unsigned int def_passwd_tries;
extern bool standalone;

void audit_failure(const struct sudoers_context *ctx, const char **argv, const char *msg);
void log_warningx(const struct sudoers_context *ctx, int slog, const char *msg);
void log_auth_failure(const struct sudoers_context *ctx, unsigned int validated, unsigned int ntries);
char *auth_getpass(const char *prompt, int type, struct sudo_conv_callback *callback);
void freezero(void *ptr, size_t len);
void pass_warn(void);
bool user_interrupted(void);
void debug_decl(int func, int level);
int debug_return_int(int ret);

#define N_(x) x

typedef struct sudo_auth sudo_auth;