#include <string.h>
#include <stdint.h>

#define FALSE 0
#define TRUE 1

#define ID_LARGE 0x40
#define ID_UNIQUE 0x3f
#define ID_BLOCK_CHECKSUM 0x0f
#define ID_ODD_SIZE 0x40
#define HAS_CHECKSUM 0x20

typedef struct {
    char ckID[4];
    uint32_t ckSize;
    uint16_t version;
    uint16_t flags;
} WavpackHeader;

#define BITSTREAM_SHORTS

#ifdef BITSTREAM_SHORTS
#define WavpackNativeToLittleEndian(header, format)
#define WavpackLittleEndianToNative(header, format)
#else
#define WavpackHeaderFormat
#define WavpackNativeToLittleEndian(header, format)
#define WavpackLittleEndianToNative(header, format)
#endif