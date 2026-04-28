#include <stdio.h>
#include <stdint.h>

typedef uint32_t guint32;

typedef struct {
    uint16_t reserved;
    uint16_t resource_type;
    uint16_t icon_count;
} IcoFileHeader;

static int ico_read_int16(FILE *fp, uint16_t *value, int count);