#include <stdint.h>
#include <string.h>

typedef uint64_t ram_addr_t;

typedef struct RAMBlock {
    char *idstr;
    ram_addr_t length;
    void *mr;
    struct RAMBlock *next;
} RAMBlock;

typedef struct {
    RAMBlock *blocks;
} RAMList;

typedef struct QEMUFile {
    // Placeholder for QEMUFile structure
} QEMUFile;

#define RAM_SAVE_FLAG_CONTINUE (1 << 0)
#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = *(head); (var); (var) = (var)->next)

extern RAMList ram_list;
extern void error_report(const char *fmt, ...);
extern uint8_t qemu_get_byte(QEMUFile *f);
extern void qemu_get_buffer(QEMUFile *f, uint8_t *buf, int size);
extern void *memory_region_get_ram_ptr(void *mr);