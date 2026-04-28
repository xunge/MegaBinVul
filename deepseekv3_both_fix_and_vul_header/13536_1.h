#include <stddef.h>
#include <stdint.h>
#include <string.h>

typedef enum {
    LIBSPDM_STATUS_SUCCESS,
    LIBSPDM_STATUS_INVALID_STATE_LOCAL,
    LIBSPDM_STATUS_INVALID_MSG_SIZE,
    LIBSPDM_STATUS_INVALID_MSG_FIELD,
    LIBSPDM_STATUS_BUFFER_FULL
} libspdm_return_t;

typedef enum {
    LIBSPDM_CONNECTION_STATE_NOT_STARTED,
    LIBSPDM_CONNECTION_STATE_AFTER_VERSION,
    LIBSPDM_CONNECTION_STATE_AFTER_CAPABILITIES
} libspdm_connection_state_t;

typedef struct {
    uint8_t request_response_code;
    uint8_t spdm_version;
    uint8_t param1;
    uint8_t param2;
} spdm_message_header_t;

typedef struct {
    spdm_message_header_t header;
    uint8_t ct_exponent;
    uint32_t flags;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} spdm_get_capabilities_request_t;

typedef struct {
    spdm_message_header_t header;
    uint8_t ct_exponent;
    uint8_t reserved;
    uint16_t reserved2;
    uint32_t flags;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} spdm_capabilities_response_t;

typedef struct {
    uint8_t ct_exponent;
    uint32_t flags;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} libspdm_capability_t;

typedef struct {
    libspdm_capability_t capability;
    libspdm_connection_state_t connection_state;
} libspdm_connection_info_t;

typedef struct {
    libspdm_capability_t capability;
} libspdm_local_context_t;

typedef struct {
    libspdm_connection_info_t connection_info;
    libspdm_local_context_t local_context;
    void *last_spdm_request;
    size_t (*transport_get_header_size)(void *context);
} libspdm_context_t;

#define LIBSPDM_MAX_CT_EXPONENT 0xFF
#define SPDM_MESSAGE_VERSION_11 0x11
#define SPDM_MESSAGE_VERSION_12 0x12
#define SPDM_GET_CAPABILITIES 0xE1
#define SPDM_CAPABILITIES 0x61
#define SPDM_ERROR 0x7F
#define SPDM_MIN_DATA_TRANSFER_SIZE_VERSION_12 42
#define SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_CHUNK_CAP 0x02

#define LIBSPDM_STATUS_IS_ERROR(status) ((status) != LIBSPDM_STATUS_SUCCESS)
#define LIBSPDM_ASSERT(expression) ((void)0)

static inline void libspdm_zero_mem(void *buffer, size_t size) {
    memset(buffer, 0, size);
}

libspdm_return_t libspdm_reset_message_buffer_via_request_code(libspdm_context_t *context, void *buffer, uint8_t request_code);
libspdm_return_t libspdm_acquire_sender_buffer(libspdm_context_t *context, size_t *message_size, void **message);
libspdm_return_t libspdm_release_sender_buffer(libspdm_context_t *context);
uint8_t libspdm_get_connection_version(libspdm_context_t *context);
libspdm_return_t libspdm_send_spdm_request(libspdm_context_t *context, void *buffer, size_t request_size, void *request);
libspdm_return_t libspdm_acquire_receiver_buffer(libspdm_context_t *context, size_t *message_size, void **message);
libspdm_return_t libspdm_receive_spdm_response(libspdm_context_t *context, void *buffer, size_t *response_size, void **response);
libspdm_return_t libspdm_handle_simple_error_response(libspdm_context_t *context, uint8_t error_code);
int validate_responder_capability(uint32_t flags, uint8_t spdm_version);
libspdm_return_t libspdm_append_message_a(libspdm_context_t *context, void *message, size_t message_size);
libspdm_return_t libspdm_release_receiver_buffer(libspdm_context_t *context);