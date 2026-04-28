#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define L1_MODE_TRANS 1
#define HFCUSB_D_RX 1
#define HFCUSB_PCM_RX 2
#define PH_DATA 1
#define PH_DATA_E 2
#define INDICATION 1
#define HFCUSB_DBG_FIFO_ERR 1
#define HFCUSB_DBG_VERBOSE_USB 2
#define HFCUSB_DBG_DCHANNEL 3
#define KERN_ERR "<3>"

typedef uint8_t __u8;

typedef struct sk_buff {
    unsigned char *data;
    unsigned int len;
} sk_buff;

typedef struct hfcusb_data {
    int b_mode[2];
} hfcusb_data;

typedef struct hif {
    void (*l1l2)(struct hif *, int, struct sk_buff *);
} hif;

typedef struct usb_fifo {
    hfcusb_data *hfc;
    int fifonum;
    struct sk_buff *skbuff;
    int max_size;
    struct hif *hif;
} usb_fifo;

static inline void *dev_alloc_skb(unsigned int size) {
    struct sk_buff *skb = malloc(sizeof(struct sk_buff));
    if (skb) {
        skb->data = malloc(size);
        skb->len = 0;
    }
    return skb;
}

static inline void *skb_put(struct sk_buff *skb, unsigned int len) {
    void *ret = skb->data + skb->len;
    skb->len += len;
    return ret;
}

static inline void skb_trim(struct sk_buff *skb, unsigned int len) {
    skb->len = len;
}

#define DBG(level, fmt, ...) printf(fmt "\n", ##__VA_ARGS__)
#define DBG_SKB(level, skb) 
#define printk(fmt, ...) printf(fmt "\n", ##__VA_ARGS__)