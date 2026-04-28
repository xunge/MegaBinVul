#include <linux/types.h>
#include <linux/hid.h>

#define USB_DEVICE_ID_KYE_ERGO_525V 0x5255
#define USB_DEVICE_ID_KYE_EASYPEN_I405X 0x0010
#define USB_DEVICE_ID_KYE_MOUSEPEN_I608X 0x00d0
#define USB_DEVICE_ID_KYE_EASYPEN_M610X 0x00e0
#define USB_DEVICE_ID_GENIUS_GILA_GAMING_MOUSE 0x00f0
#define USB_DEVICE_ID_GENIUS_GX_IMPERATOR 0x00f1
#define USB_DEVICE_ID_GENIUS_MANTICORE 0x00f2

#define EASYPEN_I405X_RDESC_ORIG_SIZE 120
#define MOUSEPEN_I608X_RDESC_ORIG_SIZE 172
#define EASYPEN_M610X_RDESC_ORIG_SIZE 196

extern __u8 easypen_i405x_rdesc_fixed[120];
extern __u8 mousepen_i608x_rdesc_fixed[172];
extern __u8 easypen_m610x_rdesc_fixed[196];

struct hid_device {
    unsigned int product;
};

extern __u8 *kye_consumer_control_fixup(struct hid_device *hdev, __u8 *rdesc,
                    unsigned int *rsize, int offset,
                    const char *device_name);