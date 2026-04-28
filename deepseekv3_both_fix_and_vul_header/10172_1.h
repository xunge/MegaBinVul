#include <stdint.h>

#define PHOTOMETRIC_LOGLUV 32844
#define PHOTOMETRIC_LOGL 32845
#define COMPRESSION_SGILOG24 34676

#define SGILOGDATAFMT_FLOAT 0
#define SGILOGDATAFMT_16BIT 1
#define SGILOGDATAFMT_RAW 2

typedef struct {
    int user_datafmt;
    void (*tfunc)();
    int encoder_state;
} LogLuvState;

typedef struct {
    int td_photometric;
    int td_compression;
} TIFFDirectory;

typedef struct {
    TIFFDirectory tif_dir;
    void* tif_clientdata;
    int (*tif_encoderow)();
} TIFF;

extern int LogLuvInitState(TIFF* tif);
extern int LogL16InitState(TIFF* tif);
extern int LogLuvEncode24(TIFF* tif);
extern int LogLuvEncode32(TIFF* tif);
extern int LogL16Encode(TIFF* tif);
extern void Luv24fromXYZ();
extern void Luv24fromLuv48();
extern void Luv32fromXYZ();
extern void Luv32fromLuv48();
extern void L16fromY();
extern LogLuvState* EncoderState(TIFF* tif);
extern void TIFFErrorExt(void* clientdata, const char* module, const char* fmt, ...);