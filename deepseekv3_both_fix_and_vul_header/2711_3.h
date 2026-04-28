#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define NFC_SENSB_RES_MAXSIZE 12
#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)

typedef uint8_t __u8;

struct nci_dev;
struct rf_tech_specific_params_nfcb_poll {
    __u8 sensb_res_len;
    __u8 sensb_res[NFC_SENSB_RES_MAXSIZE];
};