#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>
#include <inttypes.h>

#define _U_
#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef struct {
    uint32_t dsi_len;
    struct {
        uint32_t dsi_doff;
    } dsi_data;
} DSI_HEADER;

typedef struct {
    DSI_HEADER header;
    size_t datasize;
    void *start;
    void *eof;
    void *buffer;
} DSI;

#define log_maxdebug 0
#define logtype_dsi "dsi"