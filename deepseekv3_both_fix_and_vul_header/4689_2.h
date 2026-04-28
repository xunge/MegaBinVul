#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <endian.h>

typedef struct {
    uint32_t value;
    uint32_t reserved;
} FAT_ENTRY;

typedef struct {
    int fat_bits;
    unsigned char *fat;
    uint32_t fat_start;
    uint32_t clusters;
    uint32_t fat_size;
    int nfats;
} DOS_FS;

#define FAT_EOF(fs) ((fs)->fat_bits == 12 ? 0xfff : \
                     (fs)->fat_bits == 16 ? 0xffff : 0xfffffff)
#define FAT_BAD(fs) ((fs)->fat_bits == 12 ? 0xff7 : \
                     (fs)->fat_bits == 16 ? 0xfff7 : 0xffffff7)

extern void get_fat(FAT_ENTRY *entry, unsigned char *fat, uint32_t cluster, DOS_FS *fs);
extern void fs_write(off_t offs, int size, unsigned char *data);
extern void die(const char *fmt, ...);