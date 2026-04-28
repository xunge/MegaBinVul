#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct sMmsServerConnection* MmsServerConnection;
typedef struct sByteBuffer* ByteBuffer;
typedef struct sMmsFileReadStateMachine MmsFileReadStateMachine;
typedef void* FileHandle;

typedef enum {
    MMS_ERROR_NONE,
    MMS_ERROR_FILE_FILE_NON_EXISTENT,
    MMS_ERROR_RESOURCE_OTHER,
    MMS_ERROR_REJECT_REQUEST_INVALID_ARGUMENT,
    MMS_ERROR_REJECT_INVALID_PDU
} MmsError;

typedef enum {
    MMS_FILE_ACCESS_TYPE_OPEN
} MmsFileAccessType;

struct sMmsServerConnection {
    struct {
        MmsError (*fileAccessHandler)(void*, MmsServerConnection, MmsFileAccessType, const char*, void*);
        void* fileAccessHandlerParameter;
    }* server;
};

struct sMmsFileReadStateMachine {
    FileHandle fileHandle;
    uint32_t readPosition;
    uint32_t frsmId;
};

extern bool mmsMsg_parseFileName(char* filename, uint8_t* buffer, int* bufPos, int maxBufPos, uint32_t invokeId, ByteBuffer* response);
extern bool mmsMsg_isFilenameSave(const char* filename);
extern void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, MmsError error);
extern void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, MmsError error, ByteBuffer* response);
extern MmsFileReadStateMachine* getFreeFrsm(MmsServerConnection connection);
extern FileHandle openFile(const char* basepath, const char* filename, bool write);
extern uint32_t getNextFrsmId(MmsServerConnection connection);
extern void mmsMsg_createFileOpenResponse(const char* basepath, uint32_t invokeId, ByteBuffer* response, const char* filename, MmsFileReadStateMachine* frsm);
extern const char* MmsServerConnection_getFilesystemBasepath(MmsServerConnection connection);
extern int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
extern uint32_t BerDecoder_decodeUint32(uint8_t* buffer, int length, int bufPos);

#define DEBUG_MMS_CLIENT 0