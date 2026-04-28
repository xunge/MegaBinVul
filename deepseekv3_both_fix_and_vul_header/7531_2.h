#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define DIV_ROUND_UP(n, d) (((n) + (d) - 1) / (d))
#define BITS_PER_BYTE 8
#define ENOMEM 12
#define EFAULT 14

struct domain {
    struct {
        struct {
            struct sh_dirty_vram *dirty_vram;
        } hvm;
    } arch;
    void *dirty_cpumask;
};

struct sh_dirty_vram {
    unsigned long begin_pfn;
    unsigned long end_pfn;
};

#define XEN_GUEST_HANDLE(type) void*
#define p2m_ram_logdirty 0
#define p2m_ram_rw 0

void *vzalloc(unsigned int size);
void vfree(void *addr);
void *xzalloc(size_t size);
void xfree(void *addr);
int paging_mode_log_dirty(struct domain *d);
int paging_log_dirty_enable(struct domain *d, bool enable);
void paging_lock(struct domain *d);
void paging_unlock(struct domain *d);
void p2m_change_type_range(struct domain *d, unsigned long start, unsigned long end, int old_type, int new_type);
void guest_flush_tlb_mask(struct domain *d, void *mask);
void domain_pause(struct domain *d);
void domain_unpause(struct domain *d);
void p2m_flush_hardware_cached_dirty(struct domain *d);
void paging_log_dirty_range(struct domain *d, unsigned long begin_pfn, unsigned int nr_frames, uint8_t *bitmap);
int copy_to_guest(XEN_GUEST_HANDLE(void) dest, void *src, unsigned int size);

#define xzalloc(type) ((type *)xzalloc(sizeof(type)))