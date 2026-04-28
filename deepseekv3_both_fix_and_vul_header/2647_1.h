#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int format;
    int channels;
} SF_INFO;

typedef void SNDFILE;

typedef struct {
    int has_bext_fields;
} METADATA_INFO;

#define SFM_READ 0
#define SFM_WRITE 1
#define SFM_RDWR 2
#define SF_FORMAT_WAV 0x010000
#define SF_FORMAT_SUBMASK 0x0000FF
#define SF_FORMAT_DOUBLE 0x0002
#define SF_FORMAT_FLOAT 0x0001
#define SF_FALSE 0

SNDFILE* sf_open(const char* path, int mode, SF_INFO* sfinfo);
const char* sf_strerror(SNDFILE* sndfile);
int sf_close(SNDFILE* sndfile);

int merge_broadcast_info(SNDFILE *infile, SNDFILE *outfile, int format, const METADATA_INFO *info);
int sfe_copy_data_fp(SNDFILE *outfile, SNDFILE *infile, int channels, int normalize);
void sfe_copy_data_int(SNDFILE *outfile, SNDFILE *infile, int channels);
void update_strings(SNDFILE *outfile, const METADATA_INFO *info);