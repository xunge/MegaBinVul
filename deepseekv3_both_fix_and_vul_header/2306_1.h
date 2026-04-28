#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef int Bool;
#define TRUE 1
#define FALSE 0

typedef uint32_t CARD32;

struct _FontInfo {
    char* isStringProp;
    struct _FontProp* props;
    int nprops;
};

struct _FontProp {
    int name;
    int value;
};

typedef struct _FontInfo* FontInfoPtr;
typedef struct _FontFile* FontFilePtr;
typedef struct _PCFTable* PCFTablePtr;
typedef struct _FontProp* FontPropPtr;
typedef struct _FontProp FontPropRec;

#define INT32_MAX 2147483647
#define PCF_PROPERTIES 0
#define PCF_DEFAULT_FORMAT 0

#define PCF_FORMAT_MATCH(format, default) ((format) == (default))
#define IS_EOF(file) (0)

static int position;

static int pcfGetLSB32(FontFilePtr file);
static int pcfGetINT32(FontFilePtr file, int format);
static char pcfGetINT8(FontFilePtr file, int format);
static Bool pcfSeekToType(FontFilePtr file, PCFTablePtr tables, int ntables, int type, int* format, int* size);
static void FontFileRead(FontFilePtr file, char* buf, int len);
static void FontFileSkip(FontFilePtr file, int len);
static int MakeAtom(char* str, int len, Bool makeit);
static void pcfError(const char* format, ...);