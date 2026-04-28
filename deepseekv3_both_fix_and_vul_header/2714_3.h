#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define NFC_SENSF_RES_MAXSIZE 18
#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

typedef uint8_t __u8;

struct nci_dev;
struct rf_tech_specific_params_nfcf_poll {
    __u8 bit_rate;
    __u8 sensf_res_len;
    __u8 sensf_res[NFC_SENSF_RES_MAXSIZE];
};