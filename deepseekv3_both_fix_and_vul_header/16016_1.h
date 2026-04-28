#include <stdint.h>
#include <stdbool.h>
#include <string.h>

#define STATUS_FAILED 0
#define STATUS_SUCCESS 1
#define STATUS_NOT_ENOUGH_SPACE 2
#define UEFI_CPER_RECORD_MIN_SIZE 128
#define UEFI_CPER_RECORD_LENGTH_OFFSET 0
#define UEFI_CPER_RECORD_ID_OFFSET 8

typedef struct MemoryRegion {
    size_t size;
    uint8_t *ram_ptr;
} MemoryRegion;

typedef struct ERSTHeader {
    uint32_t record_count;
} ERSTHeader;

typedef struct ERSTDeviceState {
    MemoryRegion exchange_mr;
    unsigned record_offset;
    ERSTHeader *header;
} ERSTDeviceState;

static inline size_t memory_region_size(const MemoryRegion *mr) {
    return mr->size;
}

static inline uint8_t *memory_region_get_ram_ptr(const MemoryRegion *mr) {
    return mr->ram_ptr;
}

static inline uint32_t le32_to_cpu(uint32_t val) {
    return val;
}

static inline uint64_t le64_to_cpu(uint64_t val) {
    return val;
}

static inline uint32_t cpu_to_le32(uint32_t val) {
    return val;
}

#define ERST_IS_VALID_RECORD_ID(id) (1)

static unsigned lookup_erst_record(ERSTDeviceState *s, uint64_t record_identifier) {
    return 0;
}

static uint8_t *get_nvram_ptr_by_index(ERSTDeviceState *s, unsigned index) {
    return NULL;
}

static unsigned find_next_empty_record_index(ERSTDeviceState *s) {
    return 0;
}

static void update_map_entry(ERSTDeviceState *s, unsigned index, uint64_t record_identifier) {
}