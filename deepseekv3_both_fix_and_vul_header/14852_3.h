#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SAMPLE_LENGTH 16777216
#define CHN_16BIT 0x02
#define CHN_STEREO 0x04

typedef uint32_t UINT;
typedef uint32_t DWORD;
typedef uint16_t WORD;
typedef uint8_t BYTE;
typedef const char* LPCSTR;
typedef uint8_t* LPBYTE;
typedef uint32_t* LPDWORD;

typedef struct MODINSTRUMENT {
    UINT nLength;
    uint32_t uFlags;
    signed char* pSample;
} MODINSTRUMENT;

enum {
    RSF_16BIT = 0x01,
    RSF_STEREO = 0x02,
    RS_PCM8U,
    RS_PCM8D,
    RS_ADPCM4,
    RS_PCM16D,
    RS_PCM16S,
    RS_PCM16M,
    RS_PCM16U,
    RS_STPCM16M,
    RS_STPCM8S,
    RS_STPCM8U,
    RS_STPCM8D,
    RS_STPCM16S,
    RS_STPCM16U,
    RS_STPCM16D,
    RS_IT2148,
    RS_IT21416,
    RS_IT2158,
    RS_IT21516,
    RS_STIPCM8S,
    RS_STIPCM8U,
    RS_STIPCM16S,
    RS_STIPCM16U,
    RS_AMS8,
    RS_AMS16,
    RS_PTM8DTO16,
    RS_MDL8,
    RS_MDL16,
    RS_DMF8,
    RS_DMF16,
    RS_PCM24S,
    RS_PCM32S,
    RS_STIPCM24S,
    RS_STIPCM32S,
    RS_STIPCM16M
};

class CSoundFile {
public:
    UINT ReadSample(MODINSTRUMENT *pIns, UINT nFlags, LPCSTR lpMemFile, DWORD dwMemLength);
};

static signed char CompressionTable[16];

static inline uint16_t bswapLE16(uint16_t x) { return x; }
static inline uint16_t bswapBE16(uint16_t x) { return (x>>8)|(x<<8); }
static inline uint32_t bswapLE32(uint32_t x) { return x; }

static signed char* AllocateSample(UINT size) { return (signed char*)malloc(size); }
static void FreeSample(signed char* p) { free(p); }
static int GetDeltaValue(int delta, BYTE b) { return delta + (b & 0x0F) - (b >> 4); }
static void AdjustSampleLoop(MODINSTRUMENT* pIns) {}
static void ITUnpack8Bit(signed char* pSample, UINT nLength, LPBYTE lpMemFile, DWORD dwMemLength, int b215) {}
static void ITUnpack16Bit(signed char* pSample, UINT nLength, LPBYTE lpMemFile, DWORD dwMemLength, int b215) {}
static void AMSUnpack(const char* src, UINT srcLen, char* dest, UINT destLen, char packChar) {}
static UINT MDLReadBits(DWORD& bitbuf, UINT& bitnum, LPBYTE& ibuf, UINT n) { return 0; }
static UINT DMFUnpack(LPBYTE pSample, LPBYTE ibuf, LPBYTE ibufmax, UINT maxlen) { return 0; }