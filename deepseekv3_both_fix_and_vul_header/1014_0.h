#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE 0
#define TRUE 1
#define M_SOI 0xD8
#define M_SOS 0xDA
#define M_DQT 0xDB
#define M_DHT 0xC4
#define M_EOI 0xD9
#define M_COM 0xFE
#define M_JFIF 0xE0
#define M_EXIF 0xE1
#define M_IPTC 0xED
#define M_SOF0 0xC0
#define M_SOF1 0xC1
#define M_SOF2 0xC2
#define M_SOF3 0xC3
#define M_SOF5 0xC5
#define M_SOF6 0xC6
#define M_SOF7 0xC7
#define M_SOF9 0xC9
#define M_SOF10 0xCA
#define M_SOF11 0xCB
#define M_SOF13 0xCD
#define M_SOF14 0xCE
#define M_SOF15 0xCF
#define M_XMP 0x10E1
#define PSEUDO_IMAGE_MARKER 0x1234

typedef unsigned char uchar;

typedef enum {
    READ_METADATA = 1,
    READ_IMAGE = 2
} ReadMode_t;

typedef struct {
    int Present;
    int ResolutionUnits;
    int XDensity;
    int YDensity;
} JfifHeader_t;

typedef struct {
    JfifHeader_t JfifHeader;
} ImageInfo_t;

typedef struct {
    int Type;
    int Size;
    uchar *Data;
} Section_t;

extern ImageInfo_t ImageInfo;
extern Section_t *Sections;
extern int SectionsRead;
extern int HaveAll;
extern int ShowTags;

void ErrFatal(const char *msg);
void ErrNonfatal(const char *fmt, ...);
void CheckSectionsAllocated();
void process_DQT(uchar *Data, int itemlen);
void process_DHT(uchar *Data, int itemlen);
void process_COM(uchar *Data, int itemlen);
void process_EXIF(uchar *Data, int itemlen);
void process_SOFn(uchar *Data, int marker);
void ShowXmp(Section_t section);