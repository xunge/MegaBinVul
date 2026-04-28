#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MaxTextExtent 4096
#define IPTC_ID 0x0404

typedef long long MagickOffsetType;

typedef struct _Image Image;
typedef struct _TokenInfo TokenInfo;

static TokenInfo *AcquireTokenInfo(void);
static TokenInfo *DestroyTokenInfo(TokenInfo *);
static char *AcquireQuantumMemory(size_t, size_t);
static char *DestroyString(char *);
static int super_fgets(char **, int *, Image *);
static int Tokenizer(TokenInfo *, int, char *, size_t, const char *, const char *, const char *, const char *, int, char *, int *, char *);
static long StringToLong(const char *);
static unsigned long StringToUnsignedLong(const char *);
static size_t convertHTMLcodes(char *, int);
static MagickOffsetType TellBlob(Image *);
static MagickOffsetType SeekBlob(Image *, MagickOffsetType, int);
static int WriteBlobByte(Image *, unsigned char);
static int WriteBlobString(Image *, const char *);
static int WriteBlobMSBShort(Image *, unsigned short);
static int WriteBlobMSBLong(Image *, unsigned int);