#include <stdint.h>
#include <errno.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define HCI_CHANNEL_RAW   0
#define HCI_DATA_DIR      1
#define HCI_TIME_STAMP    2
#define HCI_FILTER       3

#define HCI_CMSG_DIR      0x0001
#define HCI_CMSG_TSTAMP   0x0002

#define BT_DBG(fmt, ...)

#define __user
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))

typedef uint32_t u32;

struct socket {
    struct sock *sk;
};

struct sock {
    // minimal definition
};

struct hci_ufilter {
    uint32_t type_mask;
    uint16_t opcode;
    uint32_t event_mask[2];
};

struct hci_filter {
    uint32_t type_mask;
    uint16_t opcode;
    uint8_t  event_mask[8];
};

struct hci_pi {
    int channel;
    int cmsg_mask;
    struct hci_filter filter;
};

static inline struct hci_pi *hci_pi(struct sock *sk)
{
    return (struct hci_pi *)sk;
}

#define EFAULT      14
#define EINVAL      22
#define ENOPROTOOPT 92

static inline int get_user(int *val, int __user *addr)
{
    *val = *addr;
    return 0;
}

static inline int put_user(int val, int __user *addr)
{
    *((int *)addr) = val;
    return 0;
}

static inline int copy_to_user(void __user *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}

static inline void lock_sock(struct sock *sk) {}
static inline void release_sock(struct sock *sk) {}