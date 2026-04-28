#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef struct {
    char ckID[4];
    int64_t ckSize;
    int64_t fileSize;
    int64_t metaOffset;
} DSFFileChunk;

typedef struct {
    char ckID[4];
    int64_t ckSize;
    uint32_t formatVersion;
    uint32_t formatID;
    uint32_t blockSize;
    int64_t sampleCount;
    uint32_t sampleRate;
    uint32_t numChannels;
    uint32_t bitsPerSample;
    uint32_t chanType;
    uint32_t reserved;
} DSFFormatChunk;

typedef struct {
    char ckID[4];
    int64_t ckSize;
} DSFChunkHeader;

typedef struct {
    int qmode;
    uint32_t channel_mask;
    int bits_per_sample;
    int bytes_per_sample;
    int num_channels;
    uint32_t sample_rate;
} WavpackConfig;

typedef struct WavpackContext WavpackContext;

#define DSF_BLOCKSIZE 4096
#define MAX_WAVPACK_SAMPLES 0x7fffffff
#define NUM_CHAN_TYPES 6

#define QMODE_NO_STORE_WRAPPER 0x40
#define QMODE_IGNORE_LENGTH 0x80
#define QMODE_CHANS_UNASSIGNED 0x100
#define QMODE_DSD_LSB_FIRST 0x200
#define QMODE_DSD_MSB_FIRST 0x400
#define QMODE_DSD_IN_BLOCKS 0x800

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1

#define DSFFileChunkFormat "4LL"
#define DSFFormatChunkFormat "4LL4LLLLLL"
#define DSFChunkHeaderFormat "4L"

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, char *buffer, int size, uint32_t *bcount);
extern void WavpackLittleEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, int32_t bcount);
extern const char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, void *unknown);
extern void error_line(const char *format, ...);

extern int debug_logging_mode;
extern uint32_t channel_masks[];