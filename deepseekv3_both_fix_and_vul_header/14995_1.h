#include <stdint.h>
#include <stddef.h>

#define HANDSHAKE_HEADER_SIZE 4
#define SSL2_HEADERS 1
#define GNUTLS_HANDSHAKE 1
#define GNUTLS_E_UNEXPECTED_PACKET_LENGTH -1
#define GNUTLS_E_UNEXPECTED_HANDSHAKE_PACKET -2

typedef int gnutls_handshake_description_t;
#define GNUTLS_HANDSHAKE_CLIENT_HELLO 1

typedef struct {
    size_t header_size;
    uint32_t packet_length;
    gnutls_handshake_description_t recv_type;
    uint8_t header[HANDSHAKE_HEADER_SIZE];
} handshake_header_buffer_t;

typedef struct {
    unsigned int v2_hello;
    handshake_header_buffer_t handshake_header_buffer;
} gnutls_internals_t;

typedef struct gnutls_session_int {
    gnutls_internals_t internals;
} *gnutls_session_t;

int _gnutls_handshake_io_recv_int(gnutls_session_t session, int type1, 
    gnutls_handshake_description_t type2, uint8_t *data, size_t size);
const char* _gnutls_handshake2str(gnutls_handshake_description_t type);
void _gnutls_handshake_log(const char *format, ...);
uint32_t _gnutls_read_uint24(const uint8_t *data);
void gnutls_assert(void);