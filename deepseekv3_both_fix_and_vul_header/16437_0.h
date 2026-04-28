#include <stdint.h>
#include <stdlib.h>

#define TRUE 1
#define MONO_FLAG 0x1
#define DSD_FLAG 0x80000000
#define CONFIG_HIGH_FLAG 0x0001
#define CONFIG_MERGE_BLOCKS 0x0002

typedef struct {
    int flags;
    int sample_rate;
    int num_channels;
    int block_samples;
} WavpackConfig;

typedef struct {
    uint32_t flags;
} WavpackHeader;

typedef struct WavpackStream {
    WavpackHeader wphdr;
    void *sample_buffer;
} WavpackStream;

typedef struct WavpackContext {
    int metabytes;
    int dsd_multiplier;
    int block_samples;
    int ave_block_samples;
    int max_samples;
    int current_stream;
    int num_streams;
    uint32_t block_boundary;
    WavpackConfig config;
    WavpackStream **streams;
} WavpackContext;

void write_metadata_block(WavpackContext *wpc);
void pack_init(WavpackContext *wpc);
void pack_dsd_init(WavpackContext *wpc);