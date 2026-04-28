#include <stdint.h>

typedef uint16_t u16;

#include <sys/socket.h>
#include <unistd.h>

#define AUDIT_LIST 1
#define AUDIT_ADD 2
#define AUDIT_DEL 3
#define AUDIT_GET 4
#define AUDIT_SET 5
#define AUDIT_GET_FEATURE 6
#define AUDIT_SET_FEATURE 7
#define AUDIT_LIST_RULES 8
#define AUDIT_ADD_RULE 9
#define AUDIT_DEL_RULE 10
#define AUDIT_SIGNAL_INFO 11
#define AUDIT_TTY_GET 12
#define AUDIT_TTY_SET 13
#define AUDIT_TRIM 14
#define AUDIT_MAKE_EQUIV 15
#define AUDIT_USER 16
#define AUDIT_FIRST_USER_MSG 17
#define AUDIT_LAST_USER_MSG 18
#define AUDIT_FIRST_USER_MSG2 19
#define AUDIT_LAST_USER_MSG2 20

#define ECONNREFUSED 111
#define EOPNOTSUPP 95
#define EPERM 1
#define EINVAL 22

#define CAP_AUDIT_CONTROL 30
#define CAP_AUDIT_WRITE 29

struct sk_buff;
struct user_namespace;
struct pid_namespace;

extern struct user_namespace init_user_ns;
extern struct pid_namespace init_pid_ns;

#define current_user_ns() (&init_user_ns)
#define task_active_pid_ns(task) (&init_pid_ns)
#define current (void*)0
#define capable(x) 1