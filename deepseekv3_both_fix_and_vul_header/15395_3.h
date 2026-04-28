#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define GFP_KERNEL 0
#define EINVAL 22
#define ENOMEM 12
#define EFAULT 14

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;

struct hl_fpriv {
    struct hl_device *hdev;
};

struct hl_info_args {
    void *return_pointer;
    u32 return_size;
    u32 sec_attest_nonce;
};

struct cpucp_sec_attest_info {
    u32 nonce;
    u16 pcr_quote_len;
    u16 pub_data_len;
    u16 certificate_len;
    u8 pcr_num_reg;
    u8 pcr_reg_len;
    u8 quote_sig_len;
    u8 pcr_data[32];
    u8 pcr_quote[256];
    u8 public_data[64];
    u8 certificate[1024];
    u8 quote_sig[256];
};

struct hl_info_sec_attest {
    u32 nonce;
    u16 pcr_quote_len;
    u16 pub_data_len;
    u16 certificate_len;
    u8 pcr_num_reg;
    u8 pcr_reg_len;
    u8 quote_sig_len;
    u8 pcr_data[32];
    u8 pcr_quote[256];
    u8 public_data[64];
    u8 certificate[1024];
    u8 quote_sig[256];
};

struct hl_device;

static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint16_t le16_to_cpu(uint16_t x) { return x; }
static inline void *kmalloc(size_t size, int flags) { return malloc(size); }
static inline void kfree(void *ptr) { free(ptr); }
static inline int copy_to_user(void *to, const void *from, size_t n) { memcpy(to, from, n); return 0; }
static inline int hl_fw_get_sec_attest_info(struct hl_device *hdev, struct cpucp_sec_attest_info *info, u32 nonce) { return 0; }

#define __user
#define min_t(type, x, y) ((x) < (y) ? (x) : (y))