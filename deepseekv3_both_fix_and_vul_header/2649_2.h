#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SF_INFO {
    int frames;
    int samplerate;
    int channels;
    int format;
    int sections;
    int seekable;
} SF_INFO;

typedef struct SNDFILE {} SNDFILE;

#define SF_FORMAT_PCM_S8 0x0001
#define SF_FORMAT_PCM_U8 0x0002
#define SF_FORMAT_PCM_16 0x0003
#define SF_FORMAT_PCM_24 0x0004
#define SF_FORMAT_PCM_32 0x0005
#define SF_FORMAT_FLOAT 0x0006
#define SF_FORMAT_DOUBLE 0x0007
#define SF_FORMAT_ULAW 0x0010
#define SF_FORMAT_ALAW 0x0011
#define SF_FORMAT_IMA_ADPCM 0x0012
#define SF_FORMAT_MS_ADPCM 0x0013
#define SF_FORMAT_GSM610 0x0020
#define SF_FORMAT_DWVW_12 0x0040
#define SF_FORMAT_DWVW_16 0x0041
#define SF_FORMAT_DWVW_24 0x0042
#define SF_FORMAT_VORBIS 0x0060
#define SF_FORMAT_OPUS 0x0064
#define SF_FORMAT_ALAC_16 0x0070
#define SF_FORMAT_ALAC_20 0x0071
#define SF_FORMAT_ALAC_24 0x0072
#define SF_FORMAT_ALAC_32 0x0073
#define SF_FORMAT_DPCM_8 0x0080
#define SF_FORMAT_DPCM_16 0x0081
#define SF_FORMAT_XI 0x00A0
#define SF_FORMAT_SUBMASK 0x0000FFFF
#define SF_FORMAT_TYPEMASK 0x0FFF0000
#define SF_FORMAT_ENDMASK 0x30000000
#define SF_ENDIAN_FILE 0x00000000
#define SF_ENDIAN_LITTLE 0x10000000
#define SF_ENDIAN_BIG 0x20000000
#define SF_ENDIAN_CPU 0x30000000
#define SFM_READ 0x10
#define SFM_WRITE 0x20
#define SF_FALSE 0
#define SF_TRUE 1

extern const char *program_name(const char *argv0);
extern void usage_exit(const char *progname);
extern int sfe_file_type_of_ext(const char *outfilename, int format);
extern void report_format_error_exit(const char *progname, const SF_INFO *sfinfo);
extern void copy_metadata(SNDFILE *outfile, SNDFILE *infile, int channels);
extern int sfe_copy_data_fp(SNDFILE *outfile, SNDFILE *infile, int channels, int normalize);
extern int sfe_copy_data_int(SNDFILE *outfile, SNDFILE *infile, int channels);
extern SNDFILE *sf_open(const char *path, int mode, SF_INFO *sfinfo);
extern int sf_close(SNDFILE *sndfile);
extern const char *sf_strerror(SNDFILE *sndfile);
extern int sf_format_check(const SF_INFO *info);