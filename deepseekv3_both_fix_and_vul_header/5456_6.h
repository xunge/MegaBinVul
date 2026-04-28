#include <stdint.h>
#include <inttypes.h>

#define SZ_64K  0x10000
#define SZ_128K 0x20000

#define XENLOG_G_WARNING ""
#define XENLOG_WARNING   ""
#define PRIpaddr "lx"
#define PRIpv "p"

typedef struct mmio_info_t {
    unsigned long gpa;
} mmio_info_t;

struct vcpu {
    struct domain *domain;
    const char *pv;
};

struct domain {
    struct {
        struct {
            unsigned long rdist_stride;
        } vgic;
    } arch;
};

extern int perfc_incr(int);
extern int __vgic_v3_rdistr_rd_mmio_read(struct vcpu *, mmio_info_t *, uint32_t);
extern int vgic_v3_rdistr_sgi_mmio_read(struct vcpu *, mmio_info_t *, uint32_t);
extern int printk(const char *fmt, ...);
extern int gdprintk(const char *fmt, ...);

static int vgicr_reads;