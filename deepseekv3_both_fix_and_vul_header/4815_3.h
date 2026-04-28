#include <stdint.h>
#include <string.h>
#include <stdio.h>

typedef struct BusChild BusChild;
typedef struct SCSIDevice SCSIDevice;
typedef struct QEMUSGList QEMUSGList;

struct BusChild {
    void *child;
    BusChild *sibling;
};

struct SCSIDevice {
    uint8_t id;
    uint8_t lun;
};

struct QEMUSGList {
    void *sg;
    int nsg;
    size_t size;
};

typedef struct MegasasState {
    struct {
        struct {
            struct {
                BusChild *children;
            } qbus;
        } bus;
        char hba_serial[32];
        uint16_t fw_cmds;
        uint16_t fw_sge;
    };
} MegasasState;

typedef struct MegasasCmd {
    size_t iov_size;
    int index;
    QEMUSGList qsg;
} MegasasCmd;

typedef struct PCIDevice {
    uint8_t has_rom;
    struct {
        uint8_t rom[256];
    };
} PCIDevice;

typedef struct PCIDeviceClass {
    uint16_t vendor_id;
    uint16_t device_id;
    uint16_t subsystem_vendor_id;
    uint16_t subsystem_id;
} PCIDeviceClass;

typedef struct MegasasBaseClass {
    char product_name[24];
    char product_version[10];
} MegasasBaseClass;

struct mfi_ctrl_info {
    struct {
        uint16_t vendor;
        uint16_t device;
        uint16_t subvendor;
        uint16_t subdevice;
    } pci;
    struct {
        uint8_t type;
    } host;
    struct {
        uint8_t type;
        uint8_t port_count;
        uint64_t port_addr[8];
    } device;
    char product_name[24];
    char serial_number[32];
    char package_version[0x60];
    struct {
        char name[4];
        char version[10];
        char build_date[11];
        char build_time[8];
    } image_component[2];
    uint8_t image_component_count;
    uint32_t current_fw_time;
    uint16_t max_arms;
    uint16_t max_spans;
    uint16_t max_arrays;
    uint16_t max_lds;
    uint16_t max_cmds;
    uint16_t max_sg_elements;
    uint32_t max_request_size;
    uint16_t lds_present;
    uint16_t pd_present;
    uint16_t pd_disks_present;
    uint32_t hw_present;
    uint16_t memory_size;
    uint16_t nvram_size;
    uint16_t flash_size;
    uint32_t raid_levels;
    uint32_t adapter_ops;
    uint32_t ld_ops;
    uint16_t max_strips_per_io;
    struct {
        uint8_t min;
        uint8_t max;
    } stripe_sz_ops;
    struct {
        uint16_t pred_fail_poll_interval;
        uint16_t intr_throttle_cnt;
        uint16_t intr_throttle_timeout;
        uint8_t rebuild_rate;
        uint8_t patrol_read_rate;
        uint8_t bgi_rate;
        uint8_t cc_rate;
        uint8_t recon_rate;
        uint8_t cache_flush_interval;
        uint8_t spinup_drv_cnt;
        uint8_t spinup_delay;
        uint8_t ecc_bucket_size;
        uint16_t ecc_bucket_leak_rate;
        uint8_t expose_encl_devices;
        uint32_t OnOffProperties;
    } properties;
    uint32_t pd_ops;
    uint32_t pd_mix_support;
};

#define PCI_DEVICE(obj) ((PCIDevice *)(obj))
#define PCI_DEVICE_GET_CLASS(obj) ((PCIDeviceClass *)(obj))
#define MEGASAS_DEVICE_GET_CLASS(obj) ((MegasasBaseClass *)(obj))
#define SCSI_DEVICE(obj) ((SCSIDevice *)(obj))

#define MFI_STAT_OK 0
#define MFI_STAT_INVALID_PARAMETER 1
#define MFI_INFO_HOST_PCIE 1
#define MFI_INFO_DEV_SAS3G 1
#define MEGASAS_MAX_ARRAYS 128
#define MFI_MAX_LD 64
#define MEGASAS_MAX_SECTORS 4096
#define MFI_INFO_HW_NVRAM 1
#define MFI_INFO_HW_MEM 2
#define MFI_INFO_HW_FLASH 4
#define MFI_INFO_RAID_0 1
#define MFI_INFO_AOPS_RBLD_RATE 1
#define MFI_INFO_AOPS_SELF_DIAGNOSTIC 2
#define MFI_INFO_AOPS_MIXED_ARRAY 4
#define MFI_INFO_LDOPS_DISK_CACHE_POLICY 1
#define MFI_INFO_LDOPS_ACCESS_POLICY 2
#define MFI_INFO_LDOPS_IO_POLICY 4
#define MFI_INFO_LDOPS_WRITE_POLICY 8
#define MFI_INFO_LDOPS_READ_POLICY 16
#define MFI_CTRL_PROP_EnableJBOD 1
#define MFI_INFO_PDOPS_FORCE_ONLINE 1
#define MFI_INFO_PDOPS_FORCE_OFFLINE 2
#define MFI_INFO_PDMIX_SAS 1
#define MFI_INFO_PDMIX_SATA 2
#define MFI_INFO_PDMIX_LD 4

static inline uint16_t cpu_to_le16(uint16_t v) { return v; }
static inline uint32_t cpu_to_le32(uint32_t v) { return v; }
static inline uint64_t cpu_to_le64(uint64_t v) { return v; }
static inline int ctz32(uint32_t v) { return __builtin_ctz(v); }

static uint32_t megasas_fw_time(void) { return 0; }
static uint64_t megasas_get_sata_addr(uint16_t pd_id) { return 0; }
static int megasas_is_jbod(MegasasState *s) { return 0; }
static size_t dma_buf_read(uint8_t *buf, size_t len, QEMUSGList *qsg) { return 0; }
static const char *qemu_hw_version(void) { return ""; }
static void trace_megasas_dcmd_invalid_xfer_len(int index, size_t iov_size, size_t dcmd_size) {}

static uint8_t *memory_region_get_ram_ptr(void *mr) { return (uint8_t *)mr; }

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = (head); (var) != NULL; (var) = (var)->field)