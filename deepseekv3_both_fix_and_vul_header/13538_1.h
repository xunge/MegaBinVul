#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef enum {
    LIBSPDM_STATUS_SUCCESS,
    LIBSPDM_STATUS_ERROR,
    LIBSPDM_STATUS_SESSION_TRY_DISCARD_KEY_UPDATE,
    LIBSPDM_STATUS_INVALID_STATE_LOCAL,
    LIBSPDM_STATUS_SESSION_MSG_ERROR,
    LIBSPDM_STATUS_RECEIVE_FAIL
} libspdm_return_t;

typedef struct {
    uint8_t request_response_code;
} spdm_message_header_t;

typedef struct {
    uint32_t rtt;
    uint32_t st1;
} libspdm_capability_t;

typedef struct {
    uint8_t ct_exponent;
} libspdm_capability_info_t;

typedef struct {
    libspdm_capability_info_t capability;
} libspdm_connection_info_t;

typedef struct {
    libspdm_capability_t capability;
} libspdm_local_context_t;

typedef struct {
    bool crypto_request;
    libspdm_local_context_t local_context;
    libspdm_connection_info_t connection_info;
    libspdm_return_t (*receive_message)(void*, size_t*, void**, uint64_t);
    size_t (*transport_get_header_size)(void*);
    libspdm_return_t (*transport_decode_message)(void*, uint32_t**, bool*, bool, size_t, void*, size_t*, void**);
    struct {
        uint8_t error_code;
    } last_spdm_error;
} libspdm_context_t;

#define LIBSPDM_DEBUG(expr)
#define LIBSPDM_DEBUG_INFO 0
#define LIBSPDM_STATUS_IS_ERROR(status) ((status) != LIBSPDM_STATUS_SUCCESS)
#define LIBSPDM_ENABLE_CAPABILITY_CHUNK_CAP 0

void* libspdm_get_secured_message_context_via_session_id(void* context, uint32_t session_id);
bool libspdm_activate_update_session_data_key(void* session_context, uint8_t action, bool use_new_key);
bool libspdm_create_update_session_data_key(void* session_context, uint8_t action);
const char* libspdm_get_code_str(uint8_t code);
void LIBSPDM_INTERNAL_DUMP_HEX(void* data, size_t size);
void libspdm_get_scratch_buffer(void* context, void** buffer, size_t* size);
size_t libspdm_get_scratch_buffer_secure_message_offset(void* context);
size_t libspdm_get_scratch_buffer_secure_message_capacity(void* context);

enum {
    SPDM_ERROR_CODE_DECRYPT_ERROR,
    LIBSPDM_KEY_UPDATE_ACTION_RESPONDER
};