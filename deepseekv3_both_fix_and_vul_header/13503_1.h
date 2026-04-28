#include <stdbool.h>
#include <stdint.h>
#include <errno.h>
#include <assert.h>
#include <stddef.h>

#define US_PER_MS 1000
#define ETIMEDOUT 110
#define ENOMEM 12
#define GNRC_NETERR_SUCCESS 0

#define IS_ACTIVE(x) (x)
#define IS_USED(x) (x)
#define CONFIG_GNRC_SIXLOWPAN_SFR_MOCK_ARQ_TIMER 0
#define CONFIG_GNRC_SIXLOWPAN_SFR_FRAG_RETRIES 3
#define MODULE_GNRC_SIXLOWPAN_FRAG_SFR_CONGURE 1
#define MODULE_GNRC_SIXLOWPAN_FRAG_SFR_STATS 1

#define DEBUG(fmt, ...)

typedef struct {
    uint16_t tag;
    struct {
        struct {
            void *next;
        } window;
        uint32_t arq_timeout;
        struct {
            struct {
                struct {
                    void *ptr;
                } content;
            } msg;
        } arq_timeout_event;
        unsigned int frags_sent;
    } sfr;
    void *pkt;
} gnrc_sixlowpan_frag_fb_t;

typedef struct {
    struct {
        struct {
            void *next;
        } super;
        uint32_t send_time;
        unsigned int resends;
    } super;
    uint32_t offset;
} _frag_desc_t;

struct {
    struct {
        unsigned int by_timeout;
    } fragment_resends;
} _stats;

uint32_t xtimer_now_usec(void);
void gnrc_sixlowpan_frag_sfr_congure_snd_report_frags_timeout(gnrc_sixlowpan_frag_fb_t *fbuf);
void _shrink_window(gnrc_sixlowpan_frag_fb_t *fbuf);
unsigned _frag_seq(_frag_desc_t *frag_desc);
bool _frag_ack_req(_frag_desc_t *frag_desc);
unsigned _frag_size(_frag_desc_t *frag_desc);
int _resend_frag(void *frag, gnrc_sixlowpan_frag_fb_t *fbuf);
void gnrc_sixlowpan_frag_sfr_congure_snd_report_frag_sent(gnrc_sixlowpan_frag_fb_t *fbuf);
void _retry_datagram(gnrc_sixlowpan_frag_fb_t *fbuf);
void clist_foreach(void *list, void (*func)(void *, void *), void *arg);
void _report_non_ack_req_window_sent(void *frag, void *fbuf);
unsigned clist_count(void *list);
void _sched_arq_timeout(gnrc_sixlowpan_frag_fb_t *fbuf, uint32_t offset);
void _send_abort_frag(void *pkt, gnrc_sixlowpan_frag_fb_t *fbuf, bool flag, int code);
void _clean_up_fbuf(gnrc_sixlowpan_frag_fb_t *fbuf, int error_no);