#include <linux/types.h>
#include <linux/nfc.h>
#include <stddef.h>

struct nfc_llcp_local;
struct nfc_dev;

extern struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
extern void local_cleanup(struct nfc_llcp_local *local);
extern void nfc_llcp_local_put(struct nfc_llcp_local *local);