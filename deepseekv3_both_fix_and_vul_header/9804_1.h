#include <stdint.h>

#define VIAID 0x1234
#define PCI_VIA_VENDOR_ID 0x1106
#define UNICHROME_CLE266_DID 0x3122
#define UNICHROME_K400_DID 0x7205
#define UNICHROME_K800_DID 0x3108
#define UNICHROME_PM800_DID 0x3118
#define UNICHROME_CN700_DID 0x3344
#define UNICHROME_CX700_DID 0x3157
#define UNICHROME_K8M890_DID 0x3230
#define UNICHROME_P4M890_DID 0x3343
#define UNICHROME_P4M900_DID 0x3371
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define EFAULT 14

typedef uint64_t u_long;
#define __user

enum unichrome_chip_type {
    UNICHROME_CLE266,
    UNICHROME_K400,
    UNICHROME_K800,
    UNICHROME_PM800,
    UNICHROME_CN700,
    UNICHROME_CX700,
    UNICHROME_K8M890,
    UNICHROME_P4M890,
    UNICHROME_P4M900
};

struct viafb_ioctl_info {
    unsigned int viafb_id;
    unsigned int vendor_id;
    unsigned int device_id;
    unsigned int version;
    unsigned int revision;
};

struct viafb_chip_info {
    enum unichrome_chip_type gfx_chip_name;
};

struct viafb_par {
    struct viafb_chip_info *chip_info;
};

extern struct viafb_par *viaparinfo;

static inline int copy_to_user(void *to, const void *from, unsigned long n)
{
    memcpy(to, from, n);
    return 0;
}