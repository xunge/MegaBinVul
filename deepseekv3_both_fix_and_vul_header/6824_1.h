#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <grp.h>

#define NFSEXP_ALLSQUASH 0x1000
#define NFSEXP_ROOTSQUASH 0x2000
#define ENOMEM 12
#define GLOBAL_ROOT_UID 0
#define GLOBAL_ROOT_GID 0
#define INVALID_UID ((uid_t)-1)
#define INVALID_GID ((gid_t)-1)

struct svc_rqst {
    struct {
        uid_t cr_uid;
        gid_t cr_gid;
        struct group_info *cr_group_info;
    } rq_cred;
};

struct svc_export {
    uid_t ex_anon_uid;
    gid_t ex_anon_gid;
};

struct group_info {
    int ngroups;
    gid_t *gid;
};

struct cred {
    uid_t fsuid;
    gid_t fsgid;
    void *cap_effective;
    void *cap_permitted;
};

typedef void *kernel_cap_t;

static int uid_eq(uid_t left, uid_t right) { return left == right; }
static int gid_eq(gid_t left, gid_t right) { return left == right; }
static struct cred *current_real_cred(void) { return NULL; }
static struct cred *prepare_creds(void) { return NULL; }
static void abort_creds(struct cred *new) {}
static void put_cred(struct cred *new) {}
static struct cred *override_creds(struct cred *new) { return NULL; }
static void revert_creds(struct cred *new) {}
static void validate_process_creds(void) {}
static void set_groups(struct cred *new, struct group_info *gi) {}
static struct group_info *groups_alloc(int size) { return NULL; }
static void groups_sort(struct group_info *gi) {}
static struct group_info *get_group_info(struct group_info *gi) { return NULL; }
static void put_group_info(struct group_info *gi) {}
static int nfsexp_flags(struct svc_rqst *rqstp, struct svc_export *exp) { return 0; }
static kernel_cap_t cap_drop_nfsd_set(kernel_cap_t cap) { return NULL; }
static kernel_cap_t cap_raise_nfsd_set(kernel_cap_t cap1, kernel_cap_t cap2) { return NULL; }