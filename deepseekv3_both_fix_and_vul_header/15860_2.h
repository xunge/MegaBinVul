#include <stddef.h>

struct device;
struct sk_buff;

struct brcmf_pub {
    struct brcmf_bus *bus_if;
};

struct brcmf_bus {
    struct brcmf_pub *drvr;
};

struct brcmf_if {
    struct brcmf_pub *drvr;
};

#define EVENT 0

void *dev_get_drvdata(const struct device *dev);
const char *dev_name(const struct device *dev);
int brcmf_rx_hdrpull(struct brcmf_pub *drvr, struct sk_buff *skb, struct brcmf_if **ifp);
void brcmf_fweh_process_skb(struct brcmf_pub *drvr, struct sk_buff *skb, ...);
void brcmu_pkt_buf_free_skb(struct sk_buff *skb);
void brcmf_dbg(int level, const char *format, ...);