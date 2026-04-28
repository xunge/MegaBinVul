#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint32_t u32;
typedef uint16_t u16;
typedef uint8_t u8;
typedef int64_t i64;
typedef int64_t sqlite_int64;

#define SQLITE_OK 0
#define SQLITE_NOMEM 7
#define SQLITE_CONSTRAINT 19
#define SQLITE_NULL 5
#define SQLITE_IGNORE 4
#define SQLITE_REPLACE 5

#define ZIPFILE_NEWENTRY_MADEBY 20
#define ZIPFILE_NEWENTRY_REQUIRED 20
#define ZIPFILE_NEWENTRY_FLAGS 0

typedef struct sqlite3_vtab sqlite3_vtab;
typedef struct sqlite3_value sqlite3_value;
typedef struct sqlite3 sqlite3;

struct sqlite3_vtab {
    const void *pModule;
    int nRef;
    char *zErrMsg;
};

struct sqlite3_value {
    unsigned char type;
    union {
        int iVal;
        sqlite_int64 i64Val;
        double rVal;
        const char *zVal;
        const void *pVal;
    } u;
};

struct sqlite3 {
    void *pVfs;
    void *pDb;
    int errCode;
};

typedef struct ZipfileTab ZipfileTab;
typedef struct ZipfileEntry ZipfileEntry;
typedef struct ZipfileCsr ZipfileCsr;
typedef struct ZipfileCDS ZipfileCDS;

struct ZipfileCDS {
    u16 iVersionMadeBy;
    u16 iVersionExtract;
    u16 flags;
    u16 iCompression;
    u32 mTime;
    u32 crc32;
    u32 szCompressed;
    u32 szUncompressed;
    u16 nFile;
    u16 nExtra;
    u16 nComment;
    u16 iInternalAttr;
    u32 iExternalAttr;
    u32 iOffset;
    char *zFile;
};

struct ZipfileEntry {
    ZipfileEntry *pNext;
    ZipfileCDS cds;
    u32 mUnixTime;
    char *zFile;
};

struct ZipfileTab {
    sqlite3_vtab base;
    sqlite3 *db;
    char *zFile;
    FILE *pWriteFd;
    i64 szCurrent;
    ZipfileEntry *pFirstEntry;
    ZipfileCsr *pCsrList;
};

struct ZipfileCsr {
    ZipfileCsr *pCsrNext;
    ZipfileTab *pTab;
    ZipfileEntry *pCurrent;
    int bNoop;
};

u32 crc32(u32 crc, const void *buf, size_t size);
void *sqlite3_mprintf(const char *zFormat, ...);
void sqlite3_free(void*);
const unsigned char *sqlite3_value_blob(sqlite3_value*);
int sqlite3_value_bytes(sqlite3_value*);
int sqlite3_value_int(sqlite3_value*);
const char *sqlite3_value_text(sqlite3_value*);
int sqlite3_value_type(sqlite3_value*);
int sqlite3_vtab_on_conflict(sqlite3*);