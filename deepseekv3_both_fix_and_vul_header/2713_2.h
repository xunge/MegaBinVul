#include <stdint.h>
#include <string.h>
#include <stdio.h>

#define NCI_NFC_A_PASSIVE_POLL_MODE 0x00
#define NCI_NFC_B_PASSIVE_POLL_MODE 0x01

#define NCI_STATUS_OK 0x00
#define NCI_STATUS_RF_PROTOCOL_ERROR 0x01

#define min_t(type, x, y) ({ type __x = (x); type __y = (y); __x < __y ? __x : __y; })
#define pr_debug(fmt, ...) printf(fmt, ##__VA_ARGS__)
#define pr_err(fmt, ...) fprintf(stderr, fmt, ##__VA_ARGS__)

typedef uint8_t __u8;

struct nci_dev;
struct nci_rf_intf_activated_ntf;

struct activation_params_nfca_poll_iso_dep {
    __u8 rats_res_len;
    __u8 rats_res[20];
};

struct activation_params_nfcb_poll_iso_dep {
    __u8 attrib_res_len;
    __u8 attrib_res[50];
};

struct activation_params {
    struct activation_params_nfca_poll_iso_dep nfca_poll_iso_dep;
    struct activation_params_nfcb_poll_iso_dep nfcb_poll_iso_dep;
};

struct nci_rf_intf_activated_ntf {
    __u8 activation_rf_tech_and_mode;
    struct activation_params activation_params;
};