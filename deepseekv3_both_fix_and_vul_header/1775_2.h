#include <stddef.h>
#include <stdint.h>
#include <sys/types.h>

#define ETH_ALEN 6
#define PTR_ERR(ptr) ((long)(ptr))
#define IS_ERR(ptr) ((unsigned long)(ptr) > (unsigned long)(-1000))
#define EINVAL 22

typedef uint8_t u8;

struct device;
struct device_node;
struct nvmem_cell;

void *nvmem_cell_read(struct nvmem_cell *cell, ssize_t *len);
struct nvmem_cell *of_nvmem_cell_get(struct device_node *np, const char *name);
void nvmem_cell_put(struct nvmem_cell *cell);
void kfree(void *ptr);
int is_valid_ether_addr(const uint8_t *addr);
void ether_addr_copy(void *dst, const void *src);
void spl2sw_check_mac_vendor_id_and_convert(uint8_t *mac);
void dev_info(struct device *dev, const char *fmt, ...);