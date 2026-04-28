#include <string.h>
#include <stdlib.h>
#include <errno.h>

#define EINVAL 22
#define EACCES 13
#define ENOMEM 12
#define PAGE_SIZE 4096

#define AA_DO_TEST 1
#define AA_ONEXEC 1
#define GFP_KERNEL 0

struct task_struct {
    int dummy;
};
extern struct task_struct *current;

struct common_audit_data {
    int type;
    void *aad;
};
struct apparmor_audit_data {
    int profile;
    int op;
    char *info;
    int error;
};

#define LSM_AUDIT_DATA_NONE 0
#define OP_SETPROCATTR 0
#define AUDIT_APPARMOR_DENIED 0

extern int aa_current_profile(void);
extern void aa_audit_msg(int, struct common_audit_data *, void *);
extern int aa_setprocattr_changehat(char *, size_t, int);
extern int aa_setprocattr_changeprofile(char *, int, int);
extern char *strim(char *);
extern char *strsep(char **, const char *);
extern char *skip_spaces(const char *);

static inline void *kmalloc(size_t size, int flags) {
    return malloc(size);
}

static inline void kfree(void *ptr) {
    free(ptr);
}