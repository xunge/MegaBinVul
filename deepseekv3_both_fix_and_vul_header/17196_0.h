#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    char ckID[4];
    int64_t ckDataSize;
    char formType[4];
} DFFFileHeader;

typedef struct {
    char ckID[4];
    int64_t ckDataSize;
} DFFChunkHeader;

typedef struct WavpackConfig {
    int qmode;
    uint32_t channel_mask;
    int bits_per_sample;
    int bytes_per_sample;
    int num_channels;
    uint32_t sample_rate;
} WavpackConfig;

typedef struct WavpackContext WavpackContext;

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, char *buffer, uint32_t count, uint32_t *bcount);
extern void WavpackBigEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern const char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, void *null);
extern void error_line(const char *format, ...);

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define QMODE_NO_STORE_WRAPPER 0x40
#define QMODE_IGNORE_LENGTH 0x80
#define QMODE_CHANS_UNASSIGNED 0x100
#define QMODE_DSD_MSB_FIRST 0x200

static const char *DFFFileHeaderFormat = "4L4";
static const char *DFFChunkHeaderFormat = "4L";
static int debug_logging_mode = 0;