#include <stdint.h>
#include <string.h>

typedef uint64_t hwaddr;

typedef struct Rom {
    hwaddr addr;
    size_t romsize;
    size_t datasize;
    uint8_t *data;
    void *fw_file;
    void *mr;
    struct Rom *next;
} Rom;

extern Rom *roms;

#define QTAILQ_FOREACH(var, head, field) \
    for ((var) = (head); (var) != NULL; (var) = (var)->field)