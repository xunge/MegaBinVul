#include <stddef.h>

struct si_sm_io {
    unsigned long addr_data;
    void (*io_cleanup)(struct si_sm_io *io);
    unsigned int regsize;
    void *dev;
    unsigned int io_size;
    unsigned int regspacing;
    void *addr;
    void (*inputb)(struct si_sm_io *io, unsigned int offset);
    void (*outputb)(struct si_sm_io *io, unsigned int offset, unsigned char val);
};

#define DEVICE_NAME "ipmi_si"
#define ENODEV 19
#define EINVAL 22
#define EIO 5

void mem_cleanup(struct si_sm_io *io);
void intf_mem_inb(struct si_sm_io *io, unsigned int offset);
void intf_mem_outb(struct si_sm_io *io, unsigned int offset, unsigned char val);
void intf_mem_inw(struct si_sm_io *io, unsigned int offset);
void intf_mem_outw(struct si_sm_io *io, unsigned int offset, unsigned short val);
void intf_mem_inl(struct si_sm_io *io, unsigned int offset);
void intf_mem_outl(struct si_sm_io *io, unsigned int offset, unsigned int val);
void mem_inq(struct si_sm_io *io, unsigned int offset);
void mem_outq(struct si_sm_io *io, unsigned int offset, unsigned long long val);
void mem_region_cleanup(struct si_sm_io *io, int idx);
void dev_warn(void *dev, const char *fmt, ...);
void *ioremap(unsigned long addr, unsigned long size);
void *request_mem_region(unsigned long start, unsigned long len, const char *name);