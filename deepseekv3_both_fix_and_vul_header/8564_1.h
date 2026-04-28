#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define ALOGE(...)
#define ERROR (-1)
#define OK 0
#define METADATA_ALIGNMENT 4
#define ENTRY_ALIGNMENT 4
#define DATA_ALIGNMENT 8
#define VENDOR_SECTION 0x8000
#define NUM_TYPES 10

typedef uint32_t metadata_size_t;
typedef uint32_t metadata_uptrdiff_t;

typedef struct camera_metadata {
    metadata_size_t size;
    metadata_size_t entry_count;
    metadata_size_t entry_capacity;
    metadata_uptrdiff_t entries_start;
    metadata_size_t data_capacity;
    metadata_uptrdiff_t data_start;
} camera_metadata_t;

typedef struct camera_metadata_buffer_entry {
    uint32_t tag;
    uint32_t count;
    union {
        uint32_t offset;
        uint32_t value;
    } data;
    uint8_t type;
    uint8_t reserved[3];
} camera_metadata_buffer_entry_t;

typedef struct camera_metadata_rational {
    int32_t numerator;
    int32_t denominator;
} camera_metadata_rational_t;

typedef union camera_metadata_data {
    uint8_t u8;
    int32_t i32;
    float f;
    int64_t i64;
    double d;
    struct camera_metadata_rational r;
} camera_metadata_data_t;

#define ALIGN_TO(ptr, align) (((uintptr_t)(ptr) + (align) - 1) & ~((uintptr_t)(align) - 1))

static const char* get_camera_metadata_tag_name(uint32_t tag) { return NULL; }
static int get_camera_metadata_tag_type(uint32_t tag) { return 0; }
static size_t calculate_camera_metadata_entry_data_size(uint8_t type, uint32_t count) { return 0; }
static camera_metadata_buffer_entry_t* get_entries(const camera_metadata_t* metadata) { return NULL; }
static uint8_t* get_data(const camera_metadata_t* metadata) { return NULL; }