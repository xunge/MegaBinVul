#include <stdint.h>
#include <string.h>
#include <arpa/inet.h>

#define SCTP_AUTH_HMAC_ID_MAX 0
#define SCTP_AUTH_HMAC_ID_SHA1 0
#define EOPNOTSUPP 95
#define EINVAL 22

typedef uint16_t __u16;

typedef struct sctp_paramhdr {
    uint16_t length;
} sctp_paramhdr_t;

struct sctp_endpoint {
    struct {
        uint16_t *hmac_ids;
        sctp_paramhdr_t param_hdr;
    } *auth_hmacs_list;
};

struct sctp_hmacalgo {
    uint16_t shmac_num_idents;
    uint16_t shmac_idents[];
};

struct {
    const char *hmac_name;
} sctp_hmac_list[SCTP_AUTH_HMAC_ID_MAX + 1];