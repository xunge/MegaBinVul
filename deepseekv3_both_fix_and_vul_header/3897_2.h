#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <limits.h>
#include <inttypes.h>

#define HAVE_DECL_OPTARG 0
#define FALSE 0
#define TRUE 1
#define MAX_SECTIONS 10
#define MAX_IMAGES 100
#define TIFF_DIR_MAX 100000
#define PATH_MAX 4096
#define NUM_BUFF_OVERSIZE_BYTES 16
#define PAGE_MODE_NONE 0
#define DUMP_NONE 0
#define DUMP_TEXT 1
#define DUMP_RAW 2
#define EXIT_FAILURE 1

typedef struct TIFF TIFF;
typedef struct TIFFOpenOptions TIFFOpenOptions;
typedef int tdir_t;

extern int optind;
extern int pageNum;
extern int little_endian;
extern int maxMalloc;
extern uint16_t config;
extern uint16_t compression;
extern uint16_t predictor;
extern uint16_t fillorder;
extern uint32_t rowsperstrip;
extern uint32_t tilewidth;
extern uint32_t tilelength;
extern uint32_t g3opts;
extern uint16_t defcompression;
extern uint16_t defpredictor;
extern uint32_t defg3opts;

struct image_data {
    int adjustments;
};

struct crop_mask {
    int selections;
    int exp_mode;
    uint32_t combined_width;
    uint32_t combined_length;
};

struct pagedef {
    int mode;
};

struct pageseg {
};

struct buffinfo {
    unsigned char *buffer;
};

struct dump_opts {
    int format;
    char infilename[PATH_MAX];
    char outfilename[PATH_MAX];
    FILE *infile;
    FILE *outfile;
    char *mode;
    int debug;
};

void TIFFError(const char*, const char*, ...);
char* TIFFFileName(TIFF*);
void _TIFFfree(void*);
TIFF* TIFFOpenExt(const char*, const char*, TIFFOpenOptions*);
TIFFOpenOptions* TIFFOpenOptionsAlloc(void);
void TIFFOpenOptionsFree(TIFFOpenOptions*);
void TIFFOpenOptionsSetMaxSingleMemAlloc(TIFFOpenOptions*, int);
int TIFFClose(TIFF*);
int TIFFNumberOfDirectories(TIFF*);
int TIFFSetDirectory(TIFF*, tdir_t);

void initImageData(struct image_data *);
void initCropMasks(struct crop_mask *);
void initPageSetup(struct pagedef *, struct pageseg *, struct buffinfo *);
void initDumpOptions(struct dump_opts *);
void process_command_opts(int, char *[], char *, char *, uint32_t *, uint16_t *, uint16_t *, uint32_t *, uint32_t *, uint32_t *, struct crop_mask *, struct pagedef *, struct dump_opts *, unsigned int *, unsigned int *);
void usage(int);
int loadImage(TIFF *, struct image_data *, struct dump_opts *, unsigned char **);
int correct_orientation(struct image_data *, unsigned char **);
int getCropOffsets(struct image_data *, struct crop_mask *, struct dump_opts *);
int processCropSelections(struct image_data *, struct crop_mask *, unsigned char **, struct buffinfo *);
int createCroppedImage(struct image_data *, struct crop_mask *, unsigned char **, unsigned char **);
int writeSelections(TIFF *, TIFF **, struct crop_mask *, struct image_data *, struct dump_opts *, struct buffinfo *, char *, char *, unsigned int *, unsigned int);
int update_output_file(TIFF **, char *, int, char *, unsigned int *);
int writeCroppedImage(TIFF *, TIFF *, struct image_data *, struct dump_opts *, uint32_t, uint32_t, unsigned char *, unsigned int, unsigned int);
int computeOutputPixelOffsets(struct crop_mask *, struct image_data *, struct pagedef *, struct pageseg *, struct dump_opts *);
int writeImageSections(TIFF *, TIFF *, struct image_data *, struct pagedef *, struct pageseg *, struct dump_opts *, unsigned char *, unsigned char **);
void dump_info(FILE *, int, const char *, const char *, ...);