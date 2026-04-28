#include <stdbool.h>
#include <stdlib.h>

#define NUM_DLCI 256

enum dlci_state {
    DLCI_CLOSED,
    DLCI_OPENING,
    DLCI_OPEN,
    DLCI_CLOSING
};

struct list_head {
    struct list_head *next, *prev;
};

struct gsm_msg {
    struct list_head list;
};

struct gsm_dlci {
    bool dead;
    enum dlci_state state;
};

struct gsm_mux {
    bool dead;
    int mutex;
    struct gsm_dlci *dlci[NUM_DLCI];
    int kick_timer;
    int t2_timer;
    int ka_timer;
    int tx_work;
    int event;
    bool has_devices;
    int num;
    void *tty;
    struct list_head tx_ctrl_list;
    struct list_head tx_data_list;
};

#define list_for_each_entry_safe(pos, n, head, member) \
    for (pos = NULL, n = NULL; pos != (void *)(head); pos = n)

#define INIT_LIST_HEAD(ptr) do { \
    (ptr)->next = (ptr); (ptr)->prev = (ptr); \
} while (0)

static inline void mutex_lock(int *mutex) { (void)mutex; }
static inline void mutex_unlock(int *mutex) { (void)mutex; }
static inline void wait_event(int event, int condition) { (void)event; (void)condition; }
static inline void del_timer_sync(int *timer) { (void)timer; }
static inline void flush_work(int *work) { (void)work; }
static inline void tty_ldisc_flush(void *tty) { (void)tty; }

extern void gsm_dlci_begin_close(struct gsm_dlci *dlci);
extern void gsm_dlci_release(struct gsm_dlci *dlci);
extern void gsm_unregister_devices(void *driver, int num);
extern void *gsm_tty_driver;