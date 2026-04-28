#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

typedef unsigned char BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef uint64_t DDWORD;

#define MV_FLAG 0x1000
#define PROP_ID(x) ((x) & 0xFFFF)
#define PROP_TYPE(x) ((x) >> 16)
#define PROP_TAG(type, id) (((type) << 16) | (id))

#define PT_I2 2
#define PT_LONG 3
#define PT_R4 4
#define PT_DOUBLE 5
#define PT_CURRENCY 6
#define PT_APPTIME 7
#define PT_ERROR 10
#define PT_BOOLEAN 11
#define PT_OBJECT 13
#define PT_I8 20
#define PT_STRING8 30
#define PT_UNICODE 31
#define PT_SYSTIME 64
#define PT_CLSID 72
#define PT_BINARY 258

#define PR_SUBJECT 0x0037001E
#define PR_SUBJECT_IPM 0x0037001F
#define PR_ORIGINAL_SUBJECT 0x0049001E
#define PR_NORMALIZED_SUBJECT 0x0E1D001E
#define PR_CONVERSATION_TOPIC 0x0070001E

typedef struct {
    BYTE *data;
    DWORD size;
} variableLength;

typedef struct {
    DWORD id;
    int custom;
    DWORD count;
    int namedproperty;
    BYTE guid[16];
    variableLength *propnames;
    variableLength *data;
} MAPIProperty;

typedef struct {
    DWORD count;
    MAPIProperty *properties;
} MAPIProps;

typedef struct {
    int Debug;
    variableLength subject;
} TNEFStruct;

#define ALLOCCHECK(ptr) if ((ptr) == NULL) { printf("Memory allocation failed\n"); exit(-1); }
#define SIZECHECK(size) if ((d + (size)) > (data + size)) { printf("Buffer overflow\n"); exit(-1); }
#define DEBUG(level, threshold, msg) if ((level) >= (threshold)) printf("%s", msg)
#define DEBUG2(level, threshold, fmt, arg1, arg2) if ((level) >= (threshold)) printf(fmt, (unsigned int)arg1, (unsigned int)arg2)

DWORD SwapDWord(BYTE *data, int size);
WORD SwapWord(BYTE *data, int size);
DDWORD SwapDDWord(BYTE *data, int size);
BYTE *to_utf8(DWORD size, char *data);