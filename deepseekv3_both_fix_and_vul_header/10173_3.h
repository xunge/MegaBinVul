#include <assert.h>

typedef struct TIFFDirectory {
    int td_samplesperpixel;
    int td_photometric;
    int td_bitspersample;
    int td_sampleformat;
} TIFFDirectory;

typedef struct LogLuvState {
    int encoder_state;
} LogLuvState;

typedef struct TIFF {
    void* tif_data;
    TIFFDirectory tif_dir;
} TIFF;

#define PHOTOMETRIC_LOGL 1
#define SAMPLEFORMAT_INT 1