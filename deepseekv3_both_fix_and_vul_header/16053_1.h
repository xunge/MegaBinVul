#include <stddef.h>
#include <stdint.h>

typedef struct {
    struct {
        size_t byteIndex;
    } buffer;
} OSCTXT;

typedef unsigned char OSOCTET;
typedef uint64_t OSUINTTYPE;
typedef int64_t OSINTTYPE;
typedef struct {
    size_t numocts;
    OSOCTET* data;
} OSDynOctStr64;
typedef char OSUTF8CHAR;
typedef int OSBOOL;
#define TRUE 1
#define FALSE 0
typedef double OSDOUBLE;
typedef size_t OSSIZE;

#define OSRTCBOR_UINT 0
#define OSRTCBOR_NEGINT 1
#define OSRTCBOR_BYTESTR 2
#define OSRTCBOR_UTF8STR 3
#define OSRTCBOR_ARRAY 4
#define OSRTCBOR_MAP 5
#define OSRTCBOR_FLOAT 7
#define OSRTCBOR_INDEF 31
#define OSRTCBOR_FALSEENC 20
#define OSRTCBOR_TRUEENC 21
#define OSRTCBOR_FLT16ENC 25
#define OSRTCBOR_FLT32ENC 26
#define OSRTCBOR_FLT64ENC 27

#define LOG_RTERR(ctx, err) (err)
#define _NO_INT64_SUPPORT

int rtxReadBytes(OSCTXT* pCborCtxt, OSOCTET* buf, size_t size);
int rtCborDecUInt(OSCTXT* pCborCtxt, OSOCTET ub, OSUINTTYPE* value);
int rtJsonEncUInt64Value(OSCTXT* pJsonCtxt, OSUINTTYPE value);
int rtJsonEncUIntValue(OSCTXT* pJsonCtxt, OSUINTTYPE value);
int rtCborDecInt(OSCTXT* pCborCtxt, OSOCTET ub, OSINTTYPE* value);
int rtJsonEncInt64Value(OSCTXT* pJsonCtxt, OSINTTYPE value);
int rtJsonEncIntValue(OSCTXT* pJsonCtxt, OSINTTYPE value);
int rtCborDecDynByteStr(OSCTXT* pCborCtxt, OSOCTET ub, OSDynOctStr64* byteStr);
int rtJsonEncHexStr(OSCTXT* pJsonCtxt, size_t numocts, OSOCTET* data);
void rtxMemFreePtr(OSCTXT* pCborCtxt, void* ptr);
int rtCborDecDynUTF8Str(OSCTXT* pCborCtxt, OSOCTET ub, char** utf8str);
int rtJsonEncStringValue(OSCTXT* pJsonCtxt, OSUTF8CHAR* str);
int OSRTCBOR_MATCHEOC(OSCTXT* pCborCtxt);
int cborElemNameToJson(OSCTXT* pCborCtxt, OSCTXT* pJsonCtxt);
void OSRTSAFEPUTCHAR(OSCTXT* pJsonCtxt, char ch);
int rtCborDecSize(OSCTXT* pCborCtxt, OSOCTET len, OSSIZE* nitems);
int rtJsonEncBoolValue(OSCTXT* pJsonCtxt, OSBOOL boolval);
int rtCborDecFloat(OSCTXT* pCborCtxt, OSOCTET ub, OSDOUBLE* fltval);
int rtJsonEncDoubleValue(OSCTXT* pJsonCtxt, OSDOUBLE fltval, int prec);
int cborTagNotSupp(OSCTXT* pCborCtxt, OSOCTET tag);
int rtxErrGetErrorCnt(OSCTXT* pCtxt);