#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

typedef struct {
    uint8_t* buffer;
    int size;
} ByteBuffer;

#define DEBUG_MMS_SERVER 0

enum MMS_ERROR {
    MMS_ERROR_FILE_FILE_NON_EXISTENT
};

extern int addFileEntriesToResponse(const char* basepath, uint8_t* buffer, int curPos, int maxSize, char* directoryName, char** continueAfterFileName, bool* moreFollows);
extern void mmsMsg_createServiceErrorPdu(uint32_t invokeId, ByteBuffer* response, enum MMS_ERROR error);
extern int BerEncoder_UInt32determineEncodedSize(uint32_t value);
extern int BerEncoder_determineLengthSize(uint32_t length);
extern int BerEncoder_encodeTL(uint8_t tag, uint32_t length, uint8_t* buffer, int bufPos);
extern int BerEncoder_encodeUInt32(uint32_t value, uint8_t* buffer, int bufPos);
extern int BerEncoder_encodeBoolean(uint8_t tag, bool value, uint8_t* buffer, int bufPos);