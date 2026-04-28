#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint32_t evtchn_port_t;
typedef uint32_t event_word_t;

struct evtchn_loop_ctrl;
struct evtchn_fifo_control_block {
    uint32_t dummy;
    uint32_t head[1];
};
struct evtchn_fifo_queue {
    uint32_t dummy;
    uint32_t head[1];
};
extern struct evtchn_fifo_queue cpu_queue;

#define per_cpu(var, cpu) (var)
#define virt_rmb() do {} while (0)
#define clear_linked(word) (0)
#define evtchn_fifo_is_pending(port) (0)
#define evtchn_fifo_is_masked(port) (0)
#define clear_bit(bit, addr) do {} while (0)
#define unlikely(x) (x)
#define pr_warn(fmt, ...) do {} while (0)

static event_word_t *event_word_from_port(evtchn_port_t port) { return NULL; }
static void handle_irq_for_port(evtchn_port_t port, ...) {}