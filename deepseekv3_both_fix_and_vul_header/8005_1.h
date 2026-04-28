#include <stdint.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    uint16_t len;
    uint16_t offset;
} BT_HDR;

#define BTA_HH_MIN_OFFSET 0
#define GKI_getbuf(size) malloc(size)
#define UINT16 uint16_t
#define UINT8 uint8_t