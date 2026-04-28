#include <stdio.h>
#include <stdlib.h>

typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef unsigned char BYTE;

#define YTNEF_INCORRECT_SETUP -1
#define YTNEF_CANNOT_INIT_DATA -2
#define YTNEF_ERROR_READING_DATA -3
#define YTNEF_NOT_TNEF_STREAM -4
#define YTNEF_NO_KEY -5
#define YTNEF_BAD_CHECKSUM -6
#define YTNEF_ERROR_IN_HANDLER -7

#define DEBUG(debug, level, message)
#define DEBUG2(debug, level, format, arg1, arg2)
#define ALLOCCHECK(ptr)

typedef struct {
    int (*InitProc)(void*);
    int (*ReadProc)(void*, size_t, size_t, void*);
    int (*CloseProc)(void*);
} IOStruct;

typedef struct {
    int id;
    char* name;
    int (*handler)(void*, int, char*, size_t);
} TNEFHandler;

typedef struct {
    IOStruct IO;
    int Debug;
} TNEFStruct;

extern TNEFHandler TNEFList[10];  // 假设数组大小为10
extern const size_t TNEFListSize = 10;

extern int TNEFCheckForSignature(DWORD signature);
extern int TNEFGetKey(TNEFStruct* TNEF, WORD* key);
extern int TNEFGetHeader(TNEFStruct* TNEF, DWORD* type, DWORD* size);
extern int TNEFRawRead(TNEFStruct* TNEF, BYTE* data, DWORD size, WORD* checksum);
extern WORD SwapWord(BYTE* data, size_t size);