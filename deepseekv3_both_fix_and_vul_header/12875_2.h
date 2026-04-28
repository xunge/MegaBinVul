#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct sByteBuffer ByteBuffer;
typedef struct sMmsServerConnection* MmsServerConnection;
typedef struct sMmsServer MmsServer;

typedef enum eMmsError {
    MMS_ERROR_NONE,
    MMS_ERROR_REJECT_INVALID_PDU,
    MMS_ERROR_FILE_FILE_NON_EXISTENT,
    MMS_ERROR_FILE_OTHER
} MmsError;

typedef enum eMmsFileAccessType {
    MMS_FILE_ACCESS_TYPE_RENAME
} MmsFileAccessType;

struct sMmsServerConnection {
    MmsServer* server;
};

struct sMmsServer {
    MmsError (*fileAccessHandler)(void*, MmsServerConnection, MmsFileAccessType, const char*, const char*);
    void* fileAccessHandlerParameter;
};

#define DEBUG_MMS_SERVER 0

int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
bool mmsMsg_parseFileName(char* fileName, uint8_t* buffer, int* bufPos, int maxBufPos, uint32_t invokeId, ByteBuffer* response);
void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, MmsError error, ByteBuffer* response);
bool mmsMsg_isFilenameSave(const char* filename);
void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, MmsError error);
const char* MmsServerConnection_getFilesystemBasepath(MmsServerConnection connection);
bool renameFile(const char* basepath, const char* oldName, const char* newName);
void createNullResponseExtendedTag(uint32_t invokeId, ByteBuffer* response, uint8_t tag);