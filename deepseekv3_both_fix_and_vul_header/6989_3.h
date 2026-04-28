#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define CONTROL_BUFFER_SIZE 1024
#define COMMAND_BUFFER_SIZE 2048
#define RNDIS_MSG_QUERY 1
#define ENOMEM (-1)
#define EINVAL (-2)
#define GFP_KERNEL 0

typedef uint32_t u32;

struct usbnet {
    void *net;
};

struct mutex {
    int lock;
};

struct rndis_wlan_private {
    void *command_buffer;
    struct mutex command_lock;
    u32 current_command_oid;
};

struct rndis_msg_hdr {
    u32 dummy;
};

struct rndis_query {
    u32 msg_type;
    u32 msg_len;
    u32 oid;
};

struct rndis_query_c {
    u32 status;
    u32 len;
    u32 offset;
};

static inline u32 cpu_to_le32(u32 x) { return x; }
static inline u32 le32_to_cpu(u32 x) { return x; }

static void mutex_lock(struct mutex *lock) { lock->lock = 1; }
static void mutex_unlock(struct mutex *lock) { lock->lock = 0; }

static void *kmalloc(size_t size, int flags) { return malloc(size); }
static void kfree(void *ptr) { free(ptr); }

static void netdev_dbg(void *net, const char *fmt, ...) {}

static struct rndis_wlan_private *get_rndis_wlan_priv(struct usbnet *dev) {
    static struct rndis_wlan_private priv = {0};
    return &priv;
}
static int rndis_command(struct usbnet *dev, struct rndis_msg_hdr *hdr, int buflen) { return 0; }
static int rndis_error_status(u32 status) { return 0; }
static const char *oid_to_string(u32 oid) { return ""; }