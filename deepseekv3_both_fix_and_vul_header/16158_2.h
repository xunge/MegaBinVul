#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;

#define LCP_OPTION_ACCM 2
#define LCP_OPTION_MRU 1
#define LCP_OPTION_MAGIC 5
#define PID_LCP 0xc021

#define RCR_BAD 0
#define RCR_GOOD 1
#define CP_CONF_REJ 1
#define CP_CONF_NAK 3
#define CP_CONF_ACK 2

#define GFP_ATOMIC 0

struct net_device_stats {
    unsigned int rx_dropped;
    unsigned int rx_errors;
};

struct net_device {
    struct net_device_stats stats;
};

void *kmalloc(size_t size, int flags);
void kfree(void *ptr);

void ppp_cp_event(struct net_device *dev, u16 pid, int rcr, int type, u8 id, unsigned int len, const u8 *data);