#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <string.h>

#define MB(_mb)     ((uint64_t)(_mb) << 20)
#define GB(_gb)     ((uint64_t)(_gb) << 30)
#define SECINITSID_DOMU 1
#define X86_HVM_NR_SPECIAL_PAGES 8
#define X86_HVM_END_SPECIAL_REGION 0x1000
#define LAPIC_BASE_ADDRESS 0xfee00000
#define XC_PAGE_SHIFT 12
#define E820_RAM 1
#define E820_RESERVED 2
#define XEN_DOMCTL_CDF_xs_domain (1 << 0)
#define XEN_DOMCTL_CDF_hvm (1 << 1)
#define XEN_DOMCTL_CDF_hap (1 << 2)
#define XEN_X86_EMU_LAPIC (1 << 0)
#define XC_DOM_HVM_CONTAINER 1
#define XC_DOM_PV_CONTAINER 2
#define VIRQ_DOM_EXC 1
#define IOCTL_XENBUS_BACKEND_SETUP _IOC(_IOC_NONE, 'X', 0, 0)

struct e820entry {
    uint64_t addr;
    uint64_t size;
    uint32_t type;
};

struct xen_domctl_createdomain {
    uint32_t ssidref;
    uint32_t flags;
    uint32_t max_vcpus;
    int32_t max_evtchn_port;
    uint32_t max_grant_frames;
    uint32_t max_maptrack_frames;
    uint32_t grant_opts;
    struct {
        uint32_t emulation_flags;
    } arch;
};

struct xc_dom_image {
    int container_type;
    uint64_t target_pages;
    uint64_t mmio_size;
    uint64_t lowmem_end;
    uint64_t highmem_end;
    uint64_t mmio_start;
    uint32_t max_vcpus;
    uint32_t guest_domid;
    char *cmdline;
    uint32_t xenstore_domid;
    int console_evtchn;
    unsigned long console_pfn;
};

extern char *flask;
extern char *kernel;
extern char *ramdisk;
extern char *param;
extern unsigned int memory;
extern unsigned int maxmem;
extern unsigned int domid;
extern int console_evtchn;
extern unsigned long console_gfn;

typedef struct xc_interface xc_interface;

static inline uint32_t XEN_DOMCTL_GRANT_version(uint32_t v) { return v; }