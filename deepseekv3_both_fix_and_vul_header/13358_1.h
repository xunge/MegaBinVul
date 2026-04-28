#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

typedef enum {
    LIBSPDM_STATUS_SUCCESS,
    LIBSPDM_STATUS_UNSUPPORTED_CAP
} libspdm_return_t;

#define LIBSPDM_STATUS_IS_ERROR(status) ((status) != LIBSPDM_STATUS_SUCCESS)

typedef enum {
    LIBSPDM_RESPONSE_STATE_NORMAL
} libspdm_response_state_t;

typedef enum {
    LIBSPDM_CONNECTION_STATE_NEGOTIATED
} libspdm_connection_state_t;

typedef enum {
    LIBSPDM_SESSION_STATE_HANDSHAKING
} libspdm_session_state_t;

typedef enum {
    SPDM_ERROR_CODE_VERSION_MISMATCH,
    SPDM_ERROR_CODE_UNSUPPORTED_REQUEST,
    SPDM_ERROR_CODE_UNEXPECTED_REQUEST,
    SPDM_ERROR_CODE_SESSION_REQUIRED,
    SPDM_ERROR_CODE_INVALID_REQUEST,
    SPDM_ERROR_CODE_DECRYPT_ERROR,
    SPDM_ERROR_CODE_UNSPECIFIED
} spdm_error_code_t;

typedef enum {
    SPDM_PSK_EXCHANGE,
    SPDM_PSK_FINISH_RSP
} spdm_request_response_code_t;

typedef enum {
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_PSK_CAP,
    SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_PSK_CAP_RESPONDER_WITH_CONTEXT,
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_HBEAT_CAP,
    SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_HBEAT_CAP
} spdm_capabilities_flags_t;

typedef struct {
    uint8_t spdm_version;
    spdm_request_response_code_t request_response_code;
    uint8_t param1;
    uint8_t param2;
} spdm_message_header_t;

typedef struct {
    spdm_message_header_t header;
} spdm_psk_finish_request_t;

typedef struct {
    spdm_message_header_t header;
} spdm_psk_finish_response_t;

typedef struct {
    void* secured_message_context;
    bool use_psk;
} libspdm_session_info_t;

typedef struct {
    uint32_t last_spdm_request_session_id;
    bool last_spdm_request_session_id_valid;
    libspdm_response_state_t response_state;
    struct {
        struct {
            uint32_t base_hash_algo;
        } algorithm;
        libspdm_connection_state_t connection_state;
    } connection_info;
    struct {
        struct {
            uint32_t heartbeat_period;
        } local_context;
    };
    uint32_t handle_error_return_policy;
} libspdm_context_t;

#define LIBSPDM_MAX_HASH_SIZE 64
#define LIBSPDM_DEBUG_INFO 1
#define LIBSPDM_ENABLE_CAPABILITY_HBEAT_CAP 0
#define LIBSPDM_DATA_HANDLE_ERROR_RETURN_POLICY_DROP_ON_DECRYPT_ERROR 0

#define LIBSPDM_ASSERT(expr) ((void)0)
#define LIBSPDM_DEBUG(expr) ((void)0)

libspdm_return_t libspdm_generate_error_response(libspdm_context_t *context,
                                                spdm_error_code_t error_code,
                                                uint8_t error_data,
                                                size_t *response_size,
                                                void *response);
libspdm_return_t libspdm_responder_handle_response_state(
    libspdm_context_t *context,
    spdm_request_response_code_t request_code,
    size_t *response_size,
    void *response);
bool libspdm_is_capabilities_flag_supported(
    libspdm_context_t *context,
    bool is_requester,
    spdm_capabilities_flags_t req_flag,
    spdm_capabilities_flags_t rsp_flag);
uint8_t libspdm_get_connection_version(libspdm_context_t *context);
libspdm_session_info_t* libspdm_get_session_info_via_session_id(
    libspdm_context_t *context,
    uint32_t session_id);
libspdm_session_state_t libspdm_secured_message_get_session_state(
    void *secured_message_context);
uint32_t libspdm_get_hash_size(uint32_t base_hash_algo);
void libspdm_reset_message_buffer_via_request_code(
    libspdm_context_t *context,
    libspdm_session_info_t *session_info,
    spdm_request_response_code_t request_code);
libspdm_return_t libspdm_append_message_f(
    libspdm_context_t *context,
    libspdm_session_info_t *session_info,
    bool is_requester,
    const void *message,
    size_t message_size);
void libspdm_zero_mem(void *buffer, size_t size);
bool libspdm_verify_psk_finish_req_hmac(
    libspdm_context_t *context,
    libspdm_session_info_t *session_info,
    const uint8_t *hmac,
    size_t hmac_size);
bool libspdm_calculate_th2_hash(
    libspdm_context_t *context,
    libspdm_session_info_t *session_info,
    bool is_requester,
    uint8_t *th2_hash_data);
bool libspdm_generate_session_data_key(
    void *secured_message_context,
    const uint8_t *th2_hash_data);
bool libspdm_start_watchdog(uint32_t session_id, uint32_t timeout);