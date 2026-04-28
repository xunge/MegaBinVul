#include <stdio.h>
#include <stdlib.h>

#define MP3_FRAME_SYNC 0xFFE00000
#define MP3_BITRATE 0x0000F000
#define MP3_BITRATE_SHIFT 12
#define MP3_SAMPLERATE 0x00000C00
#define MP3_SAMPLERATE_SHIFT 10
#define MP3_SAMPLERATE_IDX_MAX 2
#define MP3_CHANNEL 0x000000C0
#define MP3_CHANNEL_MONO 0x000000C0
#define MP3_VERSION 0x00180000
#define MP3_VERSION_1 0x00180000
#define MP3_VERSION_2 0x00100000
#define MP3_VERSION_25 0x00080000
#define MP3_LAYER 0x00060000
#define MP3_LAYER_1 0x00060000
#define MP3_LAYER_2 0x00040000
#define MP3_LAYER_3 0x00020000
#define MP3_PADDING 0x00000200
#define MP3_PROTECT 0x00010000

static const int mp1_samplerate_table[] = {44100, 48000, 32000};
static const int mp2_samplerate_table[] = {22050, 24000, 16000};
static const int mp25_samplerate_table[] = {11025, 12000, 8000};
static const int mp1l1_bitrate_table[] = {0,32,64,96,128,160,192,224,256,288,320,352,384,416,448};
static const int mp1l2_bitrate_table[] = {0,32,48,56,64,80,96,112,128,160,192,224,256,320,384};
static const int mp1l3_bitrate_table[] = {0,32,40,48,56,64,80,96,112,128,160,192,224,256,320};
static const int mp2l1_bitrate_table[] = {0,32,48,56,64,80,96,112,128,144,160,176,192,224,256};
static const int mp2l23_bitrate_table[] = {0,8,16,24,32,40,48,56,64,80,96,112,128,144,160};

void error(const char *msg);
void skipBytes(FILE *f, int bytes);