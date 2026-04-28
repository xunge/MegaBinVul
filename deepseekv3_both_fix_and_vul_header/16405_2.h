#include <stdint.h>
#include <stddef.h>

#define RTAS_INSTANTIATE_MAX 0
#define RTAS_RMOBUF_MAX 0
#define PAGE_SIZE 4096
#define CONFIG_PPC64
#define FW_FEATURE_LPAR 0
#define CONFIG_RTAS_ERROR_LOGGING

typedef uint32_t u32;
typedef uint32_t __be32;

struct device_node {
    // Minimal stub for compilation
};
struct rtas_t {
    struct device_node *dev;
    u32 base;
    u32 size;
    u32 entry;
};

extern struct rtas_t rtas;
extern unsigned long rtas_rmo_buf;
extern int ibm_suspend_me_token;
extern int rtas_last_error_token;
extern unsigned long ppc64_rma_size;

static inline struct device_node *of_find_node_by_name(struct device_node *from, const char *name) { return NULL; }
static inline int of_property_read_u32(struct device_node *np, const char *propname, u32 *out) { return 0; }
static inline void of_node_put(struct device_node *node) {}
static inline int firmware_has_feature(unsigned long feature) { return 0; }
static inline int rtas_token(const char *service) { return 0; }
static inline unsigned long memblock_phys_alloc_range(unsigned long size, unsigned long align, unsigned long start, unsigned long end) { return 0; }
static inline void panic(const char *fmt, ...) {}

#define __init