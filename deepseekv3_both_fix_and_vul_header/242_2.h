#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LLCP_VERSION_11 0x11
#define LLCP_TLV_VERSION 0x01
#define LLCP_TLV_LTO 0x02
#define LLCP_TLV_WKS 0x03
#define LLCP_TLV_MIUX 0x04
#define ENOMEM 12
#define EINVAL 22
#define NFC_MAX_GT_LEN 48

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint16_t __be16;

#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define kfree free

struct nfc_llcp_local {
    u8 *gb;
    u8 gb_len;
    u16 local_wks;
    u8 lto;
    __be16 miux;
};

static const u8 llcp_magic[3] = {0x46, 0x66, 0x6D};

static inline __be16 cpu_to_be16(u16 x) {
    return ((x & 0xFF) << 8) | ((x >> 8) & 0xFF);
}

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))