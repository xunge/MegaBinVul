#include <stdint.h>
#include <stdio.h>

#define DEBUG_NE2000
#define E8390_CMD 0x00
#define E8390_STOP 0x01
#define E8390_RREAD 0x08
#define E8390_RWRITE 0x10
#define E8390_TRANS 0x04
#define ENISR_RESET 0x01
#define ENISR_RDC 0x20
#define ENISR_TX 0x02
#define ENTSR_PTX 0x01
#define NE2000_PMEM_END 0x2000
#define NE2000_PMEM_SIZE 0x2000

#define EN0_STARTPG 0x01
#define EN0_STOPPG 0x02
#define EN0_BOUNDARY 0x03
#define EN0_IMR 0x04
#define EN0_TPSR 0x05
#define EN0_TCNTLO 0x06
#define EN0_TCNTHI 0x07
#define EN0_RSARLO 0x08
#define EN0_RSARHI 0x09
#define EN0_RCNTLO 0x0A
#define EN0_RCNTHI 0x0B
#define EN0_RXCR 0x0C
#define EN0_DCFG 0x0D
#define EN0_ISR 0x0E
#define EN1_PHYS 0x10
#define EN1_CURPAG 0x17
#define EN1_MULT 0x18

typedef struct NE2000State {
    uint8_t cmd;
    uint8_t isr;
    uint8_t imr;
    uint8_t start;
    uint8_t stop;
    uint8_t boundary;
    uint8_t tpsr;
    uint16_t tcnt;
    uint16_t rsar;
    uint16_t rcnt;
    uint8_t rxcr;
    uint8_t dcfg;
    uint8_t phys[6];
    uint8_t curpag;
    uint8_t mult[8];
    uint8_t tsr;
    uint8_t *mem;
    void *nic;
} NE2000State;

void ne2000_update_irq(NE2000State *s);
void qemu_send_packet(void *nic, uint8_t *buf, int size);
void *qemu_get_queue(void *nic);