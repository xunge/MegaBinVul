#include <stddef.h>

typedef int EAS_RESULT;
typedef void* EAS_HW_DATA_HANDLE;
typedef void* EAS_FILE_HANDLE;
typedef void* EAS_DLSLIB_HANDLE;
typedef int EAS_I32;
typedef unsigned int EAS_U32;
typedef unsigned short EAS_U16;
typedef int EAS_BOOL;

#define EAS_SUCCESS 0
#define EAS_ERROR_FILE_FORMAT (-1)
#define EAS_ERROR_UNRECOGNIZED_FORMAT (-2)
#define EAS_ERROR_MALLOC_FAILED (-3)
#define EAS_FALSE 0
#define EAS_TRUE 1

#define CHUNK_RIFF 0x52494646
#define CHUNK_DLS 0x444C5320
#define CHUNK_CDL 0x63646C20
#define CHUNK_LINS 0x6C696E73
#define CHUNK_WVPL 0x7776706C
#define CHUNK_PTBL 0x7074626C

#define DLS_MAX_WAVE_COUNT 1024
#define DLS_MAX_REGION_COUNT 4096
#define DLS_MAX_ART_COUNT 4096
#define DLS_MAX_INST_COUNT 128

typedef struct {
    EAS_U32 cueSize;
} POOLCUE;

typedef struct {
    EAS_U32 count;
    POOLCUE cues[1];
} POOLTABLE;

typedef struct {
    EAS_U16 refCount;
    EAS_U16 numDLSPrograms;
    EAS_U16 numDLSRegions;
    EAS_U16 numDLSArticulations;
    EAS_U16 numDLSSamples;
    void* pDLSPrograms;
    void* pDLSRegions;
    void* pDLSArticulations;
    void* pDLSSampleLen;
    void* pDLSSampleOffsets;
    void* pDLSSamples;
} S_EAS;

typedef struct {
    EAS_U32 waveCount;
    EAS_U32 regionCount;
    EAS_U32 artCount;
    EAS_U32 instCount;
    EAS_U32 wavePoolSize;
    EAS_BOOL bigEndian;
    EAS_BOOL filterUsed;
    EAS_HW_DATA_HANDLE hwInstData;
    EAS_FILE_HANDLE fileHandle;
    S_EAS* pDLS;
    void* wsmpData;
} SDLS_SYNTHESIZER_DATA;

typedef struct {
    EAS_U32 unused;
} S_WSMP_DATA;

typedef struct {
    EAS_U32 unused;
} S_PROGRAM;

typedef struct {
    EAS_U32 unused;
} S_DLS_REGION;

typedef struct {
    EAS_U32 unused;
} S_DLS_ARTICULATION;

static S_DLS_ARTICULATION defaultArt;

EAS_RESULT EAS_HWFileSeek(EAS_HW_DATA_HANDLE, EAS_FILE_HANDLE, EAS_I32);
EAS_RESULT EAS_HWReadFile(EAS_HW_DATA_HANDLE, EAS_FILE_HANDLE, void*, EAS_I32, EAS_I32*);
void* EAS_HWMalloc(EAS_HW_DATA_HANDLE, EAS_I32);
void EAS_HWFree(EAS_HW_DATA_HANDLE, void*);
void EAS_HWMemSet(void*, int, EAS_I32);
void* PtrOfs(void*, EAS_I32);
EAS_RESULT NextChunk(SDLS_SYNTHESIZER_DATA*, EAS_I32*, EAS_U32*, EAS_I32*);
EAS_RESULT Parse_cdl(SDLS_SYNTHESIZER_DATA*, EAS_I32, EAS_U32*);
EAS_RESULT Parse_ptbl(SDLS_SYNTHESIZER_DATA*, EAS_I32, EAS_I32, EAS_I32);
EAS_RESULT Parse_lins(SDLS_SYNTHESIZER_DATA*, EAS_I32, EAS_I32);
void Convert_art(SDLS_SYNTHESIZER_DATA*, S_DLS_ARTICULATION*, EAS_I32);
void DLSCleanup(EAS_HW_DATA_HANDLE, S_EAS*);