#include <stdint.h>
#include <string.h>

#define COAP_HEADER_VERSION_MASK 0xC0
#define COAP_HEADER_VERSION_POSITION 6
#define COAP_HEADER_TYPE_MASK 0x30
#define COAP_HEADER_TYPE_POSITION 4
#define COAP_HEADER_TOKEN_LEN_MASK 0x0F
#define COAP_HEADER_TOKEN_LEN_POSITION 0
#define COAP_TOKEN_LEN 8
#define COAP_HEADER_LEN 4
#define COAP_ETAG_LEN 8
#define COAP_MAX_ACCEPT_NUM 2

#define COAP_OPTION_CONTENT_TYPE 1
#define COAP_OPTION_MAX_AGE 2
#define COAP_OPTION_ETAG 3
#define COAP_OPTION_ACCEPT 4
#define COAP_OPTION_IF_MATCH 5
#define COAP_OPTION_IF_NONE_MATCH 6
#define COAP_OPTION_URI_HOST 7
#define COAP_OPTION_URI_PORT 8
#define COAP_OPTION_URI_PATH 9
#define COAP_OPTION_URI_QUERY 10
#define COAP_OPTION_LOCATION_PATH 11
#define COAP_OPTION_LOCATION_QUERY 12
#define COAP_OPTION_PROXY_URI 13
#define COAP_OPTION_OBSERVE 14
#define COAP_OPTION_BLOCK2 15
#define COAP_OPTION_BLOCK1 16
#define COAP_OPTION_SIZE 17
#define COAP_OPTION_TOKEN 19

#define MIN(a, b) ((a) < (b) ? (a) : (b))

typedef enum {
    NO_ERROR,
    BAD_REQUEST_4_00,
    BAD_OPTION_4_02,
    PROXYING_NOT_SUPPORTED_5_05
} coap_status_t;

typedef struct {
    uint8_t *buffer;
    uint8_t version;
    uint8_t type;
    uint8_t token_len;
    uint8_t code;
    uint16_t mid;
    uint8_t token[COAP_TOKEN_LEN];
    uint8_t content_type;
    unsigned long max_age;
    uint8_t etag_len;
    uint8_t etag[COAP_ETAG_LEN];
    uint8_t if_match_len;
    uint8_t if_match[COAP_ETAG_LEN];
    uint8_t if_none_match;
    uint8_t *uri_host;
    uint16_t uri_host_len;
    uint16_t uri_port;
    void *uri_path;
    void *uri_query;
    void *location_path;
    uint16_t location_query_len;
    void *location_query;
    uint8_t *proxy_uri;
    uint16_t proxy_uri_len;
    unsigned long observe;
    unsigned long block2_num;
    uint8_t block2_more;
    uint16_t block2_size;
    unsigned long block2_offset;
    unsigned long block1_num;
    uint8_t block1_more;
    uint16_t block1_size;
    unsigned long block1_offset;
    unsigned long size;
    uint8_t *payload;
    uint16_t payload_len;
    uint8_t accept[COAP_MAX_ACCEPT_NUM];
    uint8_t accept_num;
    uint32_t options;
} coap_packet_t;

extern char *coap_error_message;

#define SET_OPTION(pkt, opt) ((pkt)->options |= (1 << (opt)))
#define PRINTF(...)

unsigned long coap_parse_int_option(uint8_t *data, size_t len);
void coap_add_multi_option(void **dst, uint8_t *option, size_t option_len, uint8_t is_static);
void coap_merge_multi_option(void **dst, uint16_t *dst_len, uint8_t *option, size_t option_len, char separator);