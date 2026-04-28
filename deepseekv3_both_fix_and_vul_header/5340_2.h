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

typedef struct WavpackContext WavpackContext;

typedef struct {
    uint32_t sample_rate;
    int num_channels;
    int bits_per_sample;
    int bytes_per_sample;
    uint32_t channel_mask;
    int qmode;
} WavpackConfig;

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define QMODE_NO_STORE_WRAPPER 0x40
#define QMODE_IGNORE_LENGTH 0x80
#define QMODE_CHANS_UNASSIGNED 0x100
#define QMODE_DSD_MSB_FIRST 0x200

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, uint32_t count, uint32_t *bcount);
extern void error_line(const char *format, ...);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t bcount);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern void WavpackBigEndianToNative(void *data, const char *format);
extern int WavpackSetConfiguration64(WavpackContext *wpc, struct WavpackConfig *config, int64_t total_samples, void *unknown);

static int debug_logging_mode = 0;
static const char DFFFileHeaderFormat[] = "A4L4A4";
static const char DFFChunkHeaderFormat[] = "A4L4";