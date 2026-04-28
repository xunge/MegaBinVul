#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdint.h>
#include <sys/types.h>

struct ndpi_packet_struct {
    const uint8_t *payload;
    u_int payload_packet_len;
};

typedef unsigned int u_int;

#define ndpi_min(a, b) ((a) < (b) ? (a) : (b))
#define ndpi_isprint(c) isprint((unsigned char)(c))