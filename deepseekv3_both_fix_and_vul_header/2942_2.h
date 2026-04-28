#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

struct nsproxy;
struct user_namespace;
struct cred;
struct mm_struct {
    int mm_users;
};
struct fs_struct {
    int users;
};
struct task_struct {
    struct mm_struct *mm;
    struct fs_struct *fs;
};

#define CAP_SYS_ADMIN 0
#define EINVAL 22
#define EPERM 1
#define ENOMEM 12

#define atomic_read(v) (*(v))
#define ns_capable(ns, cap) 0
#define current_user_ns() NULL
#define prepare_creds() NULL
#define put_user_ns(ns) 
#define set_cred_user_ns(cred, ns) 
#define get_user_ns(ns) NULL
#define commit_creds(cred) 0

extern struct task_struct *current;