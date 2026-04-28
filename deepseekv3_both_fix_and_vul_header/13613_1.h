#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

#define FW_BULKOUT_SIZE 256
#define FW_CONFIG 0x15
#define GFP_KERNEL 0
#define ENOMEM 12
#define EIO 5

#define deb_info(fmt, ...) printf(fmt, ##__VA_ARGS__)

struct usb_device;
struct dvb_usb_device_properties;
struct dvb_usb_device_description;

typedef uint8_t u8;

extern void *kmalloc(size_t size, int flags);
extern void kfree(void *ptr);
extern int af9005_boot_packet(struct usb_device *udev, u8 request, u8 *reply,
                              u8 *buf, int size);