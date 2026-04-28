#include <stdint.h>

typedef int irqreturn_t;
typedef uint16_t u16;

#define IRQ_HANDLED 1

struct snd_msnd {
    void *mappedbase;
    void *DSPQ;
    unsigned int io;
};

#define DSPQ_DATA_BUFF 0
#define JQS_wTail 0
#define JQS_wHead 0
#define JQS_wSize 0
#define HP_RXL 0

static inline uint16_t readw(void *addr) { return *(volatile uint16_t *)addr; }
static inline void writew(uint16_t value, void *addr) { *(volatile uint16_t *)addr = value; }
static inline uint8_t inb(unsigned int port) { return *(volatile uint8_t *)port; }
static void snd_msnd_eval_dsp_msg(struct snd_msnd *chip, uint16_t msg);