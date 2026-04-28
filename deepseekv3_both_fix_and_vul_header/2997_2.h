#include <stdbool.h>
#include <stdint.h>

#define CAP_SETUID 0
#define CAP_SETGID 1
#define CAP_LAST_CAP 2

typedef uint32_t u32;
typedef struct { u32 val; } kuid_t;
typedef struct { u32 val; } kgid_t;

struct uid_gid_map {
    unsigned int nr_extents;
    struct {
        u32 first;
        u32 lower_first;
        u32 count;
    } extent[1];
};

struct user_namespace {
    struct user_namespace *parent;
};

struct file {
    const struct cred *f_cred;
};

struct cred {
    kuid_t fsuid;
    kgid_t fsgid;
};

static inline bool uid_eq(kuid_t left, kuid_t right) { return left.val == right.val; }
static inline bool gid_eq(kgid_t left, kgid_t right) { return left.val == right.val; }
static inline kuid_t make_kuid(struct user_namespace *ns, u32 uid) { return (kuid_t){ uid }; }
static inline kgid_t make_kgid(struct user_namespace *ns, u32 gid) { return (kgid_t){ gid }; }
static inline bool cap_valid(int cap) { return cap >= 0 && cap < CAP_LAST_CAP; }
static inline bool ns_capable(struct user_namespace *ns, int cap) { return true; }
static inline bool file_ns_capable(const struct file *file, struct user_namespace *ns, int cap) { return true; }
static inline kuid_t current_fsuid(void) { return (kuid_t){ 0 }; }
static inline kgid_t current_fsgid(void) { return (kgid_t){ 0 }; }