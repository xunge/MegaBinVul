#include <stdint.h>

#define MAX_ETH_FRAME_SIZE 1514

typedef struct NE2000State {
    uint8_t curpag;
    uint8_t boundary;
    uint16_t start;
    uint16_t stop;
} NE2000State;