#include <stddef.h>
#include <stdint.h>

struct nfc_dev;

struct nfc_llcp_local {
    size_t gb_len;
    uint8_t *gb;
};

struct nfc_llcp_local *nfc_llcp_find_local(struct nfc_dev *dev);
void nfc_llcp_build_gb(struct nfc_llcp_local *local);

typedef uint8_t u8;