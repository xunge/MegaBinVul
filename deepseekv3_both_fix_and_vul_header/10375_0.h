#include <string.h>
#include <stdlib.h>

typedef struct _StringInfo StringInfo;
typedef unsigned char Quantum;

#define PSDQuantum(count)  (((count)+1) & ~0x01)
#define MSBEndian 1
#define PushLongPixel(endian,p,value) (p+4)
#define PushShortPixel(endian,p,value) (p+2)
#define CopyMagickMemory(destination,source,size) memmove(destination,source,size)
#define LocaleNCompare(s1,s2,n) strncmp(s1,s2,n)

size_t GetStringInfoLength(const StringInfo *);
unsigned char *GetStringInfoDatum(StringInfo *);
void SetStringInfoLength(StringInfo *, size_t);