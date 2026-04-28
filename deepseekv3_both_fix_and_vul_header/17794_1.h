#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

struct coap_s;
struct coap_options_list_s;

typedef enum {
    COAP_CT_NONE = -1
} sn_coap_content_format_e;

typedef struct sn_coap_hdr_s {
    uint8_t token_len;
    uint8_t *token_ptr;
    uint16_t uri_path_len;
    uint8_t *uri_path_ptr;
    sn_coap_content_format_e content_format;
    struct coap_options_list_s *options_list_ptr;
} sn_coap_hdr_s;

struct coap_options_list_s {
    uint32_t max_age;
    uint16_t proxy_uri_len;
    uint8_t *proxy_uri_ptr;
    uint16_t etag_len;
    uint8_t *etag_ptr;
    uint8_t uri_host_len;
    uint8_t *uri_host_ptr;
    uint16_t location_path_len;
    uint8_t *location_path_ptr;
    uint16_t uri_port;
    uint16_t location_query_len;
    uint8_t *location_query_ptr;
    uint16_t observe;
    uint16_t uri_query_len;
    uint8_t *uri_query_ptr;
    uint32_t block2;
    uint32_t block1;
    sn_coap_content_format_e accept;
    bool use_size1;
    uint32_t size1;
    bool use_size2;
    uint32_t size2;
};

#define COAP_HEADER_TOKEN_LENGTH_MASK 0x0F
#define COAP_OPTIONS_OPTION_NUMBER_SHIFT 4
#define COAP_OPTION_MAX_AGE 14
#define COAP_OPTION_PROXY_URI 35
#define COAP_OPTION_ETAG 4
#define COAP_OPTION_URI_HOST 3
#define COAP_OPTION_LOCATION_PATH 8
#define COAP_OPTION_URI_PORT 7
#define COAP_OPTION_LOCATION_QUERY 20
#define COAP_OPTION_URI_PATH 11
#define COAP_OPTION_OBSERVE 6
#define COAP_OPTION_URI_QUERY 15
#define COAP_OPTION_BLOCK2 23
#define COAP_OPTION_BLOCK1 27
#define COAP_OPTION_ACCEPT 17
#define COAP_OPTION_SIZE1 60
#define COAP_OPTION_SIZE2 28
#define COAP_OPTION_CONTENT_FORMAT 12
#define COAP_OBSERVE_NONE 0
#define COAP_OPTION_URI_PORT_NONE 0
#define COAP_OPTION_BLOCK_NONE 0

static void tr_error(const char *msg);

static uint16_t sn_coap_parser_move_packet_ptr(uint8_t **packet_data_pptr, uint8_t *packet_data_start_ptr, uint16_t packet_len, uint16_t move_len);
static int8_t sn_coap_parser_check_packet_ptr(uint8_t *packet_ptr, uint8_t *packet_data_start_ptr, uint16_t packet_len, uint16_t needed_len);
static void *sn_coap_protocol_malloc_copy(struct coap_s *handle, uint8_t *source_ptr, uint16_t length);
static int8_t parse_ext_option(uint16_t *option_value_ptr, uint8_t **packet_data_pptr, uint8_t *packet_data_start_ptr, uint16_t packet_len, uint16_t *message_left_ptr);
static void *sn_coap_parser_alloc_options(struct coap_s *handle, sn_coap_hdr_s *dst_coap_msg_ptr);
static uint32_t sn_coap_parser_options_parse_uint(uint8_t **packet_data_pptr, uint16_t option_len);
static int8_t sn_coap_parser_options_parse_multiple_options(struct coap_s *handle, uint8_t **packet_data_pptr, uint16_t message_left, uint8_t **dst_ptr, uint16_t *dst_len_ptr, uint16_t option_number, uint16_t option_len);