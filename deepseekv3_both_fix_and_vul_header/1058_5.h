#include <errno.h>
#include <stddef.h>

struct platform_device {
    struct {
        struct {
            void *parent;
        } dev;
    };
};

struct memstick_host {
    void (*request)(struct memstick_host *);
    int (*set_param)(struct memstick_host *, int, int);
    unsigned int caps;
};

struct rtsx_ucr;

struct rtsx_usb_ms {
    struct rtsx_ucr *ucr;
    struct memstick_host *msh;
    struct platform_device *pdev;
    unsigned int power_mode;
    int host_mutex;
    void *handle_req;
    void *poll_card;
};

enum {
    MEMSTICK_POWER_OFF = 0,
    MEMSTICK_CAP_PAR4 = 1
};

static void rtsx_usb_ms_handle_req(void *work) {}
static void rtsx_usb_ms_poll_card(void *work) {}
static void rtsx_usb_ms_request(struct memstick_host *msh) {}
static int rtsx_usb_ms_set_param(struct memstick_host *msh, int param, int value) { return 0; }