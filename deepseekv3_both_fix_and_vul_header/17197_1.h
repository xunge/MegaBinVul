#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define TRUE 1
#define FALSE 0
#define MAX_WAVPACK_SAMPLES (1LL << 36)

#define QMODE_NO_STORE_WRAPPER 0x1
#define QMODE_IGNORE_LENGTH 0x2
#define QMODE_ADOBE_MODE 0x4
#define QMODE_CHANS_UNASSIGNED 0x8

typedef struct {
    char ckID[16];
    char formType[16];
    uint64_t ckSize;
} Wave64FileHeader;

typedef struct {
    char ckID[16];
    uint64_t ckSize;
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

typedef struct WavpackConfig {
    uint32_t qmode;
    uint32_t bits_per_sample;
    uint32_t bytes_per_sample;
    uint32_t num_channels;
    uint32_t sample_rate;
    uint32_t channel_mask;
    int float_norm_exp;
} WavpackConfig;

extern char riff_guid[16];
extern char wave_guid[16];
extern char fmt_guid[16];
extern char data_guid[16];
extern char Wave64ChunkHeaderFormat[];
extern char WaveHeaderFormat[];
extern int debug_logging_mode;

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, uint32_t size, uint32_t *bcount);
extern int64_t DoGetFilePosition(FILE *infile);
extern void error_line(const char *format, ...);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern void WavpackLittleEndianToNative(void *data, const char *format);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, const char *error);