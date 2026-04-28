#include <stdint.h>
#include <limits.h>
#include <string.h>

#define GDT_IOCTL 0x80
#define CACHESERVICE 0x02
#define SCSIRAWSERVICE 0x83
#define GDT_64BIT 0x01
#define SCATTER_GATHER 0x02
#define FALSE 0
#define EFAULT 1
#define EINVAL 2

typedef uint64_t u64;
typedef uint32_t u32;

struct gdth_sg_str {
    u64 sg_ptr;
    u32 sg_len;
};

struct gdth_sg64_str {
    u64 sg_ptr;
    u32 sg_len;
};

struct gdth_cmd_str {
    uint8_t OpCode;
    uint8_t Service;
    union {
        struct {
            u64 p_param;
        } ioctl;
        struct {
            u32 DestAddr;
            u32 BlockNo;
            uint16_t BlockCnt;
            uint16_t DeviceNo;
            uint8_t sg_canz;
            struct gdth_sg_str sg_lst[2];
        } cache;
        struct {
            u64 DestAddr;
            u64 BlockNo;
            uint16_t BlockCnt;
            uint16_t DeviceNo;
            uint8_t sg_canz;
            struct gdth_sg64_str sg_lst[2];
        } cache64;
        struct {
            u32 sdata;
            u32 sense_data;
            uint8_t sense_len;
            uint8_t bus;
            uint8_t lun;
            uint8_t target;
            uint8_t cmd[16];
            uint8_t clen;
            uint8_t sdlen;
            uint8_t direction;
            uint8_t sg_ranz;
            struct gdth_sg_str sg_lst[2];
        } raw;
        struct {
            u64 sdata;
            u64 sense_data;
            uint8_t sense_len;
            uint8_t bus;
            uint8_t lun;
            uint8_t target;
            uint8_t cmd[16];
            uint8_t clen;
            uint8_t sdlen;
            uint8_t direction;
            uint8_t sg_ranz;
            struct gdth_sg64_str sg_lst[2];
        } raw64;
    } u;
};

struct gdth_ioctl_general {
    int ionode;
    int timeout;
    int data_len;
    int sense_len;
    int status;
    int info;
    struct gdth_cmd_str command;
};

struct gdth_ha_str {
    unsigned int cache_feat;
    unsigned int raw_feat;
    void *sdev;
};

typedef struct gdth_ha_str gdth_ha_str;
typedef struct gdth_ioctl_general gdth_ioctl_general;
typedef struct gdth_cmd_str gdth_cmd_str;

#define __user

extern int copy_from_user(void *to, const void *from, unsigned long n);
extern int copy_to_user(void *to, const void *from, unsigned long n);
extern gdth_ha_str *gdth_find_ha(int ionode);
extern char *gdth_ioctl_alloc(gdth_ha_str *ha, int size, int scratch, u64 *paddr);
extern void gdth_ioctl_free(gdth_ha_str *ha, int size, char *buf, u64 paddr);
extern int __gdth_execute(void *sdev, gdth_cmd_str *cmd, char *cmnd, int timeout, int *info);