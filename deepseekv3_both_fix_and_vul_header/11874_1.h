#include <stdio.h>
#include <string.h>

#define CLASS
#define FORC4 for (int c = 0; c < 4; c++)
#define LIBRAW_WBI_Tungsten 0
#define LIBRAW_WBI_Daylight 1
#define LIBRAW_WBI_Cloudy 2
#define LIBRAW_WBI_FL_W 3
#define LIBRAW_WBI_Flash 4
#define LIBRAW_WBI_Shade 5
#define LIBRAW_WBI_FL_D 6
#define LIBRAW_WBI_FL_N 7
#define LIBRAW_WBI_FL_WW 8

typedef unsigned short ushort;

short order;
FILE *ifp;
char *model;
unsigned short cam_mul[4];
int raw_height, raw_width;
long data_offset;

struct {
    struct {
        struct {
            short prd_ImageHeight;
            short prd_ImageWidth;
            ushort prd_RawBitDepth;
            ushort prd_StorageMethod;
            ushort prd_BayerPattern;
        } sony;
    } makernotes;
    struct {
        float WB_Coeffs[10][4];
    } color;
} imgdata;

int get2();
int get4();
void parse_tiff(long offset);