#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef int64_t sqlite_int64;
typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int64_t i64;

#define SQLITE_OK 0
#define SQLITE_NULL 5
#define SQLITE_CONSTRAINT 19
#define SQLITE_NOMEM 7
#define SQLITE_IGNORE 5
#define SQLITE_REPLACE 6

struct sqlite3_vtab {
    int dummy;
    char *zErrMsg;
};

struct sqlite3_vtab_cursor {
    int dummy;
};

struct sqlite3_value {
    int dummy;
};

struct ZipfileCDS {
    u16 iVersionMadeBy;
    u16 iVersionExtract;
    u16 flags;
    u16 iCompression;
    u16 mTime;
    u16 mDate;
    u32 crc32;
    u32 szCompressed;
    u32 szUncompressed;
    u16 nFile;
    u16 nExtra;
    u16 nComment;
    u16 iDiskStart;
    u16 iInternalAttr;
    u32 iExternalAttr;
    u32 iOffset;
    char *zFile;
};

struct ZipfileEntry {
    struct ZipfileEntry *pNext;
    struct ZipfileCDS cds;
    u32 mUnixTime;
};

struct ZipfileCsr {
    struct sqlite3_vtab_cursor base;
    struct ZipfileTab *pTab;
    struct ZipfileEntry *pCurrent;
    struct ZipfileCsr *pCsrNext;
    int bNoop;
};

struct ZipfileTab {
    struct sqlite3_vtab base;
    void *db;
    char *zFile;
    FILE *pWriteFd;
    struct ZipfileEntry *pFirstEntry;
    struct ZipfileCsr *pCsrList;
    i64 szCurrent;
};

#define ZIPFILE_NEWENTRY_MADEBY 20
#define ZIPFILE_NEWENTRY_REQUIRED 20
#define ZIPFILE_NEWENTRY_FLAGS 0

static u32 crc32(u32 crc, const u8 *buf, size_t len) {
    u32 result = 0;
    for (size_t i = 0; i < len; i++) {
        result = (result << 8) ^ buf[i];
    }
    return result;
}

typedef struct sqlite3_vtab sqlite3_vtab;
typedef struct sqlite3_value sqlite3_value;
typedef struct ZipfileTab ZipfileTab;
typedef struct ZipfileEntry ZipfileEntry;
typedef struct ZipfileCsr ZipfileCsr;