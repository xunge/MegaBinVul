#include <stdint.h>
#include <string.h>
#include <errno.h>

#define VHDX_METADATA_TABLE_MAX_SIZE 1024
#define VHDX_BLOCK_SIZE_MIN (1 * 1024 * 1024)
#define VHDX_BLOCK_SIZE_MAX (256 * 1024 * 1024)
#define VHDX_MAX_SECTORS_PER_BLOCK 65536
#define VHDX_META_FLAGS_IS_REQUIRED 0x1
#define VHDX_PARAMS_HAS_PARENT 0x1

#define META_FILE_PARAMETER_PRESENT 0x1
#define META_VIRTUAL_DISK_SIZE_PRESENT 0x2
#define META_PAGE_83_PRESENT 0x4
#define META_LOGICAL_SECTOR_SIZE_PRESENT 0x8
#define META_PHYS_SECTOR_SIZE_PRESENT 0x10
#define META_PARENT_LOCATOR_PRESENT 0x20
#define META_ALL_PRESENT (META_FILE_PARAMETER_PRESENT | \
                         META_VIRTUAL_DISK_SIZE_PRESENT | \
                         META_PAGE_83_PRESENT | \
                         META_LOGICAL_SECTOR_SIZE_PRESENT | \
                         META_PHYS_SECTOR_SIZE_PRESENT)

typedef struct {
    uint8_t signature[8];
    uint32_t entry_count;
} VHDXMetadataTableHeader;

typedef struct {
    uint8_t item_id[16];
    uint32_t offset;
    uint32_t length;
    uint32_t data_bits;
} VHDXMetadataTableEntry;

typedef struct {
    uint32_t block_size;
    uint32_t data_bits;
} VHDXFileParameters;

typedef struct {
    uint64_t file_offset;
} VHDXRegionTableEntry;

typedef struct {
    VHDXRegionTableEntry metadata_rt;
    VHDXMetadataTableHeader metadata_hdr;
    struct {
        uint32_t present;
        VHDXMetadataTableEntry file_parameters_entry;
        VHDXMetadataTableEntry virtual_disk_size_entry;
        VHDXMetadataTableEntry page83_data_entry;
        VHDXMetadataTableEntry logical_sector_size_entry;
        VHDXMetadataTableEntry phys_sector_size_entry;
        VHDXMetadataTableEntry parent_locator_entry;
    } metadata_entries;
    VHDXFileParameters params;
    uint64_t virtual_disk_size;
    uint32_t logical_sector_size;
    uint32_t physical_sector_size;
    uint32_t sectors_per_block;
    uint32_t chunk_ratio;
    uint32_t block_size;
} BDRVVHDXState;

typedef struct {
    void *file;
} BlockDriverState;

static const uint8_t file_param_guid[16] = {0};
static const uint8_t virtual_size_guid[16] = {0};
static const uint8_t page83_guid[16] = {0};
static const uint8_t logical_sector_guid[16] = {0};
static const uint8_t phys_sector_guid[16] = {0};
static const uint8_t parent_locator_guid[16] = {0};