#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct WavpackContext WavpackContext;

typedef struct {
    char ckID[4];
    uint32_t ckSize;
} ChunkHeader;

typedef struct {
    char ckID[4];
    char formType[4];
    uint32_t ckSize;
} RiffChunkHeader;

typedef struct {
    uint64_t riffSize64;
    uint64_t dataSize64;
    uint64_t sampleCount64;
    uint32_t tableLength;
} DS64Chunk;

typedef struct {
    char ckID[4];
    uint64_t chunkSize64;
} CS64Chunk;

typedef struct {
    char ckID[4];
    uint32_t ckSize;
    uint8_t junkData[28];
} JunkChunk;

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
    uint8_t GUID[16];
} WaveHeader;

#define FALSE 0
#define TRUE 1
#define CLEAR(x) memset(&(x), 0, sizeof(x))

static const char *ChunkHeaderFormat = "4L";
static const char *DS64ChunkFormat = "3L1L";
static const char *CS64ChunkFormat = "4L1L";
static const char *WaveHeaderFormat = "2S1L2S2S2S2S2S1L2S16C";

extern int debug_logging_mode;
extern void error_line(const char *message, ...);
extern int WavpackGetNumChannels(WavpackContext *wpc);
extern int32_t WavpackGetChannelMask(WavpackContext *wpc);
extern int32_t WavpackGetSampleRate(WavpackContext *wpc);
extern int WavpackGetBytesPerSample(WavpackContext *wpc);
extern int WavpackGetBitsPerSample(WavpackContext *wpc);
extern int WavpackGetFloatNormExp(WavpackContext *wpc);
extern void WavpackNativeToLittleEndian(void *data, const char *format);
extern int DoWriteFile(FILE *outfile, void *data, size_t size, uint32_t *bcount);