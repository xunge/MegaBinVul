#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>

#define BLOSC_MEMCPYED 0x80
#define BLOSC_BLOSCLZ 0
#define BLOSC_LZ4 1
#define BLOSC_LZ4HC 2
#define BLOSC_LIZARD 3
#define BLOSC_SNAPPY 4
#define BLOSC_ZLIB 5
#define BLOSC_ZSTD 6

typedef struct blosc2_context {
    int header_flags;
    int use_dict;
    void* dict_cdict;
    int typesize;
    int clevel;
    int compcode;
    uint8_t* filters;
    void* prefilter;
} blosc2_context;

typedef struct thread_context {
    blosc2_context* parent_context;
    uint8_t* tmp4;
    void* lz4_hash_table;
} thread_context;

static int last_filter(uint8_t* filters, char type);
static const uint8_t* pipeline_c(thread_context* thread_context, int32_t bsize,
                               const uint8_t* src, int32_t offset, uint8_t* dest,
                               uint8_t* tmp, uint8_t* tmp3);
static int get_accel(blosc2_context* context);
static bool get_run(const uint8_t* ip, const uint8_t* ipbound);
static void _sw32(uint8_t* dest, int32_t value);
static void blosc_compcode_to_compname(int compcode, const char** compname);
static int blosclz_compress(int clevel, const uint8_t* src, int src_len, uint8_t* dest, int dest_len);
static int lz4_wrap_compress(char* src, size_t src_len, char* dest, size_t dest_len, int accel, void* hash_table);
static int lz4hc_wrap_compress(char* src, size_t src_len, char* dest, size_t dest_len, int clevel);
static int lizard_wrap_compress(char* src, size_t src_len, char* dest, size_t dest_len, int accel);
static int snappy_wrap_compress(char* src, size_t src_len, char* dest, size_t dest_len);
static size_t snappy_max_compressed_length(size_t src_len);
static int zlib_wrap_compress(char* src, size_t src_len, char* dest, size_t dest_len, int clevel);
static int zstd_wrap_compress(thread_context* thread_context, char* src, size_t src_len,
                             char* dest, size_t dest_len, int clevel);