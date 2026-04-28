#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#define LIBSPDM_ENABLE_CAPABILITY_MUT_AUTH_CAP 1
#define LIBSPDM_ENABLE_CAPABILITY_HBEAT_CAP 1
#define LIBSPDM_MAX_HASH_SIZE 64
#define SPDM_MAX_SLOT_COUNT 8
#define LIBSPDM_DEBUG_INFO 1
#define LIBSPDM_DATA_HANDLE_ERROR_RETURN_POLICY_DROP_ON_DECRYPT_ERROR (1 << 0)

typedef enum {
    LIBSPDM_STATUS_SUCCESS,
    LIBSPDM_STATUS_UNSUPPORTED_CAP
} libspdm_return_t;

#define LIBSPDM_STATUS_IS_ERROR(status) ((status) != LIBSPDM_STATUS_SUCCESS)

typedef enum {
    LIBSPDM_RESPONSE_STATE_NORMAL,
} libspdm_response_state_t;

typedef enum {
    LIBSPDM_CONNECTION_STATE_NEGOTIATED,
} libspdm_connection_state_t;

typedef enum {
    LIBSPDM_SESSION_STATE_HANDSHAKING,
} libspdm_session_state_t;

typedef struct {
    uint8_t spdm_version;
    uint8_t request_response_code;
    uint8_t param1;
    uint8_t param2;
} spdm_message_header_t;

typedef struct {
    spdm_message_header_t header;
    uint8_t param2;
} spdm_finish_request_t;

typedef struct {
    spdm_message_header_t header;
} spdm_finish_response_t;

typedef struct {
    libspdm_connection_state_t connection_state;
    struct {
        uint32_t base_hash_algo;
        uint32_t req_base_asym_alg;
    } algorithm;
} libspdm_connection_info_t;

typedef struct {
    bool use_psk;
    uint32_t mut_auth_requested;
    void* secured_message_context;
} libspdm_session_info_t;

typedef struct {
    uint8_t req_slot_id;
} libspdm_encap_context_t;

typedef struct {
    uint32_t latest_session_id;
    bool last_spdm_request_session_id_valid;
    uint32_t last_spdm_request_session_id;
    libspdm_connection_info_t connection_info;
    libspdm_response_state_t response_state;
    libspdm_encap_context_t encap_context;
    uint32_t handle_error_return_policy;
    struct {
        uint32_t heartbeat_period;
    } local_context;
} libspdm_context_t;

enum {
    SPDM_ERROR_CODE_VERSION_MISMATCH,
    SPDM_ERROR_CODE_UNSUPPORTED_REQUEST,
    SPDM_ERROR_CODE_UNEXPECTED_REQUEST,
    SPDM_ERROR_CODE_SESSION_REQUIRED,
    SPDM_ERROR_CODE_INVALID_REQUEST,
    SPDM_ERROR_CODE_DECRYPT_ERROR,
    SPDM_ERROR_CODE_UNSPECIFIED
};

enum {
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_KEY_EX_CAP,
    SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_KEY_EX_CAP,
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_HANDSHAKE_IN_THE_CLEAR_CAP,
    SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_HANDSHAKE_IN_THE_CLEAR_CAP,
    SPDM_GET_CAPABILITIES_REQUEST_FLAGS_HBEAT_CAP,
    SPDM_GET_CAPABILITIES_RESPONSE_FLAGS_HBEAT_CAP
};

enum {
    SPDM_KEY_EXCHANGE,
    SPDM_FINISH_RSP
};

#define LIBSPDM_DEBUG(debug)
#define LIBSPDM_ASSERT(condition)

libspdm_return_t libspdm_generate_error_response(void* context, int error_code, int param, size_t* response_size, void* response);
libspdm_return_t libspdm_responder_handle_response_state(void* context, int request_response_code, size_t* response_size, void* response);
bool libspdm_is_capabilities_flag_supported(void* context, bool is_requester, int request_flag, int response_flag);
uint8_t libspdm_get_connection_version(void* context);
uint32_t libspdm_get_hash_size(uint32_t algo);
uint32_t libspdm_get_req_asym_signature_size(uint32_t algo);
libspdm_session_info_t* libspdm_get_session_info_via_session_id(void* context, uint32_t session_id);
libspdm_session_state_t libspdm_secured_message_get_session_state(void* context);
void libspdm_reset_message_buffer_via_request_code(void* context, void* session_info, int request_response_code);
libspdm_return_t libspdm_append_message_f(void* context, void* session_info, bool is_app_message, const void* message, size_t message_size);
bool libspdm_verify_finish_req_signature(void* context, void* session_info, const void* signature, size_t signature_size);
bool libspdm_verify_finish_req_hmac(void* context, void* session_info, const void* hmac, size_t hmac_size);
void libspdm_zero_mem(void* buffer, size_t size);
bool libspdm_generate_finish_rsp_hmac(void* context, void* session_info, void* hmac);
bool libspdm_calculate_th2_hash(void* context, void* session_info, bool is_requester, void* hash_data);
bool libspdm_generate_session_data_key(void* context, void* th2_hash_data);
bool libspdm_start_watchdog(uint32_t session_id, uint32_t period);