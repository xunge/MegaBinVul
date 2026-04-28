#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <endian.h>

#define SECTOR_SIZE 512
#define MSDOS_DIR_BITS 5
#define FAT12_THRESHOLD 4085
#define FAT16_THRESHOLD 65525
#define MSDOS_DPS 16

struct boot_sector {
    uint8_t jump[3];
    uint8_t oem_id[8];
    uint16_t sector_size;
    uint8_t cluster_size;
    uint16_t reserved;
    uint8_t fats;
    uint16_t dir_entries;
    uint16_t sectors;
    uint8_t media;
    uint16_t fat_length;
    uint16_t secs_track;
    uint16_t heads;
    uint32_t hidden;
    uint32_t total_sect;
    uint8_t drive_number;
    uint8_t reserved1;
    uint8_t extended_sig;
    uint32_t serial_number;
    uint8_t label[11];
    uint8_t fs_type[8];
    uint8_t boot_code[448];
    uint16_t boot_signature;
    uint32_t fat32_length;
    uint16_t flags;
    uint8_t version[2];
    uint32_t root_cluster;
    uint16_t fsinfo_sector;
    uint16_t backup_boot;
    uint8_t reserved2[12];
};

struct boot_sector_16 {
    uint8_t jump[3];
    uint8_t oem_id[8];
    uint16_t sector_size;
    uint8_t cluster_size;
    uint16_t reserved;
    uint8_t fats;
    uint16_t dir_entries;
    uint16_t sectors;
    uint8_t media;
    uint16_t fat_length;
    uint16_t secs_track;
    uint16_t heads;
    uint32_t hidden;
    uint32_t total_sect;
    uint8_t drive_number;
    uint8_t reserved1;
    uint8_t extended_sig;
    uint32_t serial_number;
    uint8_t label[11];
    uint8_t fs_type[8];
    uint8_t boot_code[448];
    uint16_t boot_signature;
};

typedef struct {
    int cluster_size;
    int nfats;
    off_t fat_start;
    off_t root_start;
    int root_entries;
    off_t data_start;
    unsigned long data_clusters;
    int root_cluster;
    off_t fsinfo_start;
    int free_clusters;
    int fat_bits;
    int eff_fat_bits;
    unsigned long fat_size;
    uint8_t *label;
    off_t backupboot_start;
} DOS_FS;

static inline uint16_t get_unaligned_le16(const void *p)
{
    const uint8_t *ptr = p;
    return ptr[0] | (ptr[1] << 8);
}

#define GET_UNALIGNED_W(ptr) get_unaligned_le16(ptr)
#define ROUND_TO_MULTIPLE(x, y) (((x) + (y) - 1) / (y) * (y))

extern int verbose;
extern int atari_format;
extern void fs_read(off_t offset, size_t size, void *buffer);
extern void fs_test(off_t offset, size_t size);
extern void die(const char *fmt, ...);
extern void check_fat_state_bit(DOS_FS *fs, struct boot_sector *b);
extern void check_backup_boot(DOS_FS *fs, struct boot_sector *b, unsigned short logical_sector_size);
extern void read_fsinfo(DOS_FS *fs, struct boot_sector *b, unsigned short logical_sector_size);
extern void dump_boot(DOS_FS *fs, struct boot_sector *b, unsigned short logical_sector_size);