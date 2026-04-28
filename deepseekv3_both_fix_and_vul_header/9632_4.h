#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <arpa/inet.h>
#include <stdint.h>

#define PROTOCOL_BINARY_REQ 0x80

typedef enum {
    conn_closing,
    conn_new_cmd
} conn_states;

typedef enum {
    negotiating_prot,
    binary_prot,
    ascii_prot
} protocol_t;

typedef enum {
    udp_transport,
    tcp_transport
} transport_t;

typedef struct {
    int verbose;
} settings_t;

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
    char *rbuf;
    char *rcurr;
    size_t rsize;
    size_t rbytes;
    int sfd;
    protocol_t protocol;
    transport_t transport;
    protocol_binary_request_header binary_header;
    unsigned int msgcurr;
    unsigned int msgused;
    unsigned int iovused;
    unsigned int cmd;
    unsigned int keylen;
    uint32_t opaque;
    uint64_t cas;
} conn;

extern settings_t settings;

static const char *prot_text(protocol_t prot) {
    static const char *const prot_names[] = {
        "negotiating",
        "binary",
        "ascii"
    };
    return prot_names[prot];
}

static uint64_t ntohll(uint64_t val) {
    return (((uint64_t)ntohl((uint32_t)(val & 0xFFFFFFFF)) << 32) | 
            ntohl((uint32_t)(val >> 32)));
}

static int add_msghdr(conn *c) { return 0; }
static void out_string(conn *c, const char *str) {}
static void dispatch_bin_command(conn *c) {}
static void conn_set_state(conn *c, conn_states state) {}
static void process_command(conn *c, char *command) {}