#include <stdint.h>
#include <stdlib.h>
#include <wchar.h>
#include <string.h>

#define CB_ASCII_NAMES 0x00000001
#define CHANNEL_RC_OK 0
#define CHANNEL_RC_NO_MEMORY 1
#define ERROR_INVALID_DATA 13
#define ERROR_INTERNAL_ERROR 1359
#define CP_UTF8 65001
#define PRIu32 "u"
#define PRIuz "zu"

typedef unsigned int UINT;
typedef unsigned long DWORD;
typedef uint32_t UINT32;
typedef int BOOL;
#define TRUE 1
#define FALSE 0

typedef wchar_t WCHAR;

struct _wStream {
    void* buffer;
    size_t position;
    size_t length;
};

typedef struct _wStream wStream;
typedef struct _CLIPRDR_FORMAT CLIPRDR_FORMAT;
typedef struct _CLIPRDR_FORMAT_LIST CLIPRDR_FORMAT_LIST;

struct _CLIPRDR_FORMAT {
    UINT32 formatId;
    char* formatName;
};

struct _CLIPRDR_FORMAT_LIST {
    UINT32 msgFlags;
    UINT32 dataLen;
    UINT32 numFormats;
    CLIPRDR_FORMAT* formats;
};

#define TAG "cliprdr"
#define WLog_ERR(tag, fmt, ...)
#define Stream_StaticInit(stream, data, size) \
    do { \
        (stream)->buffer = (data); \
        (stream)->position = 0; \
        (stream)->length = (size); \
    } while (0)
#define Stream_Pointer(stream) ((stream)->buffer)
#define Stream_SafeSeek(stream, offset) \
    (((stream)->position + (offset)) <= (stream)->length ? \
     ((stream)->position += (offset), TRUE) : FALSE)
#define Stream_Capacity(stream) ((stream)->length)
#define Stream_GetRemainingLength(stream) ((stream)->length - (stream)->position)
#define Stream_Read_UINT32(stream, value) \
    do { \
        memcpy(&(value), (char*)(stream)->buffer + (stream)->position, 4); \
        (stream)->position += 4; \
    } while (0)
#define Stream_Seek(stream, offset) ((stream)->position += (offset))
#define Stream_GetPosition(stream) ((stream)->position)
#define Stream_SetPosition(stream, pos) ((stream)->position = (pos))
#define CopyMemory(dest, src, size) memcpy(dest, src, size)
#define ConvertFromUnicode(codepage, flags, src, srcLen, dest, destLen, defChar, usedDefChar) 0
#define _wcsnlen wcsnlen
#define _wcslen wcslen

void cliprdr_free_format_list(CLIPRDR_FORMAT_LIST* formatList);