#include <stdlib.h>
#include <string.h>

struct sk_buff {
    unsigned int len;
    void *data;
};

struct pcie_service_card {
    struct sk_buff *cmdrsp_buf;
};

struct mwifiex_adapter {
    struct pcie_service_card *card;
};

#define MWIFIEX_UPLD_SIZE 4096
#define ERROR 1
#define ENOMEM 12
#define PCI_DMA_FROMDEVICE 2

struct sk_buff *dev_alloc_skb(unsigned int size);
void skb_put(struct sk_buff *skb, unsigned int len);
void mwifiex_dbg(struct mwifiex_adapter *adapter, int level, const char *fmt, ...);
int mwifiex_map_pci_memory(struct mwifiex_adapter *adapter, struct sk_buff *skb, int size, int direction);