#include <stddef.h>
#include <netinet/in.h>

typedef int sctp_disposition_t;
typedef int sctp_subtype_t;
typedef int sctp_cmd_seq_t;

struct sctp_endpoint;
struct sctp_association;
struct sctp_chunk;

struct sk_buff {
    unsigned char *data;
};

struct sctp_chunkhdr {
    unsigned short length;
};
typedef struct sctp_chunkhdr sctp_chunkhdr_t;

struct sctp_heartbeathdr;
typedef struct sctp_heartbeathdr sctp_heartbeathdr_t;

struct sctp_heartbeat_chunk {
    sctp_chunkhdr_t chunk_hdr;
};
typedef struct sctp_heartbeat_chunk sctp_heartbeat_chunk_t;

struct sctp_chunk {
    sctp_chunkhdr_t *chunk_hdr;
    struct {
        sctp_heartbeathdr_t *hb_hdr;
    } subh;
    struct sk_buff *skb;
};

int sctp_vtag_verify(struct sctp_chunk *chunk, const struct sctp_association *asoc);
sctp_disposition_t sctp_sf_pdiscard(const struct sctp_endpoint *ep,
                                   const struct sctp_association *asoc,
                                   const sctp_subtype_t type,
                                   void *arg,
                                   sctp_cmd_seq_t *commands);
int sctp_chunk_length_valid(struct sctp_chunk *chunk, size_t len);
sctp_disposition_t sctp_sf_violation_chunklen(const struct sctp_endpoint *ep,
                                             const struct sctp_association *asoc,
                                             const sctp_subtype_t type,
                                             void *arg,
                                             sctp_cmd_seq_t *commands);
void skb_pull(struct sk_buff *skb, unsigned int len);
struct sctp_chunk *sctp_make_heartbeat_ack(const struct sctp_association *asoc,
                                          struct sctp_chunk *chunk,
                                          sctp_heartbeathdr_t *hb_hdr,
                                          size_t paylen);
void sctp_add_cmd_sf(sctp_cmd_seq_t *commands, int cmd, void *chunk);

#define SCTP_CMD_REPLY 0
#define SCTP_CHUNK(x) ((void *)(x))
#define SCTP_DISPOSITION_CONSUME 0
#define SCTP_DISPOSITION_NOMEM 1