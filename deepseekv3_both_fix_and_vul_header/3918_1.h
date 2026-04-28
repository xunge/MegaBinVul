#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint16_t coap_mid_t;

typedef struct {
    uint8_t *data;
    size_t used_size;
    size_t max_size;
    uint8_t *token;
    uint8_t code;
    uint8_t type;
    coap_mid_t mid;
    size_t hdr_size;
} coap_pdu_t;

typedef struct {
    void *context;
    void *echo;
    void *oscore_encryption;
    int proto;
    int state;
    int csm_block_supported;
    int csm_bert_rem_support;
    size_t partial_write;
    struct {
        struct {
            void *local;
        } addr_info;
    };
} coap_session_t;

typedef struct {
    size_t length;
    uint8_t *s;
} coap_bin_const_t;

typedef struct {
    coap_mid_t id;
    coap_pdu_t *pdu;
    unsigned long timeout;
} coap_queue_t;

typedef struct {
    /* opt_iter fields */
} coap_opt_iterator_t;

typedef void *coap_opt_t;

#define COAP_RESPONSE_CODE(code) (code)
#define COAP_DROPPED_RESPONSE 0
#define COAP_INVALID_MID 0
#define COAP_OPTION_HOP_LIMIT 0
#define COAP_OPTION_ECHO 0
#define COAP_OPTION_BLOCK1 0
#define COAP_OPTION_BLOCK2 0
#define COAP_MESSAGE_ACK 0
#define COAP_EMPTY_CODE 0
#define COAP_MESSAGE_CON 0
#define COAP_PDU_DELAYED 0
#define COAP_SESSION_STATE_ESTABLISHED 0
#define COAP_PROTO_RELIABLE(proto) 0
#define COAP_PDU_IS_REQUEST(pdu) 0
#define COAP_DISABLE_TCP 0
#define HAVE_OSCORE 0
#define COAP_OPT_BLOCK_SZX(opt) 0
#define INET6_ADDRSTRLEN 46

#define coap_log_warn(...)
#define coap_log_debug(...)
#define coap_print_addr(...) 0
#define coap_check_option(...) NULL
#define coap_decode_var_bytes(...) 0
#define coap_update_option(...)
#define coap_encode_var_safe8(...) 0
#define coap_pdu_resize(...) 0
#define coap_insert_option(...) 0
#define coap_add_data(...)
#define coap_delete_bin_const(...)
#define coap_rebuild_pdu_for_proxy(...) 0
#define coap_pdu_encode_header(...) 0
#define coap_send_pdu(...) 0
#define coap_session_delay_pdu(...) 0
#define coap_new_node() NULL
#define coap_prng(...)
#define coap_calc_timeout(...) 0
#define coap_wait_ack(...) 0
#define coap_delete_pdu(...)
#define coap_oscore_new_pdu_encrypted(...) NULL