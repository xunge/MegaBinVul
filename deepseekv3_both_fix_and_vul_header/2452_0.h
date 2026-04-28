#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_PAYLOAD_SIZE 1024
#define AACENC_BLOCKSIZE 1024
#define MAX_CHANNELS 2
#define INPUT_DELAY 1024
#define CORE_INPUT_OFFSET_PS 1024
#define MAX_DS_FILTER_DELAY 1024
#define AACENC_TRANS_FAC 1024
#define ADTS_HEADER_SIZE 7

typedef struct {
    int nChannels;
    unsigned int sampleRate;
    unsigned int nSamples;
} WavInfo;

typedef struct {
    int bitRate;
    int nChannelsIn;
    int nChannelsOut;
    unsigned int sampleRate;
    int bandWidth;
} AACENC_CONFIG;

typedef struct {
    int usePs;
} sbrConfiguration;

typedef struct {
    int delay;
} IIR21_RESAMPLER;

typedef struct AAC_ENCODER AAC_ENCODER;
typedef void* HANDLE_SBR_ENCODER;

extern FILE* AuChannelOpen(const char* filename, WavInfo* info);
extern int AuChannelReadShort(FILE* file, short* buffer, int samples, int* read);
extern void AuChannelClose(FILE* file);
extern void AacInitDefaultConfig(AACENC_CONFIG* config);
extern int AacEncOpen(AAC_ENCODER** enc, AACENC_CONFIG config);
extern int AacEncEncode(AAC_ENCODER* enc, float* input, int stride, unsigned char* ancData, unsigned int* ancDataBytes, unsigned int* output, int* outBytes);
extern void AacEncClose(AAC_ENCODER* enc);
extern int IsSbrSettingAvail(int bitrate, int channels, unsigned int sampleRate, unsigned int* outSampleRate);
extern void InitializeSbrDefaults(sbrConfiguration* config);
extern void AdjustSbrSettings(sbrConfiguration* config, int bitrate, int channels, unsigned int sampleRate, int transFac, int maxBitrate);
extern void EnvOpen(HANDLE_SBR_ENCODER* hEnvEnc, float* inputBuffer, sbrConfiguration* config, int* bandwidth);
extern void EnvEncodeFrame(HANDLE_SBR_ENCODER hEnvEnc, float* inputBuffer, float* coreBuffer, int stride, unsigned int* numAncDataBytes, unsigned char* ancDataBytes);
extern void EnvClose(HANDLE_SBR_ENCODER hEnvEnc);
extern void InitIIR21_Resampler(IIR21_RESAMPLER* resampler);
extern void IIR21_Upsample(IIR21_RESAMPLER* resampler, float* input, int inSamples, int inStride, float* output, int* outSamples, int outStride);
extern void IIR21_Downsample(IIR21_RESAMPLER* resampler, float* input, int inSamples, int inStride, float* output, int* outSamples, int outStride);
extern void IIR32Init();
extern int IIR32GetResamplerFeed(int samples);
extern int IIR32Resample(float* input, float* output, int inSamples, int outSamples, int channels);
extern void adts_hdr(unsigned char* buffer, AACENC_CONFIG* config);
extern void adts_hdr_up(unsigned char* buffer, int size);
extern void init_plans();
extern void destroy_plans();

static IIR21_RESAMPLER IIR21_reSampler[2];
static float inputBuffer[1024 * 1024];
static unsigned char outputBuffer[1024 * 1024];
static float sbr_envRBuffer[1024 * 1024];
static int bEncodeMono = 0;