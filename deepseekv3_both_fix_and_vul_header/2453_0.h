#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_PAYLOAD_SIZE 1024
#define AACENC_BLOCKSIZE 1024
#define MAX_CHANNELS 2
#define INPUT_DELAY 1024
#define CORE_INPUT_OFFSET_PS 1024
#define MAX_DS_FILTER_DELAY 64
#define AACENC_TRANS_FAC 8
#define ADTS_HEADER_SIZE 7

typedef struct {
    int nChannels;
    unsigned int sampleRate;
    int nSamples;
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

typedef void* HANDLE_SBR_ENCODER;
typedef void* AAC_ENCODER;

extern IIR21_RESAMPLER IIR21_reSampler[2];
extern float inputBuffer[];
extern float sbr_envRBuffer[];
extern unsigned char outputBuffer[];
extern int bEncodeMono;