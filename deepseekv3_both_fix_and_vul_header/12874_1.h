#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct sMmsServerConnection* MmsServerConnection;
typedef enum eMmsError MmsError;
typedef enum eMmsFileAccessType MmsFileAccessType;

typedef struct {
    MmsError (*fileAccessHandler)(void* parameter, MmsServerConnection connection, MmsFileAccessType accessType, const char* filename, void* parameter2);
    void* fileAccessHandlerParameter;
} MmsServer;

struct sMmsServerConnection {
    MmsServer* server;
};

typedef struct {
    uint8_t* buffer;
    int size;
    int maxSize;
} ByteBuffer;

enum eMmsError {
    MMS_ERROR_NONE,
    MMS_ERROR_REJECT_REQUEST_INVALID_ARGUMENT,
    MMS_ERROR_FILE_FILE_NON_EXISTENT,
    MMS_ERROR_FILE_FILE_ACCESS_DENIED,
    MMS_ERROR_REJECT_INVALID_PDU
};

enum eMmsFileAccessType {
    MMS_FILE_ACCESS_TYPE_DELETE
};

#define DEBUG_MMS_SERVER 0

int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, MmsError error, ByteBuffer* response);
void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, MmsError error);
const char* MmsServerConnection_getFilesystemBasepath(MmsServerConnection connection);
bool getFileInfo(const char* basepath, const char* filename, void* arg1, void* arg2);
bool deleteFile(const char* basepath, const char* filename);
void createNullResponseExtendedTag(uint32_t invokeId, ByteBuffer* response, uint8_t tag);