#include <stdint.h>
#include <stdlib.h>

#define GPT_HEADER_SIGNATURE 0x5452415020494645ULL

typedef uint32_t u32;
typedef uint64_t u64;

struct parsed_partitions {
    void *bdev;
};

typedef struct gpt_header {
    uint64_t signature;
    uint32_t header_crc32;
    uint32_t header_size;
    uint64_t my_lba;
    uint64_t first_usable_lba;
    uint64_t last_usable_lba;
    uint32_t num_partition_entries;
    uint32_t sizeof_partition_entry;
    uint32_t partition_entry_array_crc32;
} gpt_header;

typedef struct gpt_entry {
    uint8_t partition_type_guid[16];
    uint8_t unique_partition_guid[16];
    uint64_t starting_lba;
    uint64_t ending_lba;
    uint64_t attributes;
    uint16_t partition_name[36];
} gpt_entry;

extern gpt_header *alloc_read_gpt_header(struct parsed_partitions *state, u64 lba);
extern gpt_entry *alloc_read_gpt_entries(struct parsed_partitions *state, gpt_header *gpt);
extern u64 last_lba(void *bdev);
extern u32 efi_crc32(const unsigned char *buf, u32 len);
extern void kfree(void *ptr);

#define pr_debug(fmt, ...)

static inline uint64_t le64_to_cpu(uint64_t x) { return x; }
static inline uint32_t le32_to_cpu(uint32_t x) { return x; }
static inline uint32_t cpu_to_le32(uint32_t x) { return x; }