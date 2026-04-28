#include <stddef.h>
#include <string.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef int bool;
#define true 1
#define false 0

struct task_struct {
    void *audit_context;
};

struct cred {
    struct task_security_struct *security;
};

struct audit_buffer;

struct task_security_struct {
    u32 sid;
    u32 exec_sid;
    u32 create_sid;
    u32 keycreate_sid;
    u32 sockcreate_sid;
};

#define PROCESS__SETEXEC 0
#define PROCESS__SETFSCREATE 0
#define PROCESS__SETKEYCREATE 0
#define PROCESS__SETSOCKCREATE 0
#define PROCESS__SETCURRENT 0
#define PROCESS__DYNTRANSITION 0
#define PROCESS__PTRACE 0
#define SECCLASS_PROCESS 0

#define GFP_KERNEL 0
#define GFP_ATOMIC 0
#define CAP_MAC_ADMIN 0

#define EACCES 1
#define EINVAL 2
#define ENOMEM 3
#define EPERM 4

#define AUDIT_SELINUX_ERR 0

extern struct task_struct *current;

static int current_has_perm(struct task_struct *p, int perm);
static int security_context_to_sid(void *value, size_t size, u32 *sid, int gfp);
static int security_context_to_sid_force(void *value, size_t size, u32 *sid);
static int may_create_key(u32 sid, struct task_struct *p);
static int security_bounded_transition(u32 oldsid, u32 newsid);
static int avc_has_perm(u32 ssid, u32 tsid, u16 tclass, u32 perms, void *aux);
static u32 ptrace_parent_sid(struct task_struct *p);
static bool current_is_single_threaded(void);
static struct cred *prepare_creds(void);
static void commit_creds(struct cred *new);
static void abort_creds(struct cred *new);
static int capable(int cap);
static struct audit_buffer *audit_log_start(void *ctx, int gfp, int type);
static void audit_log_format(struct audit_buffer *ab, const char *fmt, ...);
static void audit_log_n_untrustedstring(struct audit_buffer *ab, const char *str, size_t len);
static void audit_log_end(struct audit_buffer *ab);