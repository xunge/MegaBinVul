#include <stdio.h>
#include <string.h>

typedef unsigned char Bool;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef enum {
    GF_OK,
    GF_BITSTREAM_READ
} GF_Err;

typedef struct {
    unsigned char *data;
    u32 dataLength;
} GF_DefaultDescriptor;

typedef struct {
    u32 position;
} GF_BitStream;

GF_BitStream *gf_bs_new(unsigned char *data, u32 length, GF_Err mode);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
u32 gf_bs_available(GF_BitStream *bs);
void gf_bs_del(GF_BitStream *bs);
u32 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char *buffer, u32 size);

void StartDescDump(FILE *trace, const char *name, u32 indent, Bool XMTDump);
void DumpString(FILE *trace, const char *name, const char *value, u32 indent, Bool XMTDump);
void StartAttribute(FILE *trace, const char *name, u32 indent, Bool XMTDump);
void EndAttribute(FILE *trace, u32 indent, Bool XMTDump);
void EndAttributes(FILE *trace, u32 indent, Bool XMTDump);
void EndDescDump(FILE *trace, const char *name, u32 indent, Bool XMTDump);
void DumpData(FILE *trace, const char *name, char *data, u32 len, u32 indent, Bool XMTDump);
int gf_fprintf(FILE *stream, const char *format, ...);