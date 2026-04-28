#include <stdio.h>

struct mp4frame {
    int nsamples;
    struct {
        int offset;
    } info[1];
};

struct mp4asc {
    int size;
};

struct {
    int mtime;
    int samplerate;
    int samples;
    int channels;
    int bits;
    int buffersize;
    int bitratemax;
    int bitrateavg;
    struct mp4frame frame;
    struct mp4asc asc;
} mp4config;

char *mp4time(int t);