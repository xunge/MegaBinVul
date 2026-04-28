#include <stdint.h>
#include <stdlib.h>

#define MS_BYTES_PER_PAGE 512
#define MS_SYSINF_PAGE_SIZE 512
#define MS_SYSINF_MSCLASS_TYPE_1 1
#define MS_SYSINF_SECURITY 0x01
#define MS_SYSINF_SECURITY_SUPPORT 0x01
#define MS_SYSINF_RESERVED1 0
#define MS_SYSINF_RESERVED2 0
#define MS_SYSINF_FORMAT_FAT 0x02
#define MS_SYSINF_USAGE_GENERAL 0
#define MS_SYSINF_CARDTYPE_RDONLY 0
#define MS_SYSINF_CARDTYPE_RDWR 1
#define MS_SYSINF_CARDTYPE_HYBRID 2
#define SIZE_OF_KIRO 1024
#define MS_PHYSICAL_BLOCKS_PER_SEGMENT 512
#define MS_NUMBER_OF_SYSTEM_ENTRY 2
#define MS_SYSENT_TYPE_INVALID_BLOCK 0x01
#define MS_SYSENT_TYPE_CIS_IDI 0x02
#define MS_IDI_GENERAL_CONF 0x0F00
#define MS_LIB_CTRL_RDONLY 0x01
#define GFP_KERNEL 0

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;

struct ms_bootblock_sysent_entry {
    u8 bType;
    u8 bReserved[3];
    u32 dwStart;
    u32 dwSize;
};

struct ms_bootblock_sysent {
    struct ms_bootblock_sysent_entry entry[2];
};

struct ms_bootblock_sysinf {
    u8 bMsClass;
    u8 bReserved1;
    u8 bReserved2;
    u8 bFormatType;
    u8 bUsage;
    u8 bSecuritySupport;
    u8 bCardType;
    u8 bReserved3;
    u16 wPageSize;
    u16 wBlockSize;
    u16 wBlockNumber;
    u16 wTotalBlockNumber;
    u16 wMemorySize;
    u16 wReserved4;
};

struct ms_bootblock_page0 {
    struct ms_bootblock_sysinf sysinf;
    struct ms_bootblock_sysent sysent;
};

struct ms_bootblock_idi {
    u16 wIDIgeneralConfiguration;
    u16 wIDIbytesPerSector;
};

struct ms_bootblock_cis_idi {
    struct {
        struct ms_bootblock_idi idi;
    } idi;
};

struct ms_lib_type_extdat {
    u32 data;
};

struct ene_ub6250_info {
    struct {
        u16 blockSize;
        u16 NumberOfPhyBlock;
        u16 NumberOfLogBlock;
        u16 PagesPerBlock;
        u16 NumberOfSegment;
        u16 BytesPerSector;
        u8 cardType;
    } MS_Lib;
    u16 MS_Model;
};

struct us_data {
    void *extra;
};

enum {
    MS_STATUS_SUCCESS,
    MS_STATUS_WRITE_PROTECT,
    MS_ERROR_FLASH_READ,
    MS_STATUS_ERROR
};

static inline u16 be16_to_cpu(u16 x) { return x; }
static inline u32 be32_to_cpu(u32 x) { return x; }
static inline u16 le16_to_cpu(u16 x) { return x; }

void *kzalloc(size_t size, int flags) { return calloc(1, size); }
void *kmalloc(size_t size, int flags) { return malloc(size); }
void kfree(void *ptr) { free(ptr); }

static void ms_lib_ctrl_set(struct ene_ub6250_info *info, u32 ctrl) {}
static void ms_lib_ctrl_reset(struct ene_ub6250_info *info, u32 ctrl) {}
static int ms_lib_alloc_logicalmap(struct us_data *us) { return 0; }
static void ms_lib_set_bootblockmark(struct us_data *us, u16 PhyBlock) {}
static int ms_read_readpage(struct us_data *us, u16 PhyBlock, u8 PageNumber, u32 *PageBuffer, struct ms_lib_type_extdat *ExtraData) { return MS_STATUS_SUCCESS; }
static void ms_lib_set_initialerrorblock(struct us_data *us, u16 phyblk) {}
static void ms_lib_free_logicalmap(struct us_data *us) {}