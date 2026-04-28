#include <stdint.h>

#define XENLOG_WARNING 0
#define X86EMUL_OKAY 0
#define IOREQ_WRITE 1

struct hvm_hw_vpic {
    uint8_t dummy[256];  // Placeholder for PIC registers
};

struct domain {
    struct {
        struct {
            struct hvm_hw_vpic vpic[2];
        } hvm_domain;
    } arch;
};

struct vcpu {
    struct domain *domain;
};
extern struct vcpu *current;

void gdprintk(int level, const char *fmt, ...);
void vpic_ioport_write(struct hvm_hw_vpic *vpic, uint32_t port, uint8_t val);
uint8_t vpic_ioport_read(struct hvm_hw_vpic *vpic, uint32_t port);