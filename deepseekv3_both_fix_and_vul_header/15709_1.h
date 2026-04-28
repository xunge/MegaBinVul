#include <stdint.h>
#include <stdlib.h>

#define UBI_MAX_VOLUMES 128
#define UBI_LAYOUT_VOLUME_ID 0
#define UBI_LAYOUT_VOLUME_EBS 2
#define UBI_VTBL_RECORD_SIZE 512
#define EINVAL 22

#define ALIGN(x, a) (((x) + ((a) - 1)) & ~((a) - 1))

#define IS_ERR(x) ((uintptr_t)(x) >= (uintptr_t)(-4095))
#define PTR_ERR(x) ((int)(uintptr_t)(x))

struct ubi_device {
    int leb_size;
    int vtbl_slots;
    int vtbl_size;
    int min_io_size;
    int good_peb_count;
    int corr_peb_count;
    int avail_pebs;
    void *vtbl;
};

struct ubi_attach_info {
    int is_empty;
};

struct ubi_ainf_volume {
    int leb_count;
    int vol_id;
};

struct empty_vtbl_record {
    uint32_t crc;
} empty_vtbl_record;

static inline uint32_t cpu_to_be32(uint32_t x) {
    return ((x & 0xFF) << 24) | ((x & 0xFF00) << 8) | ((x & 0xFF0000) >> 8) | ((x >> 24) & 0xFF);
}

struct ubi_ainf_volume *ubi_find_av(struct ubi_attach_info *ai, int vol_id);
void *create_empty_lvol(struct ubi_device *ubi, struct ubi_attach_info *ai);
void *process_lvol(struct ubi_device *ubi, struct ubi_attach_info *ai, struct ubi_ainf_volume *av);
int init_volumes(struct ubi_device *ubi, struct ubi_attach_info *ai, void *vtbl);
int check_attaching_info(struct ubi_device *ubi, struct ubi_attach_info *ai);
void vfree(void *ptr);
void ubi_free_all_volumes(struct ubi_device *ubi);
void ubi_err(struct ubi_device *ubi, const char *fmt, ...);