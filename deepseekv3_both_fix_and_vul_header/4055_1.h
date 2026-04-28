#include <stddef.h>
#include <string.h>
#include <errno.h>

#define NFC_MAX_GT_LEN 48
#define pr_err(fmt, ...)

typedef unsigned char u8;

struct nfc_dev;

struct nfc_llcp_local {
    u8 remote_gb[NFC_MAX_GT_LEN];
    u8 remote_gb_len;
};

extern u8 llcp_magic[3];

struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
int nfc_llcp_parse_gb_tlv(struct nfc_llcp_local *local, const u8 *tlv, u8 tlv_length);