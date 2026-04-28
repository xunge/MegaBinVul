#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <getopt.h>
#ifdef _WIN32
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#else
#include <unistd.h>
#endif

#define LC 0
#define MAIN 1
#define LTP 2
#define LD 3

#define FAAD_FMT_16BIT 1
#define FAAD2_VERSION "2.7"
#define FIXED_POINT_CAP (1 << 0)

extern unsigned long NeAACDecGetCapabilities(void);
extern void faad_fprintf(FILE *stream, const char *format, ...);
extern void usage(void);
extern int decodeMP4file(char *aacFileName, char *audioFileName, char *adtsFileName, int writeToStdio, int outputFormat, int format, int downMatrix, int noGapless, int infoOnly, int adts_out, float *length);
extern int decodeAACfile(char *aacFileName, char *audioFileName, char *adtsFileName, int writeToStdio, int def_srate, int object_type, int outputFormat, int format, int downMatrix, int infoOnly, int adts_out, int old_format, float *length);

static char *progName;
static int quiet = 0;
static const char *file_ext[] = {".wav", ".aiff"};