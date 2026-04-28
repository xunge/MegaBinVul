#include <stdio.h>
#include <string.h>
#include <stdint.h>
#include <stdlib.h>

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

typedef struct WavpackConfig {
    int qmode;
    int bits_per_sample;
    uint32_t channel_mask;
    int float_norm_exp;
    int bytes_per_sample;
    int num_channels;
    uint32_t sample_rate;
} WavpackConfig;

typedef struct WavpackContext WavpackContext;

#define TRUE 1
#define FALSE 0
#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define MAX_WAVPACK_SAMPLES 0x7fffffff
#define QMODE_IGNORE_LENGTH 0x40
#define QMODE_NO_STORE_WRAPPER 0x80
#define QMODE_CHANS_UNASSIGNED 0x100
#define QMODE_ADOBE_MODE 0x200

extern int debug_logging_mode;
extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, size_t size, uint32_t *bcount);
extern int64_t DoGetFilePosition(FILE *infile);
extern void WavpackLittleEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, const char *error);
extern void error_line(const char *format, ...);

#define CLEAR(dest) memset(&dest, 0, sizeof(dest))
#define ChunkHeaderFormat "4L"
#define DS64ChunkFormat "3L1L"
#define WaveHeaderFormat "2S1L1L2S2S2S2S1L2S"