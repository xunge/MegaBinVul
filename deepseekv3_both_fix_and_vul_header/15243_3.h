#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define DRM_DEBUG(fmt, ...)
#define DRM_ERROR(fmt, ...)
#define ENOMEM (-12)
#define EINVAL (-22)
#define GFP_KERNEL (0)
#define DMA_BIT_MASK(n) (~0UL >> (64 - (n)))

typedef uint8_t u8;
typedef uint32_t u32;

struct drm_sg_mem {
    void *virtual;
};

struct drm_agp_head {
    unsigned long base;
};

struct drm_map {
    void *handle;
    unsigned long offset;
};

struct drm_device {
    void *dev_private;
    struct drm_sg_mem *sg;
    unsigned long agp_buffer_token;
    struct drm_map *agp_buffer_map;
    struct drm_agp_head *agp;
};

typedef struct {
    int is_pci;
    int usec_timeout;
    int cce_mode;
    int fb_bpp;
    int front_offset;
    int front_pitch;
    int back_offset;
    int back_pitch;
    int depth_bpp;
    int depth_offset;
    int depth_pitch;
    int span_offset;
    unsigned long mmio_offset;
    unsigned long ring_offset;
    unsigned long ring_rptr_offset;
    unsigned long buffers_offset;
    unsigned long agp_textures_offset;
    unsigned long sarea_priv_offset;
    unsigned int ring_size;
} drm_r128_init_t;

typedef struct {
    void *handle;
    unsigned long offset;
    int last_frame;
    int last_dispatch;
} drm_r128_sarea_t;

typedef struct {
    int is_pci;
    int usec_timeout;
    int cce_mode;
    int cce_fifo_size;
    int color_fmt;
    int front_offset;
    int front_pitch;
    int back_offset;
    int back_pitch;
    int depth_fmt;
    int depth_offset;
    int depth_pitch;
    int span_offset;
    unsigned long front_pitch_offset_c;
    unsigned long back_pitch_offset_c;
    unsigned long depth_pitch_offset_c;
    unsigned long span_pitch_offset_c;
    struct drm_map *sarea;
    drm_r128_sarea_t *sarea_priv;
    struct drm_map *mmio;
    struct drm_map *cce_ring;
    struct drm_map *ring_rptr;
    struct drm_map *agp_textures;
    unsigned long cce_buffers_offset;
    int idle_count;
    struct {
        u32 *start;
        u32 *end;
        unsigned int size;
        unsigned int size_l2qw;
        unsigned int tail_mask;
        unsigned int high_mark;
    } ring;
    struct {
        unsigned long table_mask;
        int gart_table_location;
        unsigned int table_size;
        void *addr;
        uintptr_t bus_addr;
        int gart_reg_if;
    } gart_info;
} drm_r128_private_t;

#define R128_MAX_USEC_TIMEOUT 100000
#define R128_PM4_192BM 0
#define R128_PM4_128BM_64INDBM 1
#define R128_PM4_64BM_128INDBM 2
#define R128_PM4_64BM_64VCBM_64INDBM 3
#define R128_PM4_NONPM4 4
#define R128_PM4_192PIO 5
#define R128_PM4_128PIO_64INDBM 6
#define R128_PM4_64PIO_128INDBM 7
#define R128_PM4_64PIO_64VCBM_64INDBM 8
#define R128_PM4_64PIO_64VCPIO_64INDPIO 9
#define R128_DATATYPE_RGB565 0
#define R128_DATATYPE_ARGB8888 1
#define R128_DST_TILE (1 << 30)
#define R128_PCIGART_TABLE_SIZE (64 * 1024)
#define R128_LAST_FRAME_REG 0
#define R128_LAST_DISPATCH_REG 0
#define R128_PCI_GART_PAGE 0
#define DRM_ATI_GART_MAIN 0
#define DRM_ATI_GART_PCI 1

static void *kzalloc(size_t size, int flags) {
    void *ptr = malloc(size);
    if (ptr) memset(ptr, 0, size);
    return ptr;
}

static void atomic_set(int *v, int i) {
    *v = i;
}

static struct drm_map *drm_getsarea(struct drm_device *dev) {
    return NULL;
}

static struct drm_map *drm_core_findmap(struct drm_device *dev, unsigned long offset) {
    return NULL;
}

static int drm_ati_pcigart_init(struct drm_device *dev, void *gart_info) {
    return 0;
}

static unsigned int drm_order(unsigned int size) {
    return size;
}

static void R128_WRITE(int reg, int val) {
}

static void r128_do_cleanup_cce(struct drm_device *dev) {
}

static int r128_cce_load_microcode(drm_r128_private_t *dev_priv) {
    return 0;
}

static void r128_cce_init_ring_buffer(struct drm_device *dev, drm_r128_private_t *dev_priv) {
}

static void r128_do_engine_reset(struct drm_device *dev) {
}