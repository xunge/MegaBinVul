#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct MmsConnection {
    uint32_t requestTimeout;
} *MmsConnection;

typedef struct ByteBuffer ByteBuffer;

typedef struct MmsOutstandingCall {
    uint64_t timeout;
} *MmsOutstandingCall;

typedef struct MmsFileReadStateMachine {
    void* fileHandle;
    uint32_t readPosition;
    uint32_t frsmId;
    MmsOutstandingCall obtainRequest;
} MmsFileReadStateMachine;

typedef void* FileHandle;

extern int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
extern uint32_t BerDecoder_decodeUint32(uint8_t* buffer, int length, int bufPos);
extern bool mmsMsg_parseFileName(char* filename, uint8_t* buffer, int* bufPos, int maxBufPos, uint32_t invokeId, ByteBuffer* response);
extern MmsFileReadStateMachine* getFreeFrsm(MmsConnection connection);
extern MmsOutstandingCall mmsClient_getMatchingObtainFileRequest(MmsConnection connection, char* filename);
extern uint64_t Hal_getTimeInMs(void);
extern FileHandle mmsMsg_openFile(char* basepath, char* filename, bool write);
extern uint32_t getNextFrsmId(MmsConnection connection);
extern void mmsMsg_createFileOpenResponse(char* basepath, uint32_t invokeId, ByteBuffer* response, char* filename, MmsFileReadStateMachine* frsm);
extern void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, int errorCode);
extern void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, int errorCode, ByteBuffer* response);
extern char* MmsConnection_getFilestoreBasepath(MmsConnection connection);

#define DEBUG_MMS_CLIENT 0

enum {
    MMS_ERROR_FILE_FILE_NON_EXISTENT,
    MMS_ERROR_RESOURCE_OTHER,
    MMS_ERROR_REJECT_REQUEST_INVALID_ARGUMENT,
    MMS_ERROR_REJECT_INVALID_PDU
};