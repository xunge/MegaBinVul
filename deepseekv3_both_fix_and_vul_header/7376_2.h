#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char ckID[4];
    uint64_t ckDataSize;
    char formType[4];
} DFFFileHeader;

typedef struct {
    char ckID[4];
    uint64_t ckDataSize;
} DFFChunkHeader;

struct WavpackConfig {
    uint32_t qmode;
    uint32_t channel_mask;
    int bits_per_sample;
    int bytes_per_sample;
    int num_channels;
    uint32_t sample_rate;
};

typedef struct WavpackContext WavpackContext;
typedef struct WavpackConfig WavpackConfig;

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define QMODE_NO_STORE_WRAPPER 0x1
#define QMODE_IGNORE_LENGTH 0x2
#define QMODE_CHANS_UNASSIGNED 0x4
#define QMODE_DSD_MSB_FIRST 0x8
#define MAX_WAVPACK_SAMPLES 0x7FFFFFFFFFFFFFFFLL

static const char DFFFileHeaderFormat[] = "4D4";
static const char DFFChunkHeaderFormat[] = "4D";

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, uint32_t count, uint32_t *bcount);
extern void WavpackBigEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern const char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, void *null);
extern void error_line(const char *format, ...);

extern int debug_logging_mode;