#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdarg.h>

#define B43_FWTYPE_PROPRIETARY 0
#define B43_FWTYPE_OPENSOURCE 1
#define B43_NR_FWTYPES 2
#define B43_QOS_QUEUE_NUM 4
#define GFP_KERNEL 0

struct work_struct {
};

struct b43_hw {
    int queues;
};

struct b43_wl {
    struct work_struct firmware_load;
    struct b43_wldev *current_dev;
    struct b43_hw *hw;
    bool hw_registred;
};

struct b43_wldev {
    struct b43_wl *wl;
    struct {
        bool opensource;
    } fw;
    void *dev;
};

struct b43_request_fw_context {
    struct b43_wldev *dev;
    int req_type;
    bool fatal_failure;
    char errors[B43_NR_FWTYPES][256];
};

static bool modparam_qos;

static void *kzalloc(size_t size, int flags) { return calloc(1, size); }
static void kfree(void *ptr) { free(ptr); }
static void b43err(void *wl, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    va_end(args);
}
static void b43_print_fw_helptext(void *wl, int flag) {}
static int b43_try_request_fw(struct b43_request_fw_context *ctx) { return 0; }
static int ieee80211_register_hw(void *hw) { return 0; }
static void b43_leds_register(struct b43_wldev *dev) {}
static void b43_one_core_detach(void *dev) {}

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))