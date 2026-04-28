#include <stdint.h>
#include <stddef.h>
#include <netinet/in.h>

typedef int sctp_ierror_t;

#define SCTP_PARAM_ACTION_MASK 0xF
#define SCTP_PARAM_ACTION_DISCARD 0
#define SCTP_PARAM_ACTION_SKIP 1
#define SCTP_PARAM_ACTION_DISCARD_ERR 2
#define SCTP_PARAM_ACTION_SKIP_ERR 3

#define SCTP_IERROR_NO_ERROR 0
#define SCTP_IERROR_ERROR 1
#define SCTP_IERROR_NOMEM 2

#define SCTP_ERROR_UNKNOWN_PARAM 0
#define WORD_ROUND(x) (((x) + 3) & ~3)

struct sctp_association;
struct sctp_chunk {
    struct sctp_chunk_hdr *chunk_hdr;
};

struct sctp_chunk_hdr {
    uint16_t length;
};

union sctp_params {
    struct {
        uint16_t type;
        uint16_t length;
    } *p;
    void *v;
};

struct sctp_chunk *sctp_make_op_error_space(const struct sctp_association *asoc, 
                                           struct sctp_chunk *chunk,
                                           uint16_t length);
void sctp_init_cause(struct sctp_chunk *chunk, int error, uint16_t length);
void sctp_addto_chunk(struct sctp_chunk *chunk, uint16_t length, const void *data);