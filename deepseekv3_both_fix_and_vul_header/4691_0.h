#include <stdio.h>
#include <string.h>
#include <stdint.h>

struct boot_sector {
    uint8_t system_id[8];
    uint8_t media;
    uint16_t sector_size;
    uint16_t reserved;
    uint8_t fats;
    uint32_t hidden;
    uint16_t secs_track;
    uint16_t heads;
    uint16_t sectors;
    uint32_t total_sect;
};

typedef struct {
    unsigned cluster_size;
    unsigned fat_bits;
    unsigned fat_size;
    unsigned root_entries;
    unsigned long root_cluster;
    unsigned long long fat_start;
    unsigned long long root_start;
    unsigned long long data_start;
    unsigned long data_clusters;
} DOS_FS;

extern int atari_format;

#define GET_UNALIGNED_W(w) (w)
#define le16toh(x) (x)
#define le32toh(x) (x)

const char *get_media_descr(uint8_t media);