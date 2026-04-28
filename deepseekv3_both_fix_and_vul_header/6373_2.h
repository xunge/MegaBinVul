#include <stdio.h>
#include <string.h>

typedef unsigned char Bool;
#define GF_FALSE 0
#define GF_TRUE 1

typedef unsigned int u32;
typedef int GF_Err;
#define GF_OK 0

typedef struct {
    u32 type;
    struct {
        unsigned char *data;
        u32 dataSize;
    } *data;
} GF_ListItemBox;

typedef struct {
    u32 type;
} GF_Box;

typedef struct GF_BitStream GF_BitStream;

#define GF_BITSTREAM_READ 0

enum {
    GF_ISOM_BOX_TYPE_0xA9NAM = 0xA9E6E16D,
    GF_ISOM_BOX_TYPE_0xA9CMT = 0xA9E6E16E,
    GF_ISOM_BOX_TYPE_0xA9DAY = 0xA9E6E16F,
    GF_ISOM_BOX_TYPE_0xA9ART = 0xA9E6E170,
    GF_ISOM_BOX_TYPE_0xA9TRK = 0xA9E6E171,
    GF_ISOM_BOX_TYPE_0xA9ALB = 0xA9E6E172,
    GF_ISOM_BOX_TYPE_0xA9COM = 0xA9E6E173,
    GF_ISOM_BOX_TYPE_0xA9WRT = 0xA9E6E174,
    GF_ISOM_BOX_TYPE_0xA9TOO = 0xA9E6E175,
    GF_ISOM_BOX_TYPE_0xA9CPY = 0xA9E6E176,
    GF_ISOM_BOX_TYPE_0xA9DES = 0xA9E6E177,
    GF_ISOM_BOX_TYPE_0xA9GEN = 0xA9E6E178,
    GF_ISOM_BOX_TYPE_GNRE = 0x474E5245,
    GF_ISOM_BOX_TYPE_aART = 0x61415254,
    GF_ISOM_BOX_TYPE_PGAP = 0x50474150,
    GF_ISOM_BOX_TYPE_DISK = 0x6469736B,
    GF_ISOM_BOX_TYPE_TRKN = 0x74726B6E,
    GF_ISOM_BOX_TYPE_TMPO = 0x746D706F,
    GF_ISOM_BOX_TYPE_CPIL = 0x4350494C,
    GF_ISOM_BOX_TYPE_COVR = 0x434F5652,
    GF_ISOM_BOX_TYPE_iTunesSpecificInfo = 0x69747364,
    GF_ISOM_BOX_TYPE_0xA9GRP = 0xA9E6E179,
    GF_ISOM_ITUNE_ENCODER = 0xA9E6E17A
};

void gf_isom_box_dump_start(GF_Box *a, char *name, FILE *trace);
void gf_isom_box_dump_done(char *name, GF_Box *a, FILE *trace);
GF_BitStream *gf_bs_new(void *data, u32 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);
u32 gf_bs_read_int(GF_BitStream *bs, u32 numBits);
void gf_fprintf(FILE *trace, const char *format, ...);
void dump_data_string(FILE *trace, unsigned char *data, u32 size);
void dump_data(FILE *trace, unsigned char *data, u32 size);