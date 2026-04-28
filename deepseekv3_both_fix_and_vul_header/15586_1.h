#include <stdint.h>
#include <stdlib.h>

struct sk_buff {
    unsigned char *data;
    size_t len;
};

struct nci_spi {
    void *ndev;
};

struct nci_dev;

typedef uint8_t u8;
typedef uint16_t u16;

#define GFP_KERNEL 0
#define ENOMEM 12
#define NCI_SPI_HDR_LEN 4
#define NCI_SPI_DIRECT_WRITE 0
#define NCI_SPI_CRC_ENABLED 1
#define NCI_SPI_ACK_SHIFT 0
#define CRC_INIT 0xFFFF

static inline struct sk_buff *nci_skb_alloc(void *ndev, unsigned int len, int gfp);
static inline unsigned char *skb_push(struct sk_buff *skb, unsigned int len);
static inline void skb_put_u8(struct sk_buff *skb, u8 value);
static inline void kfree_skb(struct sk_buff *skb);
static int __nci_spi_send(struct nci_spi *nspi, struct sk_buff *skb, int flags);
uint16_t crc_ccitt(uint16_t crc, const uint8_t *buffer, size_t len);