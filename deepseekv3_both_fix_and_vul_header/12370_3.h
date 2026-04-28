#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

typedef uint32_t uint32;

#define GETINT32(p) (*(uint32_t*)(p))
#define GETINT16(p) (*(uint16_t*)(p))
#define CHECKED_XMALLOC(type, count) (type*)malloc(sizeof(type) * (count))
#define CHECKED_XCALLOC(type, count) (type*)calloc((count), sizeof(type))
#define CHECKINT16(idx, len) assert((idx) + 2 <= (len))
#define CHECKINT32(idx, len) assert((idx) + 4 <= (len))
#define GUID_EXISTS_FLAG 0x8000
#define MULTI_VALUE_FLAG 0x1000
#define szMAPI_STRING 0x1E
#define szMAPI_UNICODE_STRING 0x1F
#define szMAPI_OBJECT 0x41
#define szMAPI_BINARY 0x102
#define szMAPI_SHORT 0x2
#define szMAPI_INT 0x3
#define szMAPI_FLOAT 0x4
#define szMAPI_BOOLEAN 0xB
#define szMAPI_SYSTIME 0x40
#define szMAPI_DOUBLE 0x5
#define szMAPI_APPTIME 0x7
#define szMAPI_CURRENCY 0x6
#define szMAPI_INT8BYTE 0x14
#define szMAPI_CLSID 0x48
#define szMAPI_NULL 0x1
#define szMAPI_ERROR 0xA
#define szMAPI_UNSPECIFIED 0x0
#define ENCODE_SKIP 0
#define DEBUG_ON 0

typedef struct {
    uint8_t data[16];
} GUID;

typedef struct {
    uint32_t len;
    unsigned char* data;
} VarLenData;

typedef struct {
    union {
        uint16_t bytes2;
        uint32_t bytes4;
        uint32_t bytes8[2];
        GUID guid;
        unsigned char* buf;
    } data;
    uint32_t len;
} MAPI_Value;

typedef struct {
    uint16_t type;
    uint16_t name;
    uint32_t num_values;
    uint32_t num_names;
    GUID* guid;
    VarLenData* names;
    MAPI_Value* values;
} MAPI_Attr;

extern void copy_guid_from_buf(GUID* guid, unsigned char* buf, size_t len);
extern unsigned char* unicode_to_utf8(size_t len, unsigned char* buf);
extern size_t pad_to_4byte(size_t len);
extern MAPI_Value* alloc_mapi_values(MAPI_Attr* a);
extern void mapi_attr_dump(MAPI_Attr* attr);