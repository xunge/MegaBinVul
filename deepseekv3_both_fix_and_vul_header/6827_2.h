#include <stdint.h>
#include <string.h>

typedef uint8_t uint8;

typedef struct {
    int dimensions;
} Codebook;

typedef struct {
    int begin;
    int end;
    int part_size;
    int classbook;
    int classifications;
    int (*residue_books)[8];
    uint8 **classdata;
} Residue;

typedef struct {
    Residue *residue_config;
    int *residue_types;
    Codebook *codebooks;
    int channels;
} vorb;

#define STB_VORBIS_DIVIDES_IN_RESIDUE
#define STB_VORBIS_DIVIDES_IN_CODEBOOK
#define EOP (-1)

#define CHECK(f) 
#define DECODE(q,f,c) 
#define temp_alloc_save(f) 0
#define temp_block_array(f,ch,sz) NULL
#define temp_free(f,p) 
#define temp_alloc_restore(f,p) 

static int codebook_decode_deinterleave_repeat(vorb *f, Codebook *book, float **residue_buffers, int ch, int *c_inter, int *p_inter, int n, int part_size);
static int residue_decode(vorb *f, Codebook *book, float *target, int offset, int n, int rtype);