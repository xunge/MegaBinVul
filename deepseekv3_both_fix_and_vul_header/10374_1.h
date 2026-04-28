#include <stddef.h>
#include <sys/types.h>
#include <string.h>

typedef struct _StringInfo {
    unsigned char *datum;
    size_t length;
} StringInfo;

typedef struct _SplayTreeInfo SplayTreeInfo;

typedef struct _Image {
    SplayTreeInfo *profiles;
} Image;

static int LocaleCompare(const char *, const char *);
static int LocaleNCompare(const char *, const char *, size_t);
static void *GetValueFromSplayTree(SplayTreeInfo *, const char *);
static const unsigned char *GetStringInfoDatum(const StringInfo *);
static size_t GetStringInfoLength(const StringInfo *);
static const unsigned char *ReadResourceShort(const unsigned char *, unsigned short *);
static const unsigned char *ReadResourceByte(const unsigned char *, unsigned char *);
static const unsigned char *ReadResourceLong(const unsigned char *, unsigned int *);
static StringInfo *AcquireStringInfo(size_t);
static void *CopyMagickMemory(void *, const void *, size_t);
static void WriteResourceLong(unsigned char *, unsigned int);
static void AddValueToSplayTree(SplayTreeInfo *, const char *, StringInfo *);
static const char *ConstantString(const char *);
static StringInfo *CloneStringInfo(const StringInfo *);
static StringInfo *DestroyStringInfo(StringInfo *);