#include <assert.h>
#include <stdint.h>

typedef struct {
    void* tif_data;
    struct {
        uint16_t td_bitspersample;
        uint16_t td_sampleformat;
    } tif_dir;
} TIFF;

typedef struct TIFFDirectory {
    uint16_t td_bitspersample;
    uint16_t td_sampleformat;
} TIFFDirectory;

typedef struct {
    int state;
#define PLSTATE_INIT 1
} PixarLogState;

#define SAMPLEFORMAT_UINT 1