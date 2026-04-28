#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

typedef enum {
    MMS_ERROR_NONE,
    MMS_ERROR_REJECT_REQUEST_INVALID_ARGUMENT,
    MMS_ERROR_FILE_FILE_ACCESS_DENIED,
    MMS_ERROR_FILE_DUPLICATE_FILENAME,
    MMS_ERROR_ACCESS_TEMPORARILY_UNAVAILABLE,
    MMS_ERROR_REJECT_INVALID_PDU
} MmsError;

typedef enum {
    MMS_FILE_ACCESS_TYPE_OBTAIN
} MmsFileAccessType;

typedef enum {
    MMS_FILE_UPLOAD_STATE_SEND_OBTAIN_FILE_ERROR_DESTINATION,
    MMS_FILE_UPLOAD_STATE_FILE_OPEN_SENT
} MmsFileUploadState;

typedef struct sMmsServer MmsServer;
typedef struct sMmsServerConnection* MmsServerConnection;
typedef struct sByteBuffer* ByteBuffer;
typedef struct sMmsObtainFileTask* MmsObtainFileTask;
typedef void* FileHandle;

struct sMmsServerConnection {
    MmsServer* server;
    void* isoConnection;
};

struct sMmsServer {
    MmsError (*fileAccessHandler)(void*, MmsServerConnection, MmsFileAccessType, const char*, const char*);
    void* fileAccessHandlerParameter;
    bool (*obtainFileHandler)(void*, MmsServerConnection, const char*, const char*);
    void* obtainFileHandlerParameter;
    char* (*getFilesystemBasepath)(MmsServerConnection);
    uint32_t (*getNextRequestInvokeId)(MmsServerConnection);
    MmsObtainFileTask (*getObtainFileTask)(MmsServer*);
    ByteBuffer (*reserveTransmitBuffer)(MmsServer*);
    void (*releaseTransmitBuffer)(MmsServer*);
};

struct sMmsObtainFileTask {
    MmsServerConnection connection;
    uint32_t obtainFileRequestInvokeId;
    uint32_t lastRequestInvokeId;
    FileHandle fileHandle;
    char destinationFilename[256];
    uint64_t nextTimeout;
    MmsFileUploadState state;
#if (CONFIG_MMS_THREADLESS_STACK != 1)
    void* taskLock;
#endif
};

#define DEBUG_MMS_SERVER 0
#define CONFIG_SET_FILESTORE_BASEPATH_AT_RUNTIME 0
#define CONFIG_VIRTUAL_FILESTORE_BASEPATH ""
#define CONFIG_MMS_THREADLESS_STACK 0

extern int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
extern bool mmsMsg_parseFileName(char* filename, uint8_t* buffer, int* bufPos, int maxBufPos, uint32_t invokeId, ByteBuffer* response);
extern void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, MmsError error);
extern void mmsMsg_createMmsRejectPdu(uint32_t* invokeId, MmsError error, ByteBuffer* response);
extern void createServiceErrorObtainFileError(uint32_t invokeId, ByteBuffer* response, MmsError error, int detail);
extern bool FileSystem_getFileInfo(char* filename, void* arg1, void* arg2);
extern FileHandle openFile(char* basepath, char* filename, bool create);
extern void mmsMsg_createExtendedFilename(char* basepath, int maxLen, char* extendedFilename, char* filename);
extern void StringUtils_copyStringMax(char* dest, int maxLen, const char* src);
extern void mmsClient_createFileOpenRequest(uint32_t invokeId, ByteBuffer* request, char* filename, int arg);
extern void IsoConnection_sendMessage(void* isoConnection, ByteBuffer* request);
extern uint64_t Hal_getTimeInMs(void);
extern char* MmsServerConnection_getFilesystemBasepath(MmsServerConnection connection);
extern uint32_t MmsServerConnection_getNextRequestInvokeId(MmsServerConnection connection);
extern MmsObtainFileTask MmsServer_getObtainFileTask(MmsServer* server);
extern ByteBuffer* MmsServer_reserveTransmitBuffer(MmsServer* server);
extern void MmsServer_releaseTransmitBuffer(MmsServer* server);
#if (CONFIG_MMS_THREADLESS_STACK != 1)
extern void Semaphore_post(void* semaphore);
#endif