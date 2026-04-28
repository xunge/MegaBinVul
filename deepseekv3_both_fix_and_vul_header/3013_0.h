#include <stddef.h>
#include <string.h>
#include <stdlib.h>

#define PCI_VPD_LRDT_RO_DATA 0x82
#define PCI_VPD_LRDT_TAG_SIZE 3
#define PCI_VPD_RO_KEYWORD_MFR_ID 0x02
#define PCI_VPD_RO_KEYWORD_VENDOR0 0x03
#define PCI_VPD_RO_KEYWORD_PARTNO 0x04
#define PCI_VPD_INFO_FLD_HDR_SIZE 2
#define TG3_BPN_SIZE 80
#define ASIC_REV_5717 0x5717
#define ASIC_REV_57780 0x57780
#define ASIC_REV_57765 0x57765
#define ASIC_REV_57766 0x57766
#define ASIC_REV_5906 0x5906

#define TG3PCI_DEVICE_TIGON3_5717 0x1653
#define TG3PCI_DEVICE_TIGON3_5717_C 0x1654
#define TG3PCI_DEVICE_TIGON3_5718 0x1655
#define TG3PCI_DEVICE_TIGON3_57780 0x1691
#define TG3PCI_DEVICE_TIGON3_57760 0x1693
#define TG3PCI_DEVICE_TIGON3_57790 0x1698
#define TG3PCI_DEVICE_TIGON3_57788 0x1699
#define TG3PCI_DEVICE_TIGON3_57761 0x16b1
#define TG3PCI_DEVICE_TIGON3_57765 0x16b5
#define TG3PCI_DEVICE_TIGON3_57781 0x16b9
#define TG3PCI_DEVICE_TIGON3_57785 0x16bd
#define TG3PCI_DEVICE_TIGON3_57791 0x16c1
#define TG3PCI_DEVICE_TIGON3_57795 0x16c5
#define TG3PCI_DEVICE_TIGON3_57762 0x16b2
#define TG3PCI_DEVICE_TIGON3_57766 0x16b6
#define TG3PCI_DEVICE_TIGON3_57782 0x16ba
#define TG3PCI_DEVICE_TIGON3_57786 0x16be

typedef unsigned char u8;
typedef unsigned int u32;

struct pci_dev {
    unsigned int device;
};

struct tg3 {
    struct pci_dev *pdev;
    char board_part_number[TG3_BPN_SIZE];
    char fw_ver[256];
};

static void *tg3_vpd_readblock(struct tg3 *tp, u32 *vpdlen);
static int tg3_asic_rev(struct tg3 *tp);
static int pci_vpd_find_tag(const u8 *buf, unsigned int off, unsigned int len, u8 rdt);
static unsigned int pci_vpd_lrdt_size(const u8 *buf);
static int pci_vpd_find_info_keyword(const u8 *buf, unsigned int off, unsigned int len, u8 kw);
static unsigned int pci_vpd_info_field_size(const u8 *buf);