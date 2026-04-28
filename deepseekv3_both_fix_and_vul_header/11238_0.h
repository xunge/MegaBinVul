#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MagickPathExtent 4096
#define IPTC_ID 0

typedef struct _Image Image;
typedef long long MagickOffsetType;

typedef struct _TokenInfo TokenInfo;

static TokenInfo *AcquireTokenInfo(void);
static TokenInfo *DestroyTokenInfo(TokenInfo *);
static int Tokenizer(TokenInfo *, int, char *, size_t, const char *, const char *, const char *, const char *, int, char *, int *, char *);
static char *super_fgets(char **, int *, Image *);
static void *AcquireQuantumMemory(size_t, size_t);
static char *DestroyString(char *);
static long StringToLong(const char *);
static unsigned long StringToUnsignedLong(const char *);
static size_t convertHTMLcodes(char *, size_t);
static MagickOffsetType TellBlob(Image *);
static MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
static int WriteBlobByte(Image *, unsigned char);
static int WriteBlobString(Image *, const char *);
static int WriteBlobMSBShort(Image *, unsigned short);
static int WriteBlobMSBLong(Image *, unsigned int);