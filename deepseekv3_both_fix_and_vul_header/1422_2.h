#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <inttypes.h>

typedef struct TIFF TIFF;
typedef int32_t tmsize_t;

#define EXIT_SUCCESS 0
#define EXIT_FAILURE 1
#define TRUE 1
#define FALSE 0

#define FILLORDER_LSB2MSB 1
#define FILLORDER_MSB2LSB 2
#define PLANARCONFIG_SEPARATE 1
#define PLANARCONFIG_CONTIG 2
#define TIFFTAG_SAMPLESPERPIXEL 277

extern int optind;
extern char* optarg;

extern tmsize_t maxMalloc;
extern char comma;
extern TIFF* bias;
extern int ignore;
extern int outtiled;
extern int pageInSeq;
extern int pageNum;
extern uint16_t config;
extern uint16_t compression;
extern uint16_t predictor;
extern int preset;
extern uint16_t fillorder;
extern uint32_t rowsperstrip;
extern uint32_t tilewidth;
extern uint32_t tilelength;
extern uint32_t g3opts;
extern uint16_t defcompression;
extern uint16_t defpredictor;
extern int defpreset;
extern uint32_t defg3opts;

int streq(const char* a, const char* b);
void usage(int code);
int processCompressOptions(const char* optarg);
TIFF* openSrcImage(char** imageCursor);
int nextSrcImage(TIFF* in, char** imageCursor);
int tiffcp(TIFF* in, TIFF* out);
int TIFFIsTiled(TIFF* tif);
int TIFFGetField(TIFF* tif, int tag, ...);
int TIFFSetSubDirectory(TIFF* tif, uint64_t diroff);
int TIFFReadDirectory(TIFF* tif);
int TIFFWriteDirectory(TIFF* tif);
void TIFFError(const char* module, const char* fmt, ...);
const char* TIFFFileName(TIFF* tif);
int TIFFClose(TIFF* tif);
TIFF* TIFFOpen(const char* name, const char* mode);