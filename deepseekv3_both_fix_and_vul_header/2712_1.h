#include <stdint.h>
#include <string.h>
#include <linux/types.h>

#define NFC_NFCID1_MAXSIZE 10
#define pr_debug(fmt, ...) 

#define min_t(type, x, y) ({ \
    type __min1 = (x); \
    type __min2 = (y); \
    __min1 < __min2 ? __min1 : __min2; \
})

struct nci_dev;
struct rf_tech_specific_params_nfca_poll {
    __u16 sens_res;
    __u8 nfcid1_len;
    __u8 nfcid1[NFC_NFCID1_MAXSIZE];
    __u8 sel_res_len;
    __u8 sel_res;
};