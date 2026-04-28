#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

typedef enum {
    LIBSPDM_RESPONSE_STATE_NORMAL,
} libspdm_response_state_t;

typedef enum {
    LIBSPDM_CONNECTION_STATE_AFTER_VERSION,
    LIBSPDM_CONNECTION_STATE_AFTER_CAPABILITIES,
} libspdm_connection_state_t;

typedef enum {
    LIBSPDM_STATUS_SUCCESS,
    LIBSPDM_STATUS_ERROR,
} libspdm_return_t;

typedef enum {
    SPDM_ERROR_CODE_UNEXPECTED_REQUEST,
    SPDM_ERROR_CODE_VERSION_MISMATCH,
    SPDM_ERROR_CODE_INVALID_REQUEST,
    SPDM_ERROR_CODE_UNSPECIFIED,
} spdm_error_code_t;

typedef enum {
    SPDM_MESSAGE_VERSION_11,
    SPDM_MESSAGE_VERSION_12,
} spdm_version_t;

typedef enum {
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_CHUNK_CAP,
} spdm_capabilities_flags_t;

typedef enum {
    SPDM_CAPABILITIES,
} spdm_response_code_t;

#define LIBSPDM_MAX_CT_EXPONENT 0
#define SPDM_MIN_DATA_TRANSFER_SIZE_VERSION_12 0
#define LIBSPDM_STATUS_IS_ERROR(status) ((status) != LIBSPDM_STATUS_SUCCESS)

typedef struct {
    spdm_version_t spdm_version;
    spdm_response_code_t request_response_code;
    uint8_t param1;
    uint8_t param2;
} spdm_message_header_t;

typedef struct {
    spdm_message_header_t header;
    spdm_capabilities_flags_t flags;
    uint8_t ct_exponent;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} spdm_get_capabilities_request_t;

typedef struct {
    spdm_message_header_t header;
    uint8_t ct_exponent;
    spdm_capabilities_flags_t flags;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} spdm_capabilities_response_t;

typedef struct {
    uint8_t ct_exponent;
    spdm_capabilities_flags_t flags;
    uint32_t data_transfer_size;
    uint32_t max_spdm_msg_size;
} libspdm_capability_t;

typedef struct {
    libspdm_capability_t capability;
} libspdm_local_context_t;

typedef struct {
    libspdm_capability_t capability;
    libspdm_connection_state_t connection_state;
} libspdm_connection_info_t;

typedef struct {
    libspdm_response_state_t response_state;
    libspdm_connection_info_t connection_info;
    libspdm_local_context_t local_context;
} libspdm_context_t;

libspdm_return_t libspdm_responder_handle_response_state(
    libspdm_context_t *spdm_context,
    spdm_response_code_t request_response_code,
    size_t *response_size,
    void *response);

libspdm_return_t libspdm_generate_error_response(
    libspdm_context_t *spdm_context,
    spdm_error_code_t error_code,
    uint8_t error_data,
    size_t *response_size,
    void *response);

bool libspdm_check_request_version_compatibility(
    libspdm_context_t *spdm_context,
    spdm_version_t spdm_version);

bool libspdm_check_request_flag_compatibility(
    spdm_capabilities_flags_t flags,
    spdm_version_t spdm_version);

void libspdm_reset_message_buffer_via_request_code(
    libspdm_context_t *spdm_context,
    void *buffer,
    spdm_response_code_t request_response_code);

void libspdm_zero_mem(void *buffer, size_t size);

libspdm_return_t libspdm_append_message_a(
    libspdm_context_t *spdm_context,
    const void *message,
    size_t message_size);

void libspdm_set_connection_state(
    libspdm_context_t *spdm_context,
    libspdm_connection_state_t connection_state);

#define LIBSPDM_ASSERT(expr)