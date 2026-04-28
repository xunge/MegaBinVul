#include <stdint.h>
#include <string.h>

typedef struct libxl__gc libxl__gc;

struct libxl_ctx {
    void *xch;
};

typedef struct libxl_ctx libxl_ctx;
typedef struct libxl_domain_build_info libxl_domain_build_info;
typedef struct libxl__domain_build_state libxl__domain_build_state;

struct xc_dom_image {
    int pvh_enabled;
    int container_type;
    int flags;
    int console_evtchn;
    int console_domid;
    int xenstore_evtchn;
    int xenstore_domid;
    int claim_enabled;
    unsigned int nr_vmemranges;
    struct vmemrange *vmemranges;
    unsigned int nr_vnodes;
    uint32_t *vnode_to_pnode;
    uint64_t console_pfn;
    uint64_t xenstore_pfn;
};

struct libxl__file_reference {
    char *path;
    void *data;
    size_t size;
    int mapped;
};

struct vmemrange {
    uint64_t start;
    uint64_t end;
    uint32_t flags;
    uint32_t nid;
};

struct libxl__domain_build_state {
    char *pv_cmdline;
    int pvh_enabled;
    struct libxl__file_reference pv_kernel;
    struct libxl__file_reference pv_ramdisk;
    int console_port;
    int console_domid;
    int store_port;
    int store_domid;
    int console_mfn;
    int store_mfn;
    unsigned int num_vmemranges;
    struct vmemrange *vmemranges;
};

struct libxl_vnode_info {
    uint32_t pnode;
};

struct libxl_domain_build_info {
    unsigned int num_vnuma_nodes;
    struct libxl_vnode_info *vnuma_nodes;
    int claim_mode;
    union {
        struct {
            char *features;
        } pv;
    } u;
};

#define ERROR_FAIL (-1)
#define LOGE(level, msg)
#define LOG(level, fmt, ...)
#define libxl_defbool_val(defbool) ((defbool) ? 1 : 0)
#define XC_DOM_PV_CONTAINER 1

libxl_ctx *libxl__gc_owner(libxl__gc *gc);
void xc_dom_loginit(void *xch);
struct xc_dom_image *xc_dom_allocate(void *xch, char *cmdline, char *features);
int xc_dom_kernel_mem(struct xc_dom_image *dom, void *data, size_t size);
int xc_dom_kernel_file(struct xc_dom_image *dom, char *path);
int xc_dom_ramdisk_mem(struct xc_dom_image *dom, void *data, size_t size);
int xc_dom_ramdisk_file(struct xc_dom_image *dom, char *path);
void *xc_dom_malloc(struct xc_dom_image *dom, size_t size);
int libxl__vnuma_build_vmemrange_pv(libxl__gc *gc, uint32_t domid, libxl_domain_build_info *info, libxl__domain_build_state *state);
int libxl__vnuma_config_check(libxl__gc *gc, libxl_domain_build_info *info, libxl__domain_build_state *state);
int set_vnuma_info(libxl__gc *gc, uint32_t domid, libxl_domain_build_info *info, libxl__domain_build_state *state);
int libxl__build_dom(libxl__gc *gc, uint32_t domid, libxl_domain_build_info *info, libxl__domain_build_state *state, struct xc_dom_image *dom);
int xc_dom_feature_translated(struct xc_dom_image *dom);
uint64_t xc_dom_p2m(struct xc_dom_image *dom, uint64_t pfn);
void libxl__file_reference_unmap(struct libxl__file_reference *fr);
void xc_dom_release(struct xc_dom_image *dom);