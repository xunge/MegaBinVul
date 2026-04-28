#include <stdint.h>
#include <unistd.h>

#define IS_ACTIVE(module) (1)
#define CONFIG_GNRC_SIXLOWPAN_SFR_MOCK_ARQ_TIMER 0
#define DEBUG(fmt, ...)
#define GNRC_SIXLOWPAN_FRAG_SFR_ARQ_TIMEOUT_MSG 0

typedef struct {
    uint32_t offset;
} event_t;

typedef struct {
    void* ptr;
    uint32_t type;
} msg_content_t;

typedef struct {
    event_t event;
    struct {
        msg_content_t content;
        uint32_t type;
    } msg;
} arq_timeout_event_t;

typedef struct {
    arq_timeout_event_t arq_timeout_event;
} sfr_t;

typedef struct {
    sfr_t sfr;
    uint8_t tag;
} gnrc_sixlowpan_frag_fb_t;

typedef struct {
    // dummy evtimer structure
} evtimer_t;

evtimer_t _arq_timer;

void evtimer_add_msg(evtimer_t *timer, arq_timeout_event_t *event, int pid);
pid_t _getpid(void);