#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define GFP_KERNEL 0

struct mdesc_handle;
typedef uint64_t u64;

union md_node_info {
    struct {
        u64 id;
        char *name;
        u64 parent_cfg_hdl;
    } vdev_port;
};

const u64 *mdesc_get_property(struct mdesc_handle *md, u64 node, const char *name, int *lenp);
const u64 *parent_cfg_handle(struct mdesc_handle *md, u64 node);
char *kstrdup_const(const char *s, int gfp);