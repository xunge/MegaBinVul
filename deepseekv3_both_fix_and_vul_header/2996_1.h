#include <stdbool.h>

typedef unsigned int u32;

struct user_namespace {
    struct user_namespace *parent;
};

struct uid_gid_extent {
    u32 lower_first;
    u32 count;
};

struct uid_gid_map {
    u32 nr_extents;
    struct uid_gid_extent extent[1];
};

typedef struct {
    u32 val;
} kuid_t;

typedef struct {
    u32 val;
} kgid_t;

#define CAP_SETUID 0
#define CAP_SETGID 1

static inline bool cap_valid(int cap) {
    return cap == CAP_SETUID || cap == CAP_SETGID;
}

static inline kuid_t make_kuid(struct user_namespace *ns, u32 uid) {
    return (kuid_t){uid};
}

static inline kgid_t make_kgid(struct user_namespace *ns, u32 gid) {
    return (kgid_t){gid};
}

static inline bool uid_eq(kuid_t left, kuid_t right) {
    return left.val == right.val;
}

static inline bool gid_eq(kgid_t left, kgid_t right) {
    return left.val == right.val;
}

static inline kuid_t current_fsuid(void) {
    return (kuid_t){0};
}

static inline kgid_t current_fsgid(void) {
    return (kgid_t){0};
}

static inline bool ns_capable(struct user_namespace *ns, int cap) {
    return false;
}