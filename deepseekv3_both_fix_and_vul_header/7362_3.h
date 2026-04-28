#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define NFC_MIN_AID_LENGTH 5
#define NFC_MAX_AID_LENGTH 16
#define NFC_EVT_TRANSACTION_AID_TAG 0x81
#define NFC_EVT_TRANSACTION_PARAMS_TAG 0x82
#define ST21NFCA_EVT_CONNECTIVITY 0
#define ST21NFCA_EVT_TRANSACTION 1
#define GFP_KERNEL 0
#define EPROTO 1
#define ENOMEM 2
#define EINVAL 3

struct device {
    struct device *dev;
};

struct nfc_hci_dev {
    struct device *ndev;
};

struct sk_buff {
    unsigned int len;
    unsigned char *data;
};

struct nfc_evt_transaction {
    uint8_t aid_len;
    uint8_t aid[NFC_MAX_AID_LENGTH];
    uint8_t params_len;
    uint8_t params[];
};

typedef uint8_t u8;

void *devm_kzalloc(struct device *dev, size_t size, int flags);
void kfree_skb(struct sk_buff *skb);
int nfc_se_connectivity(struct device *ndev, u8 host);
int nfc_se_transaction(struct device *ndev, u8 host, struct nfc_evt_transaction *transaction);
void pr_debug(const char *fmt, ...);
void nfc_err(struct device *dev, const char *fmt, ...);