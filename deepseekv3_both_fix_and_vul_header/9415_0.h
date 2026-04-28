#include <stdint.h>
#include <assert.h>

#define MAX_CPU 4
#define OPENPIC_MAX_TMR 4
#define EINVAL 22

typedef struct QEMUFile QEMUFile;

typedef struct IRQQueue {
    int dummy;
} IRQQueue;

typedef struct IRQSource {
    uint32_t ivpr;
    uint32_t idr;
    uint32_t destmask;
    int32_t last_cpu;
    int32_t pending;
} IRQSource;

typedef struct IRQDest {
    int32_t ctpr;
    IRQQueue raised;
    IRQQueue servicing;
    uint32_t outputs_active;
} IRQDest;

typedef struct OpenPICTimer {
    uint32_t tccr;
    uint32_t tbcr;
} OpenPICTimer;

typedef struct OpenPICState {
    uint32_t gcr;
    uint32_t vir;
    uint32_t pir;
    uint32_t spve;
    uint32_t tfrr;
    unsigned int nb_cpus;
    unsigned int max_irq;
    IRQDest dst[MAX_CPU];
    OpenPICTimer timers[OPENPIC_MAX_TMR];
    IRQSource *src;
} OpenPICState;

void qemu_get_be32s(QEMUFile *f, uint32_t *pv);
void qemu_get_sbe32s(QEMUFile *f, int32_t *pv);
uint32_t qemu_get_be32(QEMUFile *f);
void qemu_get_buffer(QEMUFile *f, uint8_t *buf, int size);
void openpic_load_IRQ_queue(QEMUFile *f, IRQQueue *q);
void write_IRQreg_idr(OpenPICState *opp, int n, uint32_t val);
void write_IRQreg_ivpr(OpenPICState *opp, int n, uint32_t val);