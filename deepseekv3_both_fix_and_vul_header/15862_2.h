#include <stdint.h>
#include <string.h>

typedef uint16_t u16;

struct brcmf_pub;
struct sk_buff {
    uint16_t protocol;
    unsigned int len;
    unsigned char* data;
};

struct brcmf_event {
    struct {
        uint8_t oui[3];
        uint16_t subtype;
        uint16_t usr_subtype;
    } hdr;
};

static const uint8_t BRCM_OUI[3] = { 0x00, 0x10, 0x18 };
#define BCMILCP_BCM_SUBTYPE_EVENT 1
#define ETH_P_LINK_CTL 0x886c
#define ETH_HLEN 14

static inline uint16_t cpu_to_be16(uint16_t x) {
    return ((x & 0xff) << 8) | ((x >> 8) & 0xff);
}

static inline uint16_t get_unaligned_be16(const void *p) {
    const uint8_t *cp = (const uint8_t *)p;
    return (cp[0] << 8) | cp[1];
}

static inline unsigned char *skb_mac_header(const struct sk_buff *skb) {
    return skb->data;
}

#define unlikely(x) (x)

void brcmf_fweh_process_event(struct brcmf_pub *drvr, struct brcmf_event *event, unsigned int len);