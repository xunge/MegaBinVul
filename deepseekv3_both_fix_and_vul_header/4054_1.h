#include <stdlib.h>

struct nfc_dev;
struct sk_buff;
struct nfc_llcp_local;

struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
void __nfc_llcp_recv(struct nfc_llcp_local *local, struct sk_buff *skb);
void kfree_skb(struct sk_buff *skb);

#define ENODEV 19