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
#define STB_VORBIS_FAST_HUFFMAN_LENGTH 10
#define NO_CODE 255
#define EOP (-1)
#define VORBIS_invalid_first_page 1
#define VORBIS_invalid_setup 2
#define VORBIS_unexpected_eof 3
#define VORBIS_outofmem 4
#define VORBIS_feature_not_supported 5
#define VORBIS_too_many_channels 6
#define VORBIS_invalid_stream 7
#define VORBIS_ogg_skeleton_not_supported 8

typedef struct vorb vorb;

typedef struct {
    uint8_t dimensions;
    uint32_t entries;
    uint8_t sparse;
    uint8_t *codeword_lengths;
    uint32_t *codewords;
    uint32_t *sorted_codewords;
    int *sorted_values;
    int sorted_entries;
    uint8_t lookup_type;
    float minimum_value;
    float delta_value;
    uint8_t value_bits;
    uint8_t sequence_p;
    uint32_t lookup_values;
    float *multiplicands;
} Codebook;

typedef struct {
    uint8_t order;
    uint16_t rate;
    uint16_t bark_map_size;
    uint8_t amplitude_bits;
    uint8_t amplitude_offset;
    uint8_t number_of_books;
    uint8_t book_list[16];
} Floor0;

typedef struct {
    uint8_t partitions;
    uint8_t partition_class_list[31];
    uint8_t class_dimensions[16];
    uint8_t class_subclasses[16];
    uint8_t class_masterbooks[16];
    int8_t subclass_books[16][4];
    uint8_t floor1_multiplier;
    uint8_t rangebits;
    uint16_t Xlist[31*8+2];
    uint8_t sorted_order[31*8+2];
    uint16_t neighbors[31*8+2][2];
    uint16_t values;
} Floor1;

typedef union {
    Floor0 floor0;
    Floor1 floor1;
} Floor;

typedef struct {
    uint32_t begin;
    uint32_t end;
    uint32_t part_size;
    uint8_t classifications;
    uint8_t classbook;
    short (*residue_books)[8];
    uint8_t **classdata;
} Residue;

typedef struct {
    uint8_t mux;
    uint8_t magnitude;
    uint8_t angle;
} MappingChannel;

typedef struct {
    uint8_t submaps;
    uint8_t coupling_steps;
    MappingChannel *chan;
    uint8_t submap_floor[16];
    uint8_t submap_residue[16];
} Mapping;

typedef struct {
    uint8_t blockflag;
    uint16_t windowtype;
    uint16_t transformtype;
    uint8_t mapping;
} Mode;

typedef struct {
    int x;
    int id;
} stbv__floor_ordering;

struct vorb {
    uint8_t page_flag;
    int segment_count;
    uint8_t segments[255];
    int channels;
    uint32_t sample_rate;
    uint16_t blocksize_0;
    uint16_t blocksize_1;
    int error;
    uint8_t *setup_temp_memory;
    size_t setup_temp_memory_required;
    void *(*setup_malloc)(size_t);
    void (*setup_free)(void*);
    struct {
        void *alloc_buffer;
        size_t alloc_buffer_length_in_bytes;
    } alloc;
    size_t setup_offset;
    size_t temp_offset;
    int first_decode;
    int first_audio_page_offset;
    int codebook_count;
    Codebook *codebooks;
    int floor_count;
    uint8_t *floor_types;
    Floor *floor_config;
    int residue_count;
    uint8_t *residue_types;
    Residue *residue_config;
    int mapping_count;
    Mapping *mapping;
    int mode_count;
    Mode *mode_config;
    float **channel_buffers;
    float **previous_window;
    int16_t **finalY;
#ifdef STB_VORBIS_NO_DEFER_FLOOR
    float **floor_buffers;
#endif
    uint16_t blocksize[2];
    int previous_length;
    int bytes_in_seg;
    size_t temp_memory_required;
};

typedef float codetype;
typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef int16_t int16;

#define CHECK(f) do { if ((f)->error) return FALSE; } while (0)

static int point_compare(const void *p1, const void *p2) {
    const stbv__floor_ordering *a = (const stbv__floor_ordering *)p1;
    const stbv__floor_ordering *b = (const stbv__floor_ordering *)p2;
    return a->x < b->x ? -1 : a->x > b->x;
}

static void neighbors(uint16 *list, int n, int *low, int *high) {
    int i;
    *low = *high = 0;
    for (i=1; i < n; ++i) {
        if (list[i] < list[n]) {
            if (*low == 0 || list[i] > list[*low]) *low = i;
        } else {
            if (*high == 0 || list[i] < list[*high]) *high = i;
        }
    }
}