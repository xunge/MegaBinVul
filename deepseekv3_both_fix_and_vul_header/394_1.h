#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char ckID[16];
    int64_t ckSize;
    char formType[16];
} Wave64FileHeader;

typedef struct {
    char ckID[16];
    int64_t ckSize;
} Wave64ChunkHeader;

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
    uint32_t SubFormat;
} WaveHeader;

typedef struct WavpackContext WavpackContext;

typedef struct {
    uint32_t qmode;
    uint32_t channel_mask;
    int bits_per_sample;
    int float_norm_exp;
    int bytes_per_sample;
    int num_channels;
    uint32_t sample_rate;
} WavpackConfig;

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define MAX_WAVPACK_SAMPLES 0x7fffffff

#define QMODE_NO_STORE_WRAPPER 0x1
#define QMODE_IGNORE_LENGTH 0x2
#define QMODE_CHANS_UNASSIGNED 0x4
#define QMODE_ADOBE_MODE 0x8

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, uint32_t count, uint32_t *bcount);
extern int64_t DoGetFilePosition(FILE *infile);
extern void error_line(const char *format, ...);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern void WavpackLittleEndianToNative(void *data, char *format);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, const char *error);
extern int debug_logging_mode;

static const char riff_guid[16] = {0x72, 0x69, 0x66, 0x66, 0x2E, 0x91, 0xCF, 0x11, 0xA5, 0xD6, 0x28, 0xDB, 0x04, 0xC1, 0x00, 0x00};
static const char wave_guid[16] = {0x77, 0x61, 0x76, 0x65, 0xF3, 0xAC, 0xD3, 0x11, 0x8C, 0xD1, 0x00, 0xC0, 0x4F, 0x8E, 0xDB, 0x8A};
static const char fmt_guid[16] = {0x66, 0x6D, 0x74, 0x20, 0xF3, 0xAC, 0xD3, 0x11, 0x8C, 0xD1, 0x00, 0xC0, 0x4F, 0x8E, 0xDB, 0x8A};
static const char data_guid[16] = {0x64, 0x61, 0x74, 0x61, 0xF3, 0xAC, 0xD3, 0x11, 0x8C, 0xD1, 0x00, 0xC0, 0x4F, 0x8E, 0xDB, 0x8A};

static char Wave64ChunkHeaderFormat[] = "16c8";
static char WaveHeaderFormat[] = "2224422222";