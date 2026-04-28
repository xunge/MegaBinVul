#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <arpa/inet.h>
#include <time.h>

#define PROTOCOL_BINARY_REQ 0x80
#define BIN_MAX_EXTLEN 24
#define conn_closing 0

typedef union {
    struct {
        uint8_t magic;
        uint8_t opcode;
        uint16_t keylen;
        uint8_t extlen;
        uint8_t datatype;
        uint16_t reserved;
        uint32_t bodylen;
        uint32_t opaque;
        uint64_t cas;
    } request;
    uint8_t bytes[24];
} protocol_binary_request_header;

typedef struct conn {
    int sfd;
    int rbytes;
    char *rcurr;
    protocol_binary_request_header binary_header;
    int cmd;
    uint16_t keylen;
    uint32_t opaque;
    uint64_t cas;
    time_t last_cmd_time;
} conn;

typedef struct {
    int verbose;
} settings_t;

extern settings_t settings;
extern time_t current_time;

static uint64_t ntohll(uint64_t val) {
    return ((uint64_t)ntohl(val & 0xFFFFFFFF) << 32) | ntohl(val >> 32);
}

static int resp_start(conn *c);
static void conn_set_state(conn *c, int state);
static void dispatch_bin_command(conn *c, char *extbuf);