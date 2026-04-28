#include <string.h>
#include <stdlib.h>

#define EINVAL 22
#define EACCES 13
#define PAGE_SIZE 4096
#define GFP_KERNEL 0
#define AA_DO_TEST 1
#define AA_ONEXEC 1
#define AUDIT_APPARMOR_DENIED 0
#define OP_SETPROCATTR 0
#define NONE 0

struct task_struct;
struct common_audit_data {
    struct {
        int op;
        const char *info;
        int error;
    } aad;
};

extern int aa_setprocattr_changehat(char *args, size_t arg_size, int test);
extern int aa_setprocattr_changeprofile(char *args, int onexec, int test);
extern int aa_setprocattr_permipc(char *args);
extern int aa_audit(int type, void *profile, int gfp, struct common_audit_data *sa, void *info);

#define COMMON_AUDIT_DATA_INIT(_d, _t) \
    do { \
        (_d)->aad.op = 0; \
        (_d)->aad.info = NULL; \
        (_d)->aad.error = 0; \
    } while (0)

extern struct task_struct *current;

static inline char *skip_spaces(const char *str) { 
    while (*str == ' ') str++;
    return (char *)str;
}