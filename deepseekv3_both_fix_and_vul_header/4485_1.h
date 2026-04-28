#define CDC_NCM_COMM_ALTSETTING_NCM 0
#define CDC_NCM_DATA_ALTSETTING_NCM 0
#define ENODEV 19

struct usbnet;
struct usb_interface;

static int cdc_ncm_select_altsetting(struct usb_interface *intf);
static int cdc_ncm_bind_common(struct usbnet *dev, struct usb_interface *intf, int altsetting, int ndp_sign);
void usbnet_link_change(struct usbnet *dev, int link, int duplex);