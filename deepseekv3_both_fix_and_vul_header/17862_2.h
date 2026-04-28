#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>

typedef unsigned int u_int;
typedef uint16_t u_int16_t;
typedef uint8_t u_int8_t;
typedef uint32_t u_int32_t;

struct ndpi_detection_module_struct;

struct ndpi_packet_struct {
    const u_int8_t *payload;
    u_int payload_packet_len;
    u_int32_t current_time_ms;
};

struct ndpi_ssl_struct {
    char *issuerDN;
    char *subjectDN;
    time_t notBefore;
    time_t notAfter;
    char *client_requested_server_name;
    char *server_names;
    u_int16_t server_names_len;
};

struct ndpi_stun_ssl_struct {
    struct ndpi_ssl_struct ssl;
};

struct ndpi_protocols_struct {
    struct ndpi_stun_ssl_struct stun_ssl;
};

struct ndpi_tls_struct {
    int subprotocol_detected;
};

struct ndpi_tcp_struct {
    struct ndpi_tls_struct tls;
};

struct ndpi_l4_struct {
    struct ndpi_tcp_struct tcp;
};

struct ndpi_flow_struct {
    struct ndpi_packet_struct packet;
    struct ndpi_protocols_struct protos;
    struct ndpi_l4_struct l4;
    u_int32_t risk;
};

struct tm;

#define NDPI_PROTOCOL_TLS 0
#define NDPI_TLS_CERTIFICATE_EXPIRED 0
#define NDPI_TLS_CERTIFICATE_MISMATCH 0
#define NDPI_TLS_SELFSIGNED_CERTIFICATE 0

#define NDPI_SET_BIT(risk, flag) ((risk) |= (flag))

extern int extractRDNSequence(struct ndpi_packet_struct *packet, int i, char *buffer, size_t buffer_size, 
                             char *rdnSeqBuf, u_int *rdn_len, size_t rdnSeqBuf_size, const char *type);
extern void cleanupServerName(char *dNSName, u_int8_t len);
extern int ndpi_match_hostname_protocol(struct ndpi_detection_module_struct *ndpi_struct, 
                                       struct ndpi_flow_struct *flow, u_int16_t protocol, 
                                       char *name, u_int16_t name_len);
extern char* ndpi_strdup(const char *s);
extern void* ndpi_realloc(void *ptr, size_t old_size, size_t new_size);
extern time_t timegm(struct tm *tm);
extern char *strptime(const char *s, const char *format, struct tm *tm);