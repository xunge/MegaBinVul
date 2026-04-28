#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char ckID[4];
    uint32_t ckSize;
} ChunkHeader;

typedef struct {
    char formType[4];
} RiffChunkHeader;

typedef struct {
    uint16_t FormatTag;
    uint16_t NumChannels;
    uint32_t SampleRate;
    uint32_t BytesPerSecond;
    uint16_t BlockAlign;
    uint16_t BitsPerSample;
    uint16_t cbSize;
    uint16_t ValidBitsPerSample;
    uint32_t ChannelMask;
    uint16_t SubFormat;
} WaveHeader;

typedef struct {
    uint64_t riffSize64;
    uint64_t dataSize64;
    uint64_t sampleCount64;
    uint32_t tableLength;
} DS64Chunk;

typedef struct {
    char chunkId[4];
    uint64_t chunkSize;
} CS64Chunk;

typedef struct {
    int qmode;
    int bits_per_sample;
    int channel_mask;
    int float_norm_exp;
    int bytes_per_sample;
    int num_channels;
    int sample_rate;
} WavpackConfig;

typedef struct WavpackContext WavpackContext;

#define QMODE_IGNORE_LENGTH 0x1
#define QMODE_NO_STORE_WRAPPER 0x2
#define QMODE_CHANS_UNASSIGNED 0x4
#define QMODE_ADOBE_MODE 0x8

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1

#define MAX_WAVPACK_SAMPLES (1LL << 36)

#define CLEAR(dest) memset(&(dest), 0, sizeof(dest))

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, size_t size, uint32_t *bcount);
extern int64_t DoGetFilePosition(FILE *infile);
extern void WavpackLittleEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, const char *error);
extern void error_line(const char *format, ...);

extern int debug_logging_mode;

static const char ChunkHeaderFormat[] = "4L";
static const char DS64ChunkFormat[] = "3Q1L";
static const char WaveHeaderFormat[] = "2S3L2S2S2S1L1S";