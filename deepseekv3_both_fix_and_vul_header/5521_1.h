#include <stdint.h>

#define XENLOG_WARNING 0
#define RTC_CMOS_SIZE 128
#define IOREQ_WRITE 1
#define X86EMUL_OKAY 0
#define X86EMUL_UNHANDLEABLE 1

struct RTCState {
    struct {
        uint8_t cmos_index;
    } hw;
};

struct vcpu;
struct vcpu *current;

void gdprintk(int level, const char *fmt, ...);
struct RTCState *vcpu_vrtc(struct vcpu *v);
int rtc_ioport_write(struct RTCState *s, uint32_t addr, uint8_t val);
uint8_t rtc_ioport_read(struct RTCState *s, uint32_t addr);