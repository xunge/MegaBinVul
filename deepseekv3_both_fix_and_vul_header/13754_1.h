#include <stdlib.h>
#include <stdint.h>

struct peak_usb_device;

#define PCAN_USBPRO_FCT_DRVLD_REQ_LEN 2
#define PCAN_USBPRO_REQ_FCT 0
#define PCAN_USBPRO_FCT_DRVLD 0

#define GFP_KERNEL 0
#define ENOMEM 12

typedef uint8_t u8;

int pcan_usb_pro_send_req(struct peak_usb_device *dev, int req, int fct, u8 *buf, int len);