#include <stdint.h>
#include <stddef.h>

typedef struct QXLInstance QXLInstance;

typedef struct QXLReleaseInfo {
    uint64_t id;
    uint64_t next;
} QXLReleaseInfo;

typedef struct QXLReleaseInfoExt {
    int group_id;
    QXLReleaseInfo *info;
} QXLReleaseInfoExt;

typedef struct QXLCommand {
    int type;
} QXLCommand;

typedef struct QXLCommandExt {
    QXLCommand cmd;
} QXLCommandExt;

typedef struct SimpleSpiceUpdate {
    QXLCommandExt ext;
} SimpleSpiceUpdate;

typedef struct QXLReleaseRing {
    uint64_t items[0];
} QXLReleaseRing;

typedef struct QXLRam {
    QXLReleaseRing release_ring;
} QXLRam;

typedef struct PCIQXLDevice {
    struct {
        struct {
            QXLInstance *qxl;
        } ssd;
        QXLRam *ram;
        QXLReleaseInfo *last_release;
        int num_free_res;
        int id;
    };
} PCIQXLDevice;

#define MEMSLOT_GROUP_HOST 0
#define QXL_CMD_DRAW 0

#define container_of(ptr, type, member) \
    ((type *)((char *)(ptr) - offsetof(type, member)))

#define SPICE_RING_PROD_ITEM(qxl, ring, item) \
    do { \
        item = &(ring)->items[0]; \
    } while (0)

void g_assert(int condition);
void qemu_spice_destroy_update(void *ssd, SimpleSpiceUpdate *update);
void qxl_ram_set_dirty(PCIQXLDevice *qxl, void *ptr);
void qxl_ring_set_dirty(PCIQXLDevice *qxl);
void trace_qxl_ring_res_put(int id, int num);
void qxl_push_free_res(PCIQXLDevice *qxl, int flags);