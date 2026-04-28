#include <stdint.h>
#include <stddef.h>

struct si_sm_io {
    unsigned int addr_data;
    void (*io_cleanup)(void);
    unsigned int regsize;
    void *dev;
    unsigned int io_size;
    unsigned int regspacing;
    void (*inputb)(void);
    void (*outputb)(void);
};

#define DEVICE_NAME "ipmi_si"
#define ENODEV 19
#define EINVAL 22
#define EIO 5

void port_cleanup(void);
void port_inb(void);
void port_outb(void);
void port_inw(void);
void port_outw(void);
void port_inl(void);
void port_outl(void);
void dev_warn(void *dev, const char *fmt, ...);

void* request_region(unsigned long start, unsigned long length, const char *name);
void release_region(unsigned long start, unsigned long length);