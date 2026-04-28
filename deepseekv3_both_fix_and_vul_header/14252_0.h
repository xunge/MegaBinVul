#include <unistd.h>
#include <stdlib.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>

#define INIT_MSG 1
#define CLONE_FLAGS_ATTR 2
#define ROOTLESS_EUID_ATTR 3
#define OOM_SCORE_ADJ_ATTR 4
#define NS_PATHS_ATTR 5
#define UIDMAP_ATTR 6
#define GIDMAP_ATTR 7
#define UIDMAPPATH_ATTR 8
#define GIDMAPPATH_ATTR 9
#define SETGROUP_ATTR 10
#define MOUNT_SOURCES_ATTR 11

#define NLA_HDRLEN ((int)NLMSG_ALIGN(sizeof(struct nlattr)))
#define NLA_ALIGN(len) (((len) + 3) & ~3)

struct nlconfig_t {
    char *data;
    int cloneflags;
    int is_rootless_euid;
    char *oom_score_adj;
    size_t oom_score_adj_len;
    char *namespaces;
    size_t namespaces_len;
    char *uidmap;
    size_t uidmap_len;
    char *gidmap;
    size_t gidmap_len;
    char *uidmappath;
    size_t uidmappath_len;
    char *gidmappath;
    size_t gidmappath_len;
    int is_setgroup;
    char *mountsources;
    size_t mountsources_len;
};

static inline int32_t readint32(char *addr) {
    return *(int32_t *)addr;
}

static inline int8_t readint8(char *addr) {
    return *(int8_t *)addr;
}

__attribute__((noreturn)) void bail(const char *fmt, ...);