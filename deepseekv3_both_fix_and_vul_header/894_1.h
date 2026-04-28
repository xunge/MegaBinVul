#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <arpa/inet.h>

typedef struct _LIBSSH2_SESSION LIBSSH2_SESSION;
typedef struct _LIBSSH2_CHANNEL LIBSSH2_CHANNEL;
typedef struct _LIBSSH2_PACKET LIBSSH2_PACKET;

struct string_buf {
    unsigned char *data;
    unsigned char *dataptr;
    size_t len;
};

enum libssh2_NB_states {
    libssh2_NB_state_idle = 0,
    libssh2_NB_state_allocated,
    libssh2_NB_state_jump1,
    libssh2_NB_state_jump2,
    libssh2_NB_state_jump3,
    libssh2_NB_state_jump4,
    libssh2_NB_state_jump5,
    libssh2_NB_state_sent,
    libssh2_NB_state_sent1,
    libssh2_NB_state_sent2
};

enum {
    LIBSSH2_MAC_INVALID,
    LIBSSH2_MAC_VALID
};

enum {
    SSH_MSG_DISCONNECT = 1,
    SSH_MSG_IGNORE,
    SSH_MSG_DEBUG,
    SSH_MSG_GLOBAL_REQUEST,
    SSH_MSG_CHANNEL_EXTENDED_DATA,
    SSH_MSG_CHANNEL_DATA,
    SSH_MSG_CHANNEL_EOF,
    SSH_MSG_CHANNEL_REQUEST,
    SSH_MSG_CHANNEL_CLOSE,
    SSH_MSG_CHANNEL_OPEN,
    SSH_MSG_CHANNEL_WINDOW_ADJUST,
    SSH_MSG_KEXINIT,
    SSH_MSG_REQUEST_FAILURE,
    SSH_MSG_CHANNEL_FAILURE
};

enum {
    LIBSSH2_CHANNEL_EXTENDED_DATA_IGNORE = 1
};

enum {
    LIBSSH2_TRACE_TRANS = 1,
    LIBSSH2_TRACE_CONN
};

enum {
    LIBSSH2_STATE_EXCHANGING_KEYS = 1
};

enum {
    LIBSSH2_SOCKET_DISCONNECTED = 1
};

typedef struct {
    int state;
} key_exchange_state_t;

struct _LIBSSH2_SESSION {
    int packAdd_state;
    int socket_state;
    int state;
    int (*ssh_msg_disconnect)(LIBSSH2_SESSION *, uint32_t, const char *, size_t, const char *, size_t);
    int (*ssh_msg_ignore)(LIBSSH2_SESSION *, const char *, size_t);
    int (*ssh_msg_debug)(LIBSSH2_SESSION *, int, const char *, size_t, const char *, size_t);
    int (*macerror)(LIBSSH2_SESSION *, const char *, size_t);
    void *packets;
    LIBSSH2_CHANNEL *packAdd_channelp;
    key_exchange_state_t startup_key_state;
    struct {
        size_t total_num;
    } packet;
    int readPack_state;
    int fullpacket_state;
    struct {
        int state;
    } packAdd_Qlstn_state;
    struct {
        int state;
    } packAdd_x11open_state;
};

struct _LIBSSH2_CHANNEL {
    uint32_t local_id;
    uint32_t remote_id;
    size_t read_avail;
    size_t remote_window_size;
    size_t remote_packet_size;
    int remote_eof;
    int remote_close;
    int exit_status;
    char *exit_signal;
    int remote_extended_data_ignore_mode;
    struct {
        size_t window_size;
    } local;
    struct {
        size_t window_size;
        size_t packet_size;
        int eof;
        int close;
        int extended_data_ignore_mode;
    } remote;
};

struct _LIBSSH2_PACKET {
    unsigned char *data;
    size_t data_len;
    size_t data_head;
    void *node;
};

#define LIBSSH2_ERROR_INVALID_MAC 1
#define LIBSSH2_ERROR_SOCKET_DISCONNECT 2
#define LIBSSH2_ERROR_CHANNEL_UNKNOWN 3
#define LIBSSH2_ERROR_CHANNEL_PACKET_EXCEEDED 4
#define LIBSSH2_ERROR_CHANNEL_WINDOW_EXCEEDED 5
#define LIBSSH2_ERROR_ALLOC 6
#define LIBSSH2_ERROR_EAGAIN 7

#define LIBSSH2_DEBUG(session, always_display, message, message_len, language, language_len) \
    (session)->ssh_msg_debug((session), (always_display), (message), (message_len), (language), (language_len))

#define LIBSSH2_DISCONNECT(session, reason, message, message_len, language, language_len) \
    (session)->ssh_msg_disconnect((session), (reason), (message), (message_len), (language), (language_len))

#define LIBSSH2_IGNORE(session, data, datalen) \
    (session)->ssh_msg_ignore((session), (data), (datalen))

#define LIBSSH2_MACERROR(session, data, datalen) \
    (session)->macerror((session), (data), (datalen))

#define LIBSSH2_FREE(session, ptr) free(ptr)
#define LIBSSH2_ALLOC(session, size) malloc(size)

#define _libssh2_debug(session, trace, ...)
#define _libssh2_error(session, error, message) (error)
#define _libssh2_get_u32(buf, val)
#define _libssh2_get_string(buf, str, len)
#define _libssh2_ntohu32(data) ntohl(*((uint32_t *)(data)))
#define _libssh2_list_add(list, node)
#define _libssh2_channel_locate(session, channel_id) NULL
#define _libssh2_transport_send(session, data, datalen, mac, maclen) 0
#define _libssh2_channel_receive_window_adjust(channel, adjustment, force, window) 0
#define _libssh2_kex_exchange(session, reexchange, state) 0
#define packet_queue_listener(session, data, datalen, state) 0
#define packet_x11_open(session, data, datalen, state) 0