#include <stdint.h>
#include <stddef.h>

typedef int32_t EAS_I32;
typedef uint32_t EAS_U32;
typedef uint16_t EAS_U16;
typedef int EAS_RESULT;

#define EAS_SUCCESS 0
#define EAS_ERROR_FILE_FORMAT 1
#define EAS_ERROR_SOUND_LIBRARY 2
#define EAS_ERROR_UNRECOGNIZED_FORMAT 3

#define CHUNK_WAVE 0x77617665
#define CHUNK_WSMP 0x77736d70
#define CHUNK_FMT 0x666d7420
#define CHUNK_DATA 0x64617461

#define MAX_DLS_WAVE_SIZE 0x100000

typedef struct {
    EAS_I32 fineTune;
    EAS_I32 unityNote;
    EAS_I32 gain;
    EAS_I32 loopStart;
    EAS_I32 loopLength;
    EAS_I32 bitsPerSample;
} S_WSMP_DATA;

typedef struct {
    uint8_t* pDLSSamples;
    EAS_U32* pDLSSampleOffsets;
    EAS_U32* pDLSSampleLen;
} DLS_DATA;

typedef struct {
    void *hwInstData;
    void *fileHandle;
    DLS_DATA *pDLS;
    S_WSMP_DATA *wsmpData;
    EAS_U32 wavePoolSize;
    EAS_U32 wavePoolOffset;
} SDLS_SYNTHESIZER_DATA;

extern EAS_RESULT EAS_HWFileSeek(void *hwInstData, void *fileHandle, EAS_I32 pos);
extern EAS_RESULT NextChunk(SDLS_SYNTHESIZER_DATA *pDLSData, EAS_I32 *pos, EAS_U32 *temp, EAS_I32 *size);
extern EAS_RESULT Parse_wsmp(SDLS_SYNTHESIZER_DATA *pDLSData, EAS_I32 wsmpPos, S_WSMP_DATA *p);
extern EAS_RESULT Parse_fmt(SDLS_SYNTHESIZER_DATA *pDLSData, EAS_I32 fmtPos, S_WSMP_DATA *p);
extern EAS_RESULT Parse_data(SDLS_SYNTHESIZER_DATA *pDLSData, EAS_I32 dataPos, EAS_I32 dataSize, S_WSMP_DATA *p, void *pSample);

static int bitDepth;