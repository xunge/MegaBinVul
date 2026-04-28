#include <stdint.h>
#include <string.h>

typedef uint8_t u8;
typedef uint16_t u16;

struct aac_dev {
    int id;
    struct pci_dev *pdev;
};

struct pci_dev {
    u16 vendor;
    u16 device;
    u16 subsystem_vendor;
    u16 subsystem_device;
    unsigned int devfn;
    struct {
        u8 number;
    } *bus;
};

struct aac_hba_info {
    u8 adapter_number;
    u8 system_io_bus_number;
    u8 device_number;
    u8 function_number;
    u16 vendor_id;
    u16 device_id;
    u16 sub_vendor_id;
    u16 sub_system_id;
};

#define __user
#define KERN_DEBUG
#define dprintk(x)
#define EFAULT 14

static inline int copy_to_user(void *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}