#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHANNELS 64
#define SFM_READ 0x10
#define SFM_WRITE 0x20
#define SF_FORMAT_SUBMASK 0xFFFF
#define SF_FORMAT_FLOAT 0x0006
#define SF_FORMAT_DOUBLE 0x0007
#define SF_FORMAT_VORBIS 0x0060

typedef struct {
    void *infile;
    void *outfile[MAX_CHANNELS];
    int channels;
} STATE;

typedef struct {
    int frames;
    int samplerate;
    int channels;
    int format;
    int sections;
    int seekable;
} SF_INFO;

void *sf_open(const char *path, int mode, SF_INFO *sfinfo);
const char *sf_strerror(void *unused);
int sf_close(void *file);
void usage_exit(void);
void deinterleave_double(STATE *state);
void deinterleave_int(STATE *state);