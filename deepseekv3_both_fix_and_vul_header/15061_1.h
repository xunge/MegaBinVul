#include <stddef.h>
#include <stdint.h>

#define WORD_ROUND(x) (((x) + 3) & ~3)

struct sctp_association;
struct sctp_chunk;

struct sctp_paramhdr {
    uint16_t type;
    uint16_t length;
};
typedef struct sctp_paramhdr sctp_paramhdr_t;

#define SCTP_ERROR_PROTO_VIOLATION 0

void sctp_chunk_free(struct sctp_chunk *chunk);
struct sctp_chunk *sctp_make_op_error_space(const struct sctp_association *asoc,
                                          const struct sctp_chunk *chunk,
                                          size_t payload_len);
void sctp_init_cause(struct sctp_chunk *chunk, uint16_t cause_code, size_t payload_len);
void sctp_addto_chunk(struct sctp_chunk *chunk, size_t len, const void *data);
void sctp_addto_param(struct sctp_chunk *chunk, size_t len, const void *data);