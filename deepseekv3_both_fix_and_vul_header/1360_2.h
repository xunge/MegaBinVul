#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#define LSI_TAG_VALID 0x10000
#define LOG_UNIMP 0
#define LSI_MSG_ACTION_COMMAND 0

typedef struct SCSIRequest SCSIRequest;

typedef struct lsi_request {
    SCSIRequest *req;
    uint32_t tag;
    struct lsi_request *next;
} lsi_request;

typedef struct LSIState {
    uint32_t dbc;
    uint32_t select_tag;
    uint8_t sfbr;
    uint8_t current_lun;
    lsi_request *current;
    struct {
        lsi_request *tqh_first;
    } queue;
    int msg_action;
} LSIState;

enum {
    PHASE_CMD,
    PHASE_MI
};

static inline void qemu_log_mask(int mask, const char *fmt, ...) {
    (void)mask;
    va_list args;
    va_start(args, fmt);
    vprintf(fmt, args);
    va_end(args);
}

#define QTAILQ_FOREACH_SAFE(var, head, field, next_var) \
    for ((var) = (head)->tqh_first; \
         (var) && ((next_var) = (var)->next, 1); \
         (var) = (next_var))

/* Dummy function declarations to satisfy compiler */
static inline void trace_lsi_do_msgout(uint32_t dbc) {}
static inline void trace_lsi_do_msgout_disconnect(void) {}
static inline void trace_lsi_do_msgout_noop(void) {}
static inline void trace_lsi_do_msgout_extended(uint8_t msg, int len) {}
static inline void trace_lsi_do_msgout_ignored(const char *str) {}
static inline void trace_lsi_do_msgout_simplequeue(uint8_t tag) {}
static inline void trace_lsi_do_msgout_abort(uint32_t tag) {}
static inline void trace_lsi_do_msgout_clearqueue(uint32_t tag) {}
static inline void trace_lsi_do_msgout_busdevicereset(uint32_t tag) {}
static inline void trace_lsi_do_msgout_select(uint8_t lun) {}

static inline uint8_t lsi_get_msgbyte(LSIState *s) { return 0; }
static inline void lsi_skip_msgbytes(LSIState *s, int n) {}
static inline void lsi_disconnect(LSIState *s) {}
static inline void lsi_set_phase(LSIState *s, int phase) {}
static inline void lsi_add_msg_byte(LSIState *s, uint8_t byte) {}
static inline lsi_request *lsi_find_by_tag(LSIState *s, uint32_t tag) { return NULL; }
static inline void scsi_req_cancel(SCSIRequest *req) {}