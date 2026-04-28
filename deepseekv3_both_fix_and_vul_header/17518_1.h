#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef int Bool;
typedef int GF_Err;

#define GF_OK 0
#define GF_ISOM_INVALID_FILE 1
#define GF_BITSTREAM_READ 0

typedef struct GF_BitStream GF_BitStream;

typedef struct GF_Box {
    u32 size;
} GF_Box;

typedef struct GF_AudioSampleEntryBox GF_AudioSampleEntryBox;

typedef struct GF_MPEGAudioSampleEntryBox {
    GF_AudioSampleEntryBox *parent;
    u32 is_qtff;
    void *esd;
} GF_MPEGAudioSampleEntryBox;

u64 gf_bs_get_position(GF_BitStream *bs);
void gf_bs_seek(GF_BitStream *bs, u64 position);
u16 gf_bs_read_u16(GF_BitStream *bs);
u8 gf_bs_read_u8(GF_BitStream *bs);
u32 gf_bs_get_cookie(GF_BitStream *bs);
void gf_bs_read_data(GF_BitStream *bs, char *data, u32 size);
GF_BitStream *gf_bs_new(const void *buffer, u64 size, u32 mode);
void gf_bs_del(GF_BitStream *bs);

GF_Err gf_isom_audio_sample_entry_read(GF_AudioSampleEntryBox *s, GF_BitStream *bs);
GF_Err gf_isom_box_array_read(GF_Box *s, GF_BitStream *bs, GF_Err (*add_box)(GF_Box *s, GF_Box *box));
GF_Err gf_isom_box_parse(GF_Box **box, GF_BitStream *bs);
void gf_isom_box_del(GF_Box *box);
void gf_isom_box_add_for_dump_mode(GF_Box *parent, GF_Box *child);

void *gf_malloc(size_t size);
void gf_free(void *ptr);

#define GF_4CC(a, b, c, d) ((a << 24) | (b << 16) | (c << 8) | d)
#define GF_ISOM_BOX_TYPE_ESDS 0x65736473

extern Bool use_dump_mode;
GF_Err audio_sample_entry_AddBox(GF_Box *s, GF_Box *box);