#include <stdint.h>
#include <arpa/inet.h>
#include <linux/types.h>

struct sctp_chunk_hdr {
    __u16 length;
};

struct sctp_chunk {
    struct sctp_chunk_hdr *chunk_hdr;
    int pdiscard;
};