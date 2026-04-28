#include <stddef.h>
#include <stdint.h>

typedef int grub_err_t;
typedef uint64_t grub_disk_addr_t;
typedef uint64_t grub_off_t;
typedef size_t grub_size_t;

#define GRUB_ERR_NONE 0
#define GRUB_ERR_BAD_FS 1
#define GRUB_DISK_SECTOR_SIZE 512
#define GRUB_DISK_CACHE_BITS 3
#define GRUB_DISK_CACHE_SIZE (1 << GRUB_DISK_CACHE_BITS)
#define GRUB_DISK_SECTOR_BITS 9

struct grub_disk_dev
{
  int id;
  grub_err_t (*read)(void *disk, grub_disk_addr_t sector, grub_size_t size, void *buf);
};

struct grub_disk
{
  struct grub_disk_dev *dev;
  grub_disk_addr_t total_sectors;
  char *name;
  void (*read_hook)(grub_disk_addr_t sector, grub_off_t offset, grub_size_t size, void *closure);
  void *closure;
  int id;
};

typedef struct grub_disk *grub_disk_t;

extern grub_err_t grub_errno;
extern const char *grub_errmsg;

void *grub_malloc(grub_size_t size);
void *grub_realloc(void *ptr, grub_size_t size);
void grub_free(void *ptr);
void *grub_memcpy(void *dest, const void *src, grub_size_t n);
void grub_dprintf(const char *fmt, ...);
void grub_error_push(void);
void grub_error_pop(void);

grub_err_t grub_disk_adjust_range(grub_disk_t disk, grub_disk_addr_t *sector, grub_off_t *offset, grub_size_t size);
char *grub_disk_cache_fetch(int dev_id, int disk_id, grub_disk_addr_t sector);
void grub_disk_cache_unlock(int dev_id, int disk_id, grub_disk_addr_t sector);
void grub_disk_cache_store(int dev_id, int disk_id, grub_disk_addr_t sector, void *data);