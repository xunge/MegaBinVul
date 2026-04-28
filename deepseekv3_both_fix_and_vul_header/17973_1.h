#include <stdbool.h>

struct linux_binprm {
    struct cred *cred;
    char *filename;
    unsigned int per_clear;
    unsigned int unsafe;
    bool cap_effective;
};

struct cred {
    unsigned int uid;
    unsigned int euid;
    unsigned int suid;
    unsigned int fsuid;
    unsigned int gid;
    unsigned int egid;
    unsigned int sgid;
    unsigned int fsgid;
    unsigned int cap_permitted;
    unsigned int cap_effective;
    unsigned int cap_inheritable;
    unsigned int cap_bset;
    unsigned int securebits;
};

#define SECURE_NOROOT 0
#define SECURE_KEEP_CAPS 1
#define LSM_UNSAFE_PTRACE_CAP 0
#define PER_CLEAR_ON_SETID 0
#define CAP_SETUID 0
#define CAP_FULL_SET 0

const struct cred *current_cred(void);
int get_file_caps(struct linux_binprm *bprm, bool *effective, bool *has_cap);
void warn_setuid_and_fcaps_mixed(const char *filename);
bool issecure(int flag);
bool capable(int cap);
int audit_log_bprm_fcaps(struct linux_binprm *bprm, struct cred *new, const struct cred *old);
unsigned int cap_combine(unsigned int a, unsigned int b);
bool cap_issubset(unsigned int a, unsigned int b);
unsigned int cap_intersect(unsigned int a, unsigned int b);
bool cap_isclear(unsigned int a);
void cap_clear(unsigned int a);
unsigned int issecure_mask(int flag);