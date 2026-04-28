#include <stdint.h>
#include <string.h>
#include <stdbool.h>

typedef struct MmsValue MmsValue;

typedef enum {
    MMS_STRING,
    MMS_DATA_ACCESS_ERROR,
    MMS_BOOLEAN,
    MMS_BIT_STRING,
    MMS_INTEGER,
    MMS_UNSIGNED,
    MMS_FLOAT,
    MMS_OCTET_STRING,
    MMS_VISIBLE_STRING,
    MMS_BINARY_TIME,
    MMS_UTC_TIME,
    MMS_ARRAY,
    MMS_STRUCTURE
} MmsType;

typedef enum {
    MMS_DATA_ACCESS_ERROR_SUCCESS = 0,
    MMS_DATA_ACCESS_ERROR_HARDWARE_FAULT,
    MMS_DATA_ACCESS_ERROR_TEMPORARILY_UNAVAILABLE,
    MMS_DATA_ACCESS_ERROR_OBJECT_ACCESS_DENIED,
    MMS_DATA_ACCESS_ERROR_OBJECT_UNDEFINED,
    MMS_DATA_ACCESS_ERROR_INVALID_ADDRESS,
    MMS_DATA_ACCESS_ERROR_TYPE_UNSUPPORTED,
    MMS_DATA_ACCESS_ERROR_TYPE_INCONSISTENT,
    MMS_DATA_ACCESS_ERROR_OBJECT_ATTRIBUTE_INCONSISTENT,
    MMS_DATA_ACCESS_ERROR_OBJECT_VALUE_INVALID,
    MMS_DATA_ACCESS_ERROR_OBJECT_NON_EXISTENT,
    MMS_DATA_ACCESS_ERROR_OBJECT_VALUE_INVALIDATED
} MmsDataAccessError;

typedef struct {
    uint8_t* octets;
    int size;
} Integer;

typedef struct {
    uint8_t* buf;
    int size;
} BitString;

typedef struct {
    uint8_t* buf;
    int size;
} OctetString;

typedef struct {
    uint8_t buf[6];
} BinaryTime;

typedef union {
    int boolean;
    Integer* integer;
    float floatVal;
    double doubleVal;
    OctetString octetString;
    BitString bitString;
    BinaryTime binaryTime;
    char* visibleString;
} MmsValueValue;

struct MmsValue {
    MmsType type;
    MmsValueValue value;
};

extern MmsValue* MmsValue_createEmptyArray(int size);
extern MmsValue* MmsValue_createEmptyStructure(int size);
extern MmsValue* MmsValue_newDataAccessError(MmsDataAccessError error);
extern MmsValue* MmsValue_newBoolean(int boolean);
extern MmsValue* MmsValue_newBitString(int size);
extern MmsValue* MmsValue_newInteger(int size);
extern MmsValue* MmsValue_newUnsigned(int size);
extern MmsValue* MmsValue_newFloat(float value);
extern MmsValue* MmsValue_newDouble(double value);
extern MmsValue* MmsValue_newOctetString(int maxSize, int size);
extern MmsValue* MmsValue_newVisibleStringFromByteArray(uint8_t* buf, int size);
extern MmsValue* MmsValue_newBinaryTime(bool timeQuality);
extern MmsValue* MmsValue_newUtcTime(uint32_t timeval);
extern void MmsValue_setElement(MmsValue* value, int index, MmsValue* element);
extern void MmsValue_setUtcTimeByBuffer(MmsValue* value, uint8_t* buf);
extern void MmsValue_delete(MmsValue* value);

extern int BerDecoder_decodeLength(uint8_t* buffer, int* length, int bufPos, int maxBufPos);
extern uint32_t BerDecoder_decodeUint32(uint8_t* buffer, int length, int bufPos);
extern int BerDecoder_decodeBoolean(uint8_t* buffer, int bufPos);
extern float BerDecoder_decodeFloat(uint8_t* buffer, int bufPos);
extern double BerDecoder_decodeDouble(uint8_t* buffer, int bufPos);

static int getNumberOfElements(uint8_t* buffer, int bufPos, int dataLength);