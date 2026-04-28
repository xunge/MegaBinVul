#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define STATUS_RECORD_NOT_FOUND 0
#define STATUS_RECORD_STORE_EMPTY 1
#define STATUS_FAILED 2
#define STATUS_SUCCESS 3
#define ERST_UNSPECIFIED_RECORD_ID 0
#define ERST_EMPTY_END_RECORD_ID ~0U
#define UEFI_CPER_RECORD_MIN_SIZE 128
#define UEFI_CPER_RECORD_LENGTH_OFFSET 8

typedef struct MemoryRegion {
    size_t size;
    uint8_t *ram;
} MemoryRegion;

typedef struct ERSTHeader {
    uint32_t record_count;
} ERSTHeader;

typedef struct ERSTDeviceState {
    ERSTHeader *header;
    MemoryRegion exchange_mr;
    unsigned record_identifier;
    unsigned record_offset;
} ERSTDeviceState;

static uint32_t le32_to_cpu(uint32_t val) { return val; }
static size_t memory_region_size(MemoryRegion *mr) { return mr->size; }
static uint8_t *memory_region_get_ram_ptr(MemoryRegion *mr) { return mr->ram; }
static void get_next_record_identifier(ERSTDeviceState *s, unsigned *id, bool first) {}
static unsigned lookup_erst_record(ERSTDeviceState *s, unsigned id) { return 0; }
static uint8_t *get_nvram_ptr_by_index(ERSTDeviceState *s, unsigned index) { return NULL; }