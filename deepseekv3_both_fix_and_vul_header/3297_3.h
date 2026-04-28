#include <stddef.h>
#include <sys/types.h>

#define CAP_NET_ADMIN 12

typedef unsigned int kuid_t;
typedef unsigned int kgid_t;

struct net {
    void *user_ns;
    void *sysctls;
};

struct ctl_table_header {
    void *set;
};

struct ctl_table {
    int mode;
};

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

static inline kuid_t make_kuid(void *ns, int uid) { return 0; }
static inline kgid_t make_kgid(void *ns, int gid) { return 0; }
static inline int ns_capable(void *ns, int cap) { return 0; }
static inline int uid_eq(kuid_t a, kuid_t b) { return 0; }
static inline kuid_t current_euid(void) { return 0; }
static inline int in_egroup_p(kgid_t gid) { return 0; }