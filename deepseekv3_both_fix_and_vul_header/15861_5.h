#include <stdbool.h>

struct device;
struct sk_buff;

struct brcmf_pub {
    // 定义必要的成员
};

struct brcmf_bus {
    struct brcmf_pub *drvr;
    // 定义必要的成员
};

struct brcmf_if {
    struct brcmf_pub *drvr;
    // 定义必要的成员
};

#define DATA 0
#define BCMILCP_SUBTYPE_VENDOR_LONG 0

void *dev_get_drvdata(struct device *dev);
const char *dev_name(struct device *dev);

int brcmf_rx_hdrpull(struct brcmf_pub *drvr, struct sk_buff *skb, struct brcmf_if **ifp);
bool brcmf_proto_is_reorder_skb(struct sk_buff *skb);
void brcmf_proto_rxreorder(struct brcmf_if *ifp, struct sk_buff *skb);
void brcmf_fweh_process_skb(struct brcmf_pub *drvr, struct sk_buff *skb, ...);
void brcmf_netif_rx(struct brcmf_if *ifp, struct sk_buff *skb);
void brcmf_dbg(int level, const char *fmt, ...);