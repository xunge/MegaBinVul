#include <stddef.h>

struct scm_cookie {
    struct unix_fp *fp;
};

struct sk_buff {
    struct unix_skb_parms {
        struct unix_fp *fp;
    } unixcb;
};

#define UNIXCB(skb) ((skb)->unixcb)

struct unix_fp {
    int count;
    void *user;
    void **fp;
};

static void unix_notinflight(void *user_or_fp, ...);