#include <stdint.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    // ByteBuffer structure definition
} ByteBuffer;

enum {
    MMS_ERROR_REJECT_INVALID_PDU,
    MMS_ERROR_REJECT_REQUEST_INVALID_ARGUMENT,
    MMS_ERROR_FILE_FILE_NON_EXISTENT,
    MMS_ERROR_FILE_FILENAME_SYNTAX_ERROR
};

int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, int error, ByteBuffer* response);
void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, int error);