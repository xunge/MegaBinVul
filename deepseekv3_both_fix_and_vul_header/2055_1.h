#include <stdio.h>
#include <string.h>

#define FITS_MAX_AXIS 999
#define FITS_RECORD_SIZE 2880

enum FITS_DATA_TYPE {
    typ_fstring,
    typ_flong,
    typ_fbool,
    typ_fdouble
};

typedef struct FITS_RECORD_LIST {
    char data[80];
} FITS_RECORD_LIST;

typedef struct FITS_DATA {
    enum FITS_DATA_TYPE type;
    char fstring[80];
    long flong;
    int fbool;
    double fdouble;
} FITS_DATA;

typedef struct {
    int simple;
    int xtension;
    int gcount;
    int pcount;
    int groups;
    int extend;
    int blank;
    int datamin;
    int datamax;
    int bzero;
    int bscale;
} FITS_HDU_USED;

typedef struct FITS_HDU_LIST {
    long header_offset;
    long data_offset;
    FITS_HDU_USED used;
    char xtension[80];
    int naxis;
    int bitpix;
    int bpp;
    long gcount;
    long pcount;
    int groups;
    int extend;
    int naxisn[FITS_MAX_AXIS];
    long udata_size;
    long data_size;
    long blank;
    double datamin;
    double datamax;
    double bzero;
    double bscale;
    int numpic;
    FITS_RECORD_LIST *header_record_list;
} FITS_HDU_LIST;

extern int fits_ieee64_intel;
extern int fits_ieee64_motorola;
extern int fits_ieee32_intel;
extern int fits_ieee32_motorola;

static FITS_HDU_LIST *fits_new_hdulist(void);
static void fits_delete_hdulist(FITS_HDU_LIST *hdulist);
static FITS_DATA *fits_decode_card(FITS_RECORD_LIST *card, enum FITS_DATA_TYPE type);
static FITS_RECORD_LIST *fits_search_card(FITS_RECORD_LIST *hdr, const char *key);
static void fits_set_error(const char *msg);
#define FITS_RETURN(msg, val) do { fits_set_error(msg); return val; } while(0)