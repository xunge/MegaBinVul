#include <stdint.h>
#include <stdlib.h>

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned short tsample_t;
typedef int tsize_t;

struct tiff;
typedef struct tiff TIFF;

extern uint32 TIFFTileRowSize(TIFF*);
extern tsize_t TIFFTileSize(TIFF*);
extern tsize_t TIFFReadTile(TIFF*, void*, uint32, uint32, uint32, uint16);
extern void* _TIFFmalloc(tsize_t);
extern void _TIFFfree(void*);
extern void _TIFFmemcpy(void*, const void*, tsize_t);
extern const char* TIFFFileName(TIFF*);
extern uint32 TIFFCurrentTile(TIFF*);
extern void TIFFError(const char*, const char*, ...);

extern int ignore;
extern int extractContigSamplesBytes(unsigned char*, unsigned char*, uint32, tsample_t, tsample_t, uint16, tsample_t, uint32, uint32);
extern int extractContigSamplesShifted8bits(unsigned char*, unsigned char*, uint32, tsample_t, tsample_t, uint16, tsample_t, uint32, uint32, uint32);
extern int extractContigSamplesShifted16bits(unsigned char*, unsigned char*, uint32, tsample_t, tsample_t, uint16, tsample_t, uint32, uint32, uint32);
extern int extractContigSamplesShifted24bits(unsigned char*, unsigned char*, uint32, tsample_t, tsample_t, uint16, tsample_t, uint32, uint32, uint32);
extern int extractContigSamplesShifted32bits(unsigned char*, unsigned char*, uint32, tsample_t, tsample_t, uint16, tsample_t, uint32, uint32, uint32);