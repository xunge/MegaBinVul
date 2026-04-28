#include <string.h>
#include <stdbool.h>

#define BINPRM_BUF_SIZE 256
#define MNT_NOSUID 1
#define S_ISUID 0004000
#define S_ISGID 0002000
#define S_IXGRP 0000010
#define PER_CLEAR_ON_SETID 1

typedef unsigned int umode_t;
typedef int kuid_t;
typedef int kgid_t;

struct user_namespace;
struct task_struct;
struct vfsmount;

struct linux_binprm {
    struct file *file;
    struct cred *cred;
    unsigned int per_clear;
    int cred_prepared;
    char buf[BINPRM_BUF_SIZE];
};

struct inode {
    umode_t i_mode;
    kuid_t i_uid;
    kgid_t i_gid;
};

struct path {
    struct vfsmount *mnt;
};

struct file {
    struct path f_path;
};

struct vfsmount {
    unsigned int mnt_flags;
};

struct cred {
    kuid_t euid;
    kgid_t egid;
    struct user_namespace *user_ns;
};

static struct task_struct *current;

static inline kuid_t current_euid(void) { return (kuid_t){0}; }
static inline kgid_t current_egid(void) { return (kgid_t){0}; }
static inline bool task_no_new_privs(struct task_struct *task) { return false; }
static inline bool kuid_has_mapping(struct user_namespace *ns, kuid_t uid) { return true; }
static inline bool kgid_has_mapping(struct user_namespace *ns, kgid_t gid) { return true; }
static inline struct inode *file_inode(struct file *f) { return (struct inode *)0; }
static inline int security_bprm_set_creds(struct linux_binprm *bprm) { return 0; }
static inline int kernel_read(struct file *file, long offset, char *addr, unsigned long count) { return 0; }