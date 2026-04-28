#include <stdint.h>

#define XENLOG_WARNING 0
#define IOREQ_WRITE 1
#define X86EMUL_OKAY 0

struct PITState;
struct vcpu;

static inline struct vcpu *current;
static inline struct PITState *vcpu_vpit(struct vcpu *);
static inline void pit_ioport_write(struct PITState *, uint32_t, uint32_t);
static inline uint32_t pit_ioport_read(struct PITState *, uint32_t);
static inline void gdprintk(int, const char *, ...);