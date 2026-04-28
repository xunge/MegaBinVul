#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct {
    uint8_t* buffer;
    int size;
    int maxSize;
} Payload;

typedef struct {
    Payload* payload;
} CotpConnection;

extern bool DEBUG_COTP;