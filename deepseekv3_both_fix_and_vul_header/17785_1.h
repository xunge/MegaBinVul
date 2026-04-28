#include <stdint.h>
#include <string.h>
#include <strings.h>
#include <stdlib.h>

#define MAX_ENCODINGS 50
#define sz_rfbSetPixelFormatMsg (sizeof(rfbSetPixelFormatMsg))
#define sz_rfbSetEncodingsMsg (sizeof(rfbSetEncodingsMsg))

typedef int rfbBool;
#define TRUE 1
#define FALSE 0

typedef struct {
    uint8_t bitsPerPixel;
    uint8_t depth;
    uint8_t bigEndian;
    uint8_t trueColor;
    uint16_t redMax;
    uint16_t greenMax;
    uint16_t blueMax;
    uint8_t redShift;
    uint8_t greenShift;
    uint8_t blueShift;
    uint8_t pad[3];
} rfbPixelFormat;

typedef struct {
    uint8_t type;
    uint8_t pad1;
    uint16_t pad2;
    rfbPixelFormat format;
} rfbSetPixelFormatMsg;

typedef struct {
    uint8_t type;
    uint8_t pad;
    uint16_t nEncodings;
} rfbSetEncodingsMsg;

typedef struct rfbClientProtocolExtension {
    struct rfbClientProtocolExtension* next;
    int* encodings;
} rfbClientProtocolExtension;

extern rfbClientProtocolExtension* rfbClientExtensions;

#define rfbEncodingRaw 0
#define rfbEncodingCopyRect 1
#define rfbEncodingRRE 2
#define rfbEncodingCoRRE 4
#define rfbEncodingHextile 5
#define rfbEncodingZlib 6
#define rfbEncodingTight 7
#define rfbEncodingZlibHex 8
#define rfbEncodingTRLE 15
#define rfbEncodingZRLE 16
#define rfbEncodingZYWRLE 17
#define rfbEncodingUltra 18
#define rfbEncodingUltraZip 19
#define rfbEncodingXCursor -240
#define rfbEncodingRichCursor -239
#define rfbEncodingPointerPos -232
#define rfbEncodingKeyboardLedState -129
#define rfbEncodingNewFBSize -223
#define rfbEncodingLastRect -224
#define rfbEncodingSupportedMessages -256
#define rfbEncodingSupportedEncodings -255
#define rfbEncodingServerIdentity -254
#define rfbEncodingXvp -309
#define rfbEncodingCompressLevel0 0xFFFFFF00
#define rfbEncodingQualityLevel0 0xFFFFFFE0
#define rfbEncodingCompressLevel1 0xFFFFFF01

#define rfbSetPixelFormat 0
#define rfbSetEncodings 2

extern rfbBool SupportsClient2Server(void* client, int type);
extern rfbBool WriteToRFBServer(void* client, char* buf, int len);
extern rfbBool SameMachine(int sock);
extern void rfbClientLog(const char* format, ...);

typedef struct {
    char* encodingsString;
    int compressLevel;
    int enableJPEG;
    int qualityLevel;
    rfbBool useRemoteCursor;
} AppData;

typedef struct {
    int sock;
    AppData appData;
    rfbPixelFormat format;
    rfbBool canHandleNewFBSize;
} rfbClient;

static inline uint16_t rfbClientSwap16IfLE(uint16_t x) {
    return x;
}

static inline uint32_t rfbClientSwap32IfLE(uint32_t x) {
    return x;
}