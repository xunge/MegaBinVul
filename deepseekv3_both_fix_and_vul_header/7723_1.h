#include <stdlib.h>

struct nfcmrvl_private {
    struct nci_dev *ndev;
    struct {
        int reset_n_io;
    } config;
};

struct nci_dev {
    struct nfc_dev *nfc_dev;
};

struct nfc_dev {
    int fw_download_in_progress;
};

int gpio_is_valid(int gpio);
void gpio_free(int gpio);
void nfcmrvl_fw_dnld_abort(struct nfcmrvl_private *priv);
void nfcmrvl_fw_dnld_deinit(struct nfcmrvl_private *priv);
void nci_unregister_device(struct nci_dev *ndev);
void nci_free_device(struct nci_dev *ndev);