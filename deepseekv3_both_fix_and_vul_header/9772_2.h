#include <stdint.h>
#include <stddef.h>
#include <sys/socket.h>

typedef uint32_t __u32;

struct sctp_packet {
    __u32 vtag;
    struct sctp_transport *transport;
};

struct sctp_chunk;
struct sctp_transport {
    void *asoc;
};

#define SCTP_DEBUG_PRINTK(fmt, ...)

void sctp_packet_reset(struct sctp_packet *packet);
int sctp_packet_empty(struct sctp_packet *packet);
struct sctp_chunk *sctp_get_ecne_prepend(void *asoc);
void sctp_packet_append_chunk(struct sctp_packet *packet, struct sctp_chunk *chunk);