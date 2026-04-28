#include <stdint.h>
#include <stddef.h>

typedef struct fastd_socket_t fastd_socket_t;

typedef struct fastd_peer_address_t {
    // Placeholder for peer address structure
} fastd_peer_address_t;

typedef struct fastd_peer_t {
    fastd_peer_address_t local_address;
    // Other peer fields
} fastd_peer_t;

typedef struct fastd_buffer_t {
    uint8_t *data;
    // Other buffer fields
} fastd_buffer_t;

enum {
    PACKET_DATA,
    PACKET_HANDSHAKE
};

struct {
    struct {
        void (*handshake_init)(fastd_socket_t *, const fastd_peer_address_t *, const fastd_peer_address_t *, void *);
        void (*handle_recv)(fastd_peer_t *, fastd_buffer_t *);
    } *protocol;
} conf;

int fastd_peer_may_connect(fastd_peer_t *peer);
int fastd_peer_is_established(fastd_peer_t *peer);
int fastd_peer_address_equal(const fastd_peer_address_t *a, const fastd_peer_address_t *b);
void fastd_buffer_free(fastd_buffer_t *buffer);
int backoff_unknown(const fastd_peer_address_t *addr);
void pr_debug(const char *fmt, ...);
void fastd_handshake_handle(fastd_socket_t *sock, const fastd_peer_address_t *local_addr, const fastd_peer_address_t *remote_addr, fastd_peer_t *peer, fastd_buffer_t *buffer);