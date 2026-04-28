#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>

#define MAX_BLOCKSIZE 32
#define LIBSSH2_PACKET_MAXPAYLOAD 35000
#define PACKETBUFSIZE 32768

#define LIBSSH2_SESSION_BLOCK_INBOUND 0x01
#define LIBSSH2_STATE_EXCHANGING_KEYS 0x01
#define LIBSSH2_STATE_KEX_ACTIVE 0x02
#define LIBSSH2_STATE_NEWKEYS 0x04

#define LIBSSH2_ERROR_NONE 0
#define LIBSSH2_ERROR_EAGAIN -1
#define LIBSSH2_ERROR_SOCKET_RECV -2
#define LIBSSH2_ERROR_DECRYPT -3
#define LIBSSH2_ERROR_OUT_OF_BOUNDARY -4
#define LIBSSH2_ERROR_ALLOC -5

#define LIBSSH2_SOCKET_DISCONNECTED 0
#define LIBSSH2_TRACE_TRANS 0
#define LIBSSH2_TRACE_SOCKET 0

typedef struct LIBSSH2_SESSION LIBSSH2_SESSION;
typedef struct transportpacket transportpacket;
typedef struct libssh2_mac libssh2_mac;
typedef struct libssh2_crypt libssh2_crypt;

struct transportpacket {
    unsigned char *buf;
    size_t readidx;
    size_t writeidx;
    unsigned char *payload;
    size_t total_num;
    unsigned char *wptr;
    size_t data_num;
    uint32_t packet_length;
    unsigned char padding_length;
    unsigned char init[5];
};

struct libssh2_mac {
    size_t mac_len;
};

struct libssh2_crypt {
    int blocksize;
};

struct LIBSSH2_SESSION {
    transportpacket packet;
    int socket_state;
    int state;
    int socket_block_directions;
    struct {
        libssh2_crypt *crypt;
        libssh2_mac *mac;
    } remote;
    int readPack_state;
    int readPack_encrypted;
    int packAdd_state;
    void *startup_key_state;
    int socket_fd;
};

enum libssh2_NB_states {
    libssh2_NB_state_idle = 0,
    libssh2_NB_state_jump1
};

#define LIBSSH2_RECV(session, buf, len, flags) recv((session)->socket_fd, (buf), (len), (flags))
#define LIBSSH2_SOCKET_RECV_FLAGS(session) 0
#define LIBSSH2_ALLOC(session, size) malloc(size)

void _libssh2_debug(LIBSSH2_SESSION *session, int level, const char *format, ...);
int _libssh2_kex_exchange(LIBSSH2_SESSION *session, int reexchange, void **state);
int decrypt(LIBSSH2_SESSION *session, const unsigned char *src, unsigned char *dest, size_t len);
int fullpacket(LIBSSH2_SESSION *session, int encrypted);
void debugdump(LIBSSH2_SESSION *session, const char *desc, const unsigned char *data, size_t len);
uint32_t _libssh2_ntohu32(const unsigned char *buf);