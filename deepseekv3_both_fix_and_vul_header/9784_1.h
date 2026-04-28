#include <stdint.h>
#include <netinet/in.h>
#include <stddef.h>

typedef uint16_t __u16;

struct sctp_paramhdr {
    uint16_t length;
    uint16_t type;
};
typedef struct sctp_paramhdr sctp_paramhdr_t;

struct sctp_hmac_algo_param {
    sctp_paramhdr_t param_hdr;
    uint16_t hmac_ids[];
};

struct sctp_peer {
    struct sctp_hmac_algo_param *peer_hmacs;
};

struct sctp_association {
    uint16_t default_hmac_id;
    struct sctp_peer peer;
};

struct sctp_hmac {
    const char *hmac_name;
};

#define SCTP_AUTH_HMAC_ID_MAX 3
extern struct sctp_hmac sctp_hmac_list[SCTP_AUTH_HMAC_ID_MAX + 1];