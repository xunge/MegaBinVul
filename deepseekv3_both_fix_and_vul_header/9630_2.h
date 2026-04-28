#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>
#include <stdint.h>

#define PROTOCOL_BINARY_REQ 0x80
#define NEED_ALIGN

enum protocol {
    negotiating_prot,
    binary_prot,
    ascii_prot
};

enum transport {
    udp_transport
};

enum conn_states {
    conn_closing
};

typedef union {
    struct {
        uint8_t magic;
        uint8_t opcode;
        uint16_t keylen;
        uint32_t bodylen;
        uint32_t opaque;
        uint64_t cas;
    } request;
    uint8_t bytes[24];
} protocol_binary_request_header;

typedef struct {
    int verbose;
} settings_s;

typedef struct conn {
    char *rcurr;
    char *rbuf;
    size_t rsize;
    size_t rbytes;
    enum protocol protocol;
    enum transport transport;
    int sfd;
    protocol_binary_request_header binary_header;
    int msgcurr;
    int msgused;
    int iovused;
    uint8_t cmd;
    uint16_t keylen;
    uint32_t opaque;
    uint64_t cas;
} conn;

extern settings_s settings;

static const char *prot_text(enum protocol prot);
static int add_msghdr(conn *c);
static void out_string(conn *c, const char *str);
static void dispatch_bin_command(conn *c);
static void process_command(conn *c, char *command);
static void conn_set_state(conn *c, int state);

static uint64_t ntohll(uint64_t val) {
    return ((uint64_t)ntohl(val & 0xFFFFFFFF) << 32) | ntohl(val >> 32);
}