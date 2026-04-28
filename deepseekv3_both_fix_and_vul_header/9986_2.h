#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned long long DDWORD;
typedef unsigned char BYTE;

#define PT_UNSPECIFIED 0
#define PT_NULL 1
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

typedef struct {
    BYTE *data;
    int size;
} variableLength;

typedef struct {
    char *name;
    unsigned int id;
} MAPIPropertyTagList;

typedef struct {
    unsigned int id;
    int custom;
    int namedproperty;
    variableLength *propnames;
    int count;
    variableLength *data;
} MAPIProperty;

typedef struct {
    int count;
    MAPIProperty *properties;
} MAPIProps;

typedef struct {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
    int weekday;
} dtr;

#define PROP_TYPE(id) ((id) & 0xFFFF)
#define PROP_ID(id) ((id) >> 16)

static MAPIPropertyTagList MPList[] = {
    {NULL, 0}  // 空列表，实际使用时需要填充
};

extern int MAPISysTimetoDTR(void *data, dtr *thedate);
extern int TNEFPrintDate(dtr thedate);
extern int IsCompressedRTF(variableLength *data);
extern BYTE *DecompressRTF(variableLength *data, int *size);