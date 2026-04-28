#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define MAX_PERCENTS 32
#define MAX_CHANNELS 8
#define FAAD_MIN_STREAMSIZE 768
#define ADTS 1

typedef struct aac_buffer {
    unsigned char *buffer;
    int bytes_into_buffer;
    int bytes_consumed;
    int file_offset;
    int at_eof;
    FILE *infile;
} aac_buffer;

typedef struct NeAACDecFrameInfo {
    int bytesconsumed;
    int channels;
    int samplerate;
    int samples;
    int error;
    int header_type;
} NeAACDecFrameInfo;

typedef struct NeAACDecConfiguration {
    unsigned long defSampleRate;
    unsigned char defObjectType;
    unsigned char outputFormat;
    unsigned char downMatrix;
    unsigned char useOldADTSFormat;
} NeAACDecConfiguration;

typedef void* NeAACDecHandle;
typedef NeAACDecConfiguration* NeAACDecConfigurationPtr;

typedef struct audio_file {
    int channels;
} audio_file;

static const int adts_sample_rates[] = {
    96000, 88200, 64000, 48000, 44100, 32000,
    24000, 22050, 16000, 12000, 11025, 8000
};

static FILE* faad_fopen(const char *filename, const char *mode);
static int faad_fprintf(FILE *stream, const char *format, ...);
static void advance_buffer(aac_buffer *b, int bytes);
static void fill_buffer(aac_buffer *b);
static void lookforheader(aac_buffer *b);
static void adts_parse(aac_buffer *b, int *bitrate, float *length);
static unsigned char* MakeAdtsHeader(int *adtsDataSize, NeAACDecFrameInfo *frameInfo, int old_format);
static void print_channel_info(NeAACDecFrameInfo *frameInfo);
static audio_file* open_audio_file(const char *filename, int samplerate, int channels, int outputFormat, int fileType, int mask);
static int write_audio_file(audio_file *aufile, void *sample_buffer, int samples, int flush);
static void close_audio_file(audio_file *aufile);
static int aacChannelConfig2wavexChannelMask(NeAACDecFrameInfo *frameInfo);
static const char* NeAACDecGetErrorMessage(int err);
static NeAACDecHandle NeAACDecOpen(void);
static NeAACDecConfigurationPtr NeAACDecGetCurrentConfiguration(NeAACDecHandle hDecoder);
static void NeAACDecSetConfiguration(NeAACDecHandle hDecoder, NeAACDecConfigurationPtr config);
static int NeAACDecInit(NeAACDecHandle hDecoder, unsigned char *buffer,
                       unsigned long buffer_size, unsigned long *samplerate,
                       unsigned char *channels);
static void* NeAACDecDecode(NeAACDecHandle hDecoder, NeAACDecFrameInfo *hInfo,
                           unsigned char *buffer, unsigned long buffer_size);
static void NeAACDecClose(NeAACDecHandle hDecoder);