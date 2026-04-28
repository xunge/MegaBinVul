#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>

#define FALSE 0
#define TRUE 1
#define PAGEFLAG_first_page 1
#define PAGEFLAG_last_page 2
#define PAGEFLAG_continued_packet 4
#define VORBIS_packet_id 1
#define VORBIS_packet_setup 3
#define STB_VORBIS_MAX_CHANNELS 16
#define NO_CODE 255
#define EOP (-1)
#define STB_VORBIS_FAST_HUFFMAN_LENGTH 10
#define DIVTAB_NUMER 32
#define DIVTAB_DENOM 32

enum {
    VORBIS_invalid_first_page,
    VORBIS_unexpected_eof,
    VORBIS_too_many_channels,
    VORBIS_invalid_setup,
    VORBIS_outofmem,
    VORBIS_invalid_stream,
    VORBIS_feature_not_supported
};

typedef struct {
    uint8_t *alloc_buffer;
    size_t alloc_buffer_length_in_bytes;
    uint8_t *setup_buffer;
    size_t setup_offset;
    size_t temp_offset;
} stb_vorbis_alloc;

typedef struct {
    int dimensions;
    int entries;
    uint8_t *codeword_lengths;
    uint32_t *codewords;
    uint8_t *sorted_codeword_lengths;
    uint32_t *sorted_codewords;
    int *sorted_values;
    int sorted_entries;
    int lookup_type;
    int sequence_p;
    int sparse;
    int lookup_values;
    float minimum_value;
    float delta_value;
    int value_bits;
    float *multiplicands;
} Codebook;

typedef struct {
    int begin, end;
    int part_size;
    int classifications;
    int classbook;
    uint8_t **classdata;
    int16_t (*residue_books)[8];
} Residue;

typedef struct {
    int order;
    int rate;
    int bark_map_size;
    int amplitude_bits;
    int amplitude_offset;
    int number_of_books;
    uint8_t book_list[16];
} Floor0;

typedef struct {
    int x;
    int id;
} stbv__floor_ordering;

typedef struct {
    int partitions;
    uint8_t partition_class_list[32];
    uint8_t class_dimensions[16];
    uint8_t class_subclasses[16];
    uint8_t class_masterbooks[16];
    int16_t subclass_books[16][8];
    int floor1_multiplier;
    int rangebits;
    int Xlist[256];
    uint8_t sorted_order[256];
    int neighbors[256][2];
    int values;
} Floor1;

typedef union {
    Floor0 floor0;
    Floor1 floor1;
} Floor;

typedef struct {
    int magnitude;
    int angle;
    int mux;
} MappingChannel;

typedef struct {
    int submaps;
    int coupling_steps;
    MappingChannel *chan;
    uint8_t submap_floor[16];
    uint8_t submap_residue[16];
} Mapping;

typedef struct {
    int blockflag;
    int windowtype;
    int transformtype;
    int mapping;
} Mode;

typedef struct vorb {
    stb_vorbis_alloc alloc;
    int channels;
    int sample_rate;
    int blocksize_0;
    int blocksize_1;
    int setup_temp_memory_required;
    int temp_memory_required;
    int first_decode;
    int blocksize[2];
    int previous_length;
    int page_flag;
    int segment_count;
    uint8_t segments[256];
    int error;
    float **channel_buffers;
    float **previous_window;
    int16_t **finalY;
    Codebook *codebooks;
    int codebook_count;
    Floor *floor_config;
    int floor_count;
    uint8_t floor_types[64];
    Residue *residue_config;
    int residue_count;
    uint8_t residue_types[64];
    Mapping *mapping;
    int mapping_count;
    Mode *mode_config;
    int mode_count;
    size_t first_audio_page_offset;
    size_t setup_offset;
    size_t temp_offset;
    int bytes_in_seg;
} vorb;

typedef float codetype;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int16_t int16;

static int integer_divide_table[DIVTAB_NUMER][DIVTAB_DENOM];

static int error(vorb *f, int code) { f->error = code; return FALSE; }
static int ilog(int n) { return n > 1 ? 32 - __builtin_clz(n - 1) : 0; }
static int point_compare(const void *p, const void *q) {
    const stbv__floor_ordering *a = (const stbv__floor_ordering *)p;
    const stbv__floor_ordering *b = (const stbv__floor_ordering *)q;
    return a->x < b->x ? -1 : a->x > b->x;
}
static void neighbors(int *Xlist, int j, int *low, int *hi) {
    *low = j-1;
    *hi = j+1;
}

static int start_page(vorb *f) { return 0; }
static int get8(vorb *f) { return 0; }
static int getn(vorb *f, uint8 *buf, int n) { return 0; }
static int vorbis_validate(uint8 *header) { return 0; }
static int get32(vorb *f) { return 0; }
static int start_packet(vorb *f) { return 0; }
static int next_segment(vorb *f) { return 0; }
static void skip(vorb *f, int len) {}
static int IS_PUSH_MODE(vorb *f) { return 0; }
static int is_whole_packet_present(vorb *f, int flag) { return 0; }
static void crc32_init() {}
static int get8_packet(vorb *f) { return 0; }
static int get_bits(vorb *f, int n) { return 0; }
static void *setup_malloc(vorb *f, size_t size) { return NULL; }
static void CHECK(vorb *f) {}
static void *setup_temp_malloc(vorb *f, size_t size) { return NULL; }
static void setup_temp_free(vorb *f, void *p, size_t size) {}
static int compute_codewords(Codebook *c, uint8 *lengths, int entries, uint32 *values) { return 0; }
static void compute_sorted_huffman(Codebook *c, uint8 *lengths, uint32 *values) {}
static void compute_accelerated_huffman(Codebook *c) {}
static float float32_unpack(uint32 val) { return 0; }
static int lookup1_values(int entries, int dim) { return 0; }
static void flush_packet(vorb *f) {}
static int init_blocksize(vorb *f, int n, int size) { return 0; }
static size_t stb_vorbis_get_file_offset(vorb *f) { return 0; }