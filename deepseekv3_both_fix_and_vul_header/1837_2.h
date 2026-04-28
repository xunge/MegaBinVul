#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <inttypes.h>

#define HAVE_DECL_OPTARG 0
#define MAX_SECTIONS 10
#define MAX_IMAGES 100
#define TIFF_DIR_MAX 65535
#define PATH_MAX 4096
#define FALSE 0
#define TRUE 1
#define EXIT_FAILURE 1
#define EXIT_SUCCESS 0
#define PAGE_MODE_NONE 0
#define DUMP_NONE 0
#define DUMP_TEXT 1
#define DUMP_RAW 2

typedef struct TIFF TIFF;
typedef uint16_t tdir_t;

extern int optind;
extern char *optarg;

struct image_data {
    int adjustments;
};

struct crop_mask {
    int selections;
    int exp_mode;
    int combined_width;
    int combined_length;
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
    int debug;
    char infilename[PATH_MAX];
    char outfilename[PATH_MAX];
    FILE *infile;
    FILE *outfile;
    char *mode;
};

int little_endian;
int pageNum;
int config;
int compression;
int predictor;
int fillorder;
int rowsperstrip;
int tilewidth;
int tilelength;
int g3opts;
int defcompression;
int defpredictor;
int defg3opts;

void _TIFFfree(void *ptr);
TIFF* TIFFOpen(const char* filename, const char* mode);
int TIFFClose(TIFF* tif);
int TIFFNumberOfDirectories(TIFF* tif);
int TIFFSetDirectory(TIFF* tif, tdir_t dirnum);
const char* TIFFFileName(TIFF* tif);
void TIFFError(const char* module, const char* fmt, ...);

void initImageData(struct image_data *);
void initCropMasks(struct crop_mask *);
void initPageSetup(struct pagedef *, struct pageseg *, struct buffinfo *);
void initDumpOptions(struct dump_opts *);
void process_command_opts(int, char **, char *, char *, uint32_t *, uint16_t *, uint16_t *, uint32_t *, uint32_t *, uint32_t *, struct crop_mask *, struct pagedef *, struct dump_opts *, unsigned int *, unsigned int *);
void usage(int);
int loadImage(TIFF *, struct image_data *, struct dump_opts *, unsigned char **);
int correct_orientation(struct image_data *, unsigned char **);
int getCropOffsets(struct image_data *, struct crop_mask *, struct dump_opts *);
int processCropSelections(struct image_data *, struct crop_mask *, unsigned char **, struct buffinfo *);
int createCroppedImage(struct image_data *, struct crop_mask *, unsigned char **, unsigned char **);
void writeSelections(TIFF *, TIFF **, struct crop_mask *, struct image_data *, struct dump_opts *, struct buffinfo *, char *, char *, unsigned int *, unsigned int);
int update_output_file(TIFF **, char *, int, char *, unsigned int *);
int writeCroppedImage(TIFF *, TIFF *, struct image_data *, struct dump_opts *, int, int, unsigned char *, unsigned int, unsigned int);
int computeOutputPixelOffsets(struct crop_mask *, struct image_data *, struct pagedef *, struct pageseg *, struct dump_opts *);
int writeImageSections(TIFF *, TIFF *, struct image_data *, struct pagedef *, struct pageseg *, struct dump_opts *, unsigned char *, unsigned char **);
void dump_info(FILE *, int, const char *, const char *, ...);