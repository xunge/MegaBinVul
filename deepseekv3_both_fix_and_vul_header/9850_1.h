#include <string.h>
#include <stdio.h>

struct sk_buff {
    unsigned char *data;
    unsigned int len;
};

struct x25_facilities {
    unsigned char reverse;
    unsigned char throughput;
    unsigned char pacsize_in;
    unsigned char pacsize_out;
    unsigned char winsize_in;
    unsigned char winsize_out;
};

struct x25_dte_facilities {
    unsigned char calling_len;
    unsigned char called_len;
    unsigned char calling_ae[16];
    unsigned char called_ae[16];
};

#define X25_FAC_CLASS_MASK   0xC0
#define X25_FAC_CLASS_A      0x00
#define X25_FAC_CLASS_B      0x40
#define X25_FAC_CLASS_C      0x80
#define X25_FAC_CLASS_D      0xC0

#define X25_FAC_REVERSE      0x01
#define X25_FAC_THROUGHPUT   0x02
#define X25_MARKER           0x04
#define X25_FAC_PACKET_SIZE  0x42
#define X25_FAC_WINDOW_SIZE  0x43
#define X25_FAC_CALLING_AE   0xCB
#define X25_FAC_CALLED_AE    0xC9

#define X25_MASK_REVERSE     0x01
#define X25_MASK_THROUGHPUT  0x02
#define X25_MASK_PACKET_SIZE 0x04
#define X25_MASK_WINDOW_SIZE 0x08
#define X25_MASK_CALLING_AE  0x10
#define X25_MASK_CALLED_AE   0x20

#define X25_DEFAULT_REVERSE  0x00
#define X25_MAX_DTE_FACIL_LEN 16

#define KERN_DEBUG ""
#define printk printf