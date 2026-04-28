#include <stdint.h>
#include <stddef.h>
#include <inttypes.h>

#define ALOGE(...) 
#define ERROR (-1)
#define OK 0
#define METADATA_ALIGNMENT 4
#define ENTRY_ALIGNMENT 4
#define DATA_ALIGNMENT 8
#define NUM_TYPES 10
#define VENDOR_SECTION 0x8000
#define SN_EVENT_LOG_ID 0
#define ALIGN_TO(ptr, align) (((uintptr_t)(ptr) + (align) - 1) & ~((align) - 1))

typedef uint32_t metadata_size_t;
typedef uint32_t metadata_uptrdiff_t;

typedef struct camera_metadata {
    metadata_size_t size;
    metadata_size_t entry_count;
    metadata_size_t entry_capacity;
    metadata_uptrdiff_t entries_start;
    metadata_size_t data_count;
    metadata_size_t data_capacity;
    metadata_uptrdiff_t data_start;
} camera_metadata_t;

typedef struct camera_metadata_buffer_entry {
    uint32_t tag;
    uint32_t count;
    uint32_t type;
    union {
        uint32_t offset;
        uint32_t value;
    } data;
} camera_metadata_buffer_entry_t;

typedef struct camera_metadata_data {
    uint8_t data[1];
} camera_metadata_data_t;

static inline camera_metadata_buffer_entry_t* get_entries(const camera_metadata_t* metadata) {
    return (camera_metadata_buffer_entry_t*)((uint8_t*)metadata + metadata->entries_start);
}

static inline camera_metadata_data_t* get_data(const camera_metadata_t* metadata) {
    return (camera_metadata_data_t*)((uint8_t*)metadata + metadata->data_start);
}

static inline const char* get_camera_metadata_tag_name(uint32_t tag) {
    return NULL;
}

static inline int get_camera_metadata_tag_type(uint32_t tag) {
    return 0;
}

static inline int validate_and_calculate_camera_metadata_entry_data_size(size_t* data_size, uint32_t type, uint32_t count) {
    return OK;
}

static inline void android_errorWriteLog(int id, const char* msg) {}