#include <sys/socket.h>
#include <string.h>
#include <errno.h>

struct sco_conn {
    unsigned int mtu;
    void *hcon;
};

struct sk_buff {
    void *data;
};

struct sco_pi {
    struct sco_conn *conn;
};

static inline struct sco_pi *sco_pi(const struct sock *sk)
{
    return (struct sco_pi *)sk;
}

#define BT_DBG(fmt, ...)
#define MSG_DONTWAIT 0x40
#define EINVAL 22
#define EFAULT 14

static void *bt_skb_send_alloc(struct sock *sk, int len, int flags, int *err) { return NULL; }
static void kfree_skb(struct sk_buff *skb) {}
static void *skb_put(struct sk_buff *skb, int len) { return NULL; }
static int memcpy_from_msg(void *dst, struct msghdr *msg, int len) { return 0; }
static void hci_send_sco(void *hcon, struct sk_buff *skb) {}