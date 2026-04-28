#include <stdint.h>
#include <string.h>
#include <assert.h>

#define ERROR (-1)
#define OK 0
#define FLAG_SORTED (1 << 0)

typedef struct camera_metadata_buffer_entry {
    int type;
    size_t count;
    union {
        size_t offset;
        uint8_t value[8];
    } data;
} camera_metadata_buffer_entry_t;

typedef struct camera_metadata {
    size_t entry_capacity;
    size_t entry_count;
    size_t data_capacity;
    size_t data_count;
    uint32_t flags;
} camera_metadata_t;

static inline camera_metadata_buffer_entry_t* get_entries(camera_metadata_t *metadata) {
    return (camera_metadata_buffer_entry_t*)(metadata + 1);
}

static inline uint8_t* get_data(camera_metadata_t *metadata) {
    return (uint8_t*)(get_entries(metadata) + metadata->entry_capacity);
}

static int calculate_camera_metadata_entry_data_size(int type, size_t count);
static int validate_camera_metadata_structure(camera_metadata_t *metadata, size_t *expected_size);