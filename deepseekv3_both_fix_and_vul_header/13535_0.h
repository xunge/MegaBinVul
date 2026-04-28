#include <stdint.h>
#include <stddef.h>

typedef enum {
    LIBSPDM_STATUS_INVALID_MSG_SIZE,
    LIBSPDM_STATUS_INVALID_MSG_FIELD,
    LIBSPDM_STATUS_SUCCESS
} libspdm_return_t;

#define LIBSPDM_MAX_RDT_EXPONENT 10
#define LIBSPDM_ASSERT(expr) ((void)0)

typedef struct {
    uint8_t request_response_code;
    uint8_t param1;
} spdm_message_header_t;

typedef struct {
    spdm_message_header_t header;
} spdm_error_response_t;

typedef struct {
    uint8_t request_code;
    uint8_t token;
    uint8_t rd_exponent;
    uint8_t rd_tm;
} spdm_error_data_response_not_ready_t;

typedef struct {
    uint8_t rd_exponent;
    uint8_t request_code;
    uint8_t token;
    uint8_t rd_tm;
} libspdm_error_data_t;

typedef struct {
    libspdm_error_data_t error_data;
} libspdm_context_t;

#define SPDM_ERROR 0x7F
#define SPDM_ERROR_CODE_RESPONSE_NOT_READY 0x42

static void libspdm_sleep(uint64_t duration);
static libspdm_return_t libspdm_requester_respond_if_ready(
    libspdm_context_t *spdm_context,
    const uint32_t *session_id,
    size_t *response_size,
    void **response,
    uint8_t expected_response_code);