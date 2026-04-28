#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <math.h>

#define TRUE 1
#define FALSE 0

typedef struct {
    char mChunkType[4];
    int64_t mChunkSize;
} CAFChunkHeader;

typedef struct {
    char mFileType[4];
    uint16_t mFileVersion;
    uint16_t mFileFlags;
} CAFFileHeader;

typedef struct {
    char mFormatID[4];
    uint32_t mFormatFlags;
    double mSampleRate;
    uint32_t mBytesPerPacket;
    uint32_t mFramesPerPacket;
    uint32_t mChannelsPerFrame;
    uint32_t mBitsPerChannel;
} CAFAudioFormat;

typedef struct {
    uint32_t mChannelLayoutTag;
    uint32_t mChannelBitmap;
    uint32_t mNumberChannelDescriptions;
} CAFChannelLayout;

typedef struct {
    uint32_t mChannelLabel;
    uint32_t mChannelFlags;
    float mCoordinates[3];
} CAFChannelDescription;

typedef struct {
    uint32_t mChannelLayoutTag;
    uint32_t mChannelBitmap;
    const char *mChannelReorder;
    const char *mChannelIdentities;
} CAFLayoutInfo;

#define NUM_LAYOUTS 0
static const CAFLayoutInfo layouts[NUM_LAYOUTS];

#define CAF_FORMAT_FLOAT 1
#define CAF_FORMAT_LITTLE_ENDIAN 2

#define kCAFChannelLayoutTag_UseChannelDescriptions 0
#define kCAFChannelLayoutTag_UseChannelBitmap 0x10000

#define WAVPACK_NO_ERROR 0
#define WAVPACK_SOFT_ERROR 1
#define MAX_WAVPACK_SAMPLES 0x7fffffff

#define QMODE_NO_STORE_WRAPPER 0x1
#define QMODE_BIG_ENDIAN 0x2
#define QMODE_SIGNED_BYTES 0x4
#define QMODE_CHANS_UNASSIGNED 0x8
#define QMODE_REORDERED_CHANS 0x10
#define QMODE_IGNORE_LENGTH 0x20

typedef struct WavpackConfig {
    int qmode;
    int bytes_per_sample;
    int float_norm_exp;
    int bits_per_sample;
    int num_channels;
    int sample_rate;
    uint32_t channel_mask;
} WavpackConfig;

typedef struct WavpackContext WavpackContext;

extern int64_t DoGetFileSize(FILE *infile);
extern int DoReadFile(FILE *infile, void *buffer, uint32_t size, uint32_t *bcount);
extern int64_t DoGetFilePosition(FILE *infile);
extern void WavpackBigEndianToNative(void *data, const char *format);
extern int WavpackAddWrapper(WavpackContext *wpc, void *data, uint32_t size);
extern char *WavpackGetErrorMessage(WavpackContext *wpc);
extern int WavpackSetConfiguration64(WavpackContext *wpc, WavpackConfig *config, int64_t total_samples, unsigned char *channel_identities);
extern int WavpackSetChannelLayout(WavpackContext *wpc, uint32_t channel_layout, unsigned char *channel_reorder);
extern void error_line(const char *format, ...);

static const char *CAFFileHeaderFormat = "4SS";
static const char *CAFChunkHeaderFormat = "4Q";
static const char *CAFAudioFormatFormat = "4LDL4L";
static const char *CAFChannelLayoutFormat = "3L";
static const char *CAFChannelDescriptionFormat = "2L3f";

extern int debug_logging_mode;