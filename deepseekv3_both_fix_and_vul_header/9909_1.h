#include <stdint.h>
#include <string.h>

#define MAX_OSF_PARTITIONS 8
#define DISKLABELMAGIC 0x82564557
#define PAGE_SIZE 4096
#define BDEVNAME_SIZE 32

typedef uint8_t u8;
typedef uint16_t __le16;
typedef uint32_t __le32;

struct parsed_partitions {
    char name[BDEVNAME_SIZE];
    unsigned char *pp_buf;
    int limit;
};

typedef struct {
    unsigned long dummy;
} Sector;

unsigned char *read_part_sector(struct parsed_partitions *state, int n, Sector *sect);
void put_dev_sector(Sector sect);
void put_partition(struct parsed_partitions *state, int slot, uint32_t offset, uint32_t size);