#include <stdint.h>
#include <stddef.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))
#define SSD0323_CMD 0
#define SSD0323_DATA 1
#define EINVAL 22

typedef struct QEMUFile QEMUFile;

typedef struct {
    int cmd_len;
    int cmd;
    int cmd_data[8];
    int row;
    int row_start;
    int row_end;
    int col;
    int col_start;
    int col_end;
    int redraw;
    int remap;
    int mode;
    uint8_t framebuffer[128 * 80 / 2];
} ssd0323_state;

typedef struct SSISlave {
    int cs;
} SSISlave;

static inline uint32_t qemu_get_be32(QEMUFile *f) { return 0; }
static inline void qemu_get_buffer(QEMUFile *f, void *buf, size_t size) {}
#define SSI_SLAVE(obj) ((SSISlave *)obj)