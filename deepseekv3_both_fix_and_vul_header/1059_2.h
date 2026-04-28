#include <stdbool.h>
#include <stddef.h>

struct platform_device;
struct memstick_host;

struct memstick_request {
    int error;
};

struct work_struct {
    // dummy work_struct implementation
};

struct mutex {
    // dummy mutex implementation  
};

struct rtsx_usb_ms {
    struct memstick_host *msh;
    bool eject;
    struct work_struct handle_req;
    struct mutex host_mutex;
    struct memstick_request *req;
};

#define ENOMEDIUM 123
#define dev_dbg(dev, fmt, ...) 
#define ms_dev(host) NULL
#define dev_name(dev) ""
#define pm_runtime_active(dev) false
#define pm_runtime_put(dev) 
#define pm_runtime_disable(dev) 

static inline void *platform_get_drvdata(struct platform_device *pdev) { return NULL; }
static inline void platform_set_drvdata(struct platform_device *pdev, void *data) {}
static inline void cancel_work_sync(struct work_struct *work) {}
static inline void mutex_lock(struct mutex *lock) {}
static inline void mutex_unlock(struct mutex *lock) {}
static inline int memstick_next_req(struct memstick_host *msh, struct memstick_request **req) { return 0; }
static inline void memstick_remove_host(struct memstick_host *msh) {}
static inline void memstick_free_host(struct memstick_host *msh) {}