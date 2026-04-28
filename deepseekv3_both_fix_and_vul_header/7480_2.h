#include <stdint.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stddef.h>

typedef uint16_t __u16;
typedef uint16_t __be16;

struct sctp_association {
    uint32_t strreset_outseq;
    uint32_t strreset_inseq;
    uint32_t next_tsn;
};

struct sctp_chunk;
struct sctp_paramhdr {
    uint16_t type;
    uint16_t length;
};
struct sctp_strreset_outreq {
    struct sctp_paramhdr param_hdr;
    uint32_t request_seq;
    uint32_t response_seq;
    uint32_t send_reset_at_tsn;
};
struct sctp_strreset_inreq {
    struct sctp_paramhdr param_hdr;
    uint32_t request_seq;
};

#define SCTP_PARAM_RESET_OUT_REQUEST 0
#define SCTP_PARAM_RESET_IN_REQUEST 0

struct sctp_chunk *sctp_make_reconf(const struct sctp_association *asoc, uint16_t len);
void sctp_addto_chunk(struct sctp_chunk *chunk, uint16_t len, const void *data);