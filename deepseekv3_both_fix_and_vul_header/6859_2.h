#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

typedef bool rfbBool;

typedef struct rfbPixelFormat {
    uint8_t bitsPerPixel;
    uint8_t depth;
    uint8_t bigEndian;
    uint8_t trueColour;
    uint16_t redMax;
    uint16_t greenMax;
    uint16_t blueMax;
    uint8_t redShift;
    uint8_t greenShift;
    uint8_t blueShift;
} rfbPixelFormat;

typedef struct rfbScreenInfo {
    void (*setTranslateFunction)(void*);
    void (*kbdAddEvent)(bool, uint32_t, void*);
    void (*ptrAddEvent)(uint8_t, uint16_t, uint16_t, void*);
    void (*setSingleWindow)(void*, uint16_t, uint16_t);
    void (*setServerInput)(void*, uint8_t);
    void (*setTextChat)(void*, uint32_t, char*);
    void (*setXCutText)(char*, uint32_t, void*);
    bool (*setClientColourMap)(void*, int, int);
    bool dontConvertRichCursorToXCursor;
    uint16_t width;
    uint16_t height;
    uint16_t deferPtrUpdateTime;
    void* pointerClient;
    bool (*xvpHook)(void*, uint8_t, uint8_t);
} rfbScreenInfo;

typedef struct rfbClientRec {
    rfbPixelFormat format;
    bool readyForSetColourMapEntries;
    rfbScreenInfo* screen;
    int preferredEncoding;
    bool useCopyRect;
    bool useNewFBSize;
    bool cursorWasChanged;
    bool useRichCursorEncoding;
    bool enableCursorPosUpdates;
    bool enableCursorShapeUpdates;
    bool enableLastRectEncoding;
    bool enableKeyboardLedState;
    bool enableSupportedMessages;
    bool enableSupportedEncodings;
    bool enableServerIdentity;
    int tightQualityLevel;
    int tightCompressLevel;
    int turboSubsampLevel;
    int turboQualityLevel;
    int zlibCompressLevel;
    char* host;
    bool cursorWasMoved;
    bool viewOnly;
    uint8_t lastPtrButtons;
    uint16_t lastPtrX;
    uint16_t lastPtrY;
    bool PalmVNC;
    void* scaledScreen;
    void* updateMutex;
    void* updateCond;
    void* requestedRegion;
    void* modifiedRegion;
    void* copyRegion;
    struct rfbExtensionData* extensions;
} rfbClientRec;

typedef rfbClientRec* rfbClientPtr;

typedef struct sraRegion {
    // Region implementation details would go here
} sraRegion;
typedef sraRegion* sraRegionPtr;

typedef struct rfbExtensionData {
    struct rfbExtensionData* next;
    void* data;
    struct rfbProtocolExtension* extension;
} rfbExtensionData;

typedef struct rfbProtocolExtension {
    struct rfbProtocolExtension* next;
    bool (*handleMessage)(void*, void*, void*);
    bool (*enablePseudoEncoding)(void*, void**, int);
    int* pseudoEncodings;
} rfbProtocolExtension;

typedef uint32_t rfbKeySym;

typedef union {
    struct {
        uint8_t type;
        union {
            struct {
                rfbPixelFormat format;
            } spf;
            struct {
                uint16_t nEncodings;
            } se;
            struct {
                uint16_t x;
                uint16_t y;
                uint16_t w;
                uint16_t h;
                uint8_t incremental;
            } fur;
            struct {
                uint8_t down;
                uint32_t key;
            } ke;
            struct {
                uint16_t x;
                uint16_t y;
                uint8_t buttonMask;
            } pe;
            struct {
                uint8_t contentType;
                uint8_t contentParam;
                uint32_t size;
                uint32_t length;
            } ft;
            struct {
                uint16_t x;
                uint16_t y;
                uint8_t status;
            } sw;
            struct {
                uint8_t status;
                uint16_t pad;
            } sim;
            struct {
                uint8_t pad;
                uint16_t pad2;
                uint32_t length;
            } tc;
            struct {
                uint32_t length;
            } cct;
            struct {
                uint8_t scale;
            } ssc;
            struct {
                uint8_t version;
                uint8_t code;
            } xvp;
        };
    };
    uint8_t pad[64]; // Ensure minimum size
} rfbClientToServerMsg;

#define TRUE 1
#define FALSE 0

// Message type constants
#define rfbSetPixelFormat 0
#define rfbFixColourMapEntries 1
#define rfbSetEncodings 2
#define rfbFramebufferUpdateRequest 3
#define rfbKeyEvent 4
#define rfbPointerEvent 5
#define rfbClientCutText 6
#define rfbFileTransfer 7
#define rfbSetSW 8
#define rfbSetServerInput 9
#define rfbTextChat 10
#define rfbPalmVNCSetScaleFactor 11
#define rfbSetScale 12
#define rfbXvp 13

// Encoding constants
#define rfbEncodingRaw 0
#define rfbEncodingCopyRect 1
#define rfbEncodingRRE 2
#define rfbEncodingCoRRE 4
#define rfbEncodingHextile 5
#define rfbEncodingUltra 6
#define rfbEncodingZlib 7
#define rfbEncodingTight 8
#define rfbEncodingZRLE 16
#define rfbEncodingZYWRLE 17
#define rfbEncodingTightPng 18
#define rfbEncodingXCursor 19
#define rfbEncodingRichCursor 20
#define rfbEncodingPointerPos 21
#define rfbEncodingLastRect 22
#define rfbEncodingNewFBSize 23
#define rfbEncodingKeyboardLedState 24
#define rfbEncodingSupportedMessages 25
#define rfbEncodingSupportedEncodings 26
#define rfbEncodingServerIdentity 27
#define rfbEncodingXvp 28

// Text chat constants
#define rfbTextChatOpen 0xFFFFFFFF
#define rfbTextChatClose 0xFFFFFFFE
#define rfbTextChatFinished 0xFFFFFFFD
#define rfbTextMaxSize 4096

// XVP constants
#define rfbXvp_Init 0
#define rfbXvp_Fail 1

// Tight encoding constants
#define TIGHT_DEFAULT_COMPRESSION 6
#define TURBO_DEFAULT_SUBSAMP 0

// Message size constants
#define sz_rfbSetPixelFormatMsg 20
#define sz_rfbFixColourMapEntriesMsg 4
#define sz_rfbSetEncodingsMsg 4
#define sz_rfbFramebufferUpdateRequestMsg 10
#define sz_rfbKeyEventMsg 8
#define sz_rfbPointerEventMsg 6
#define sz_rfbFileTransferMsg 10
#define sz_rfbSetSWMsg 5
#define sz_rfbSetServerInputMsg 3
#define sz_rfbTextChatMsg 7
#define sz_rfbClientCutTextMsg 8
#define sz_rfbSetScaleMsg 2
#define sz_rfbXvpMsg 2

// Function declarations
uint16_t Swap16IfLE(uint16_t value);
uint32_t Swap32IfLE(uint32_t value);
void rfbLogPerror(const char* str);
void rfbCloseClient(rfbClientPtr cl);
int rfbReadExact(rfbClientPtr cl, char* buf, int len);
void rfbLog(const char* format, ...);
void rfbStatRecordMessageRcvd(rfbClientPtr cl, uint8_t type, int len, int bytes);
void rfbRedrawAfterHideCursor(rfbClientPtr cl, void* data);
bool rectSwapIfLEAndClip(uint16_t* x, uint16_t* y, uint16_t* w, uint16_t* h, rfbClientPtr cl);
bool rfbSetClientColourMap(rfbClientPtr cl, int first, int n);
void rfbProcessFileTransfer(rfbClientPtr cl, uint8_t contentType, uint8_t contentParam, uint32_t size, uint32_t length);
void rfbScalingSetup(rfbClientPtr cl, int width, int height);
void rfbSendNewScaleSize(rfbClientPtr cl);
bool rfbSendXvp(rfbClientPtr cl, uint8_t version, uint8_t code);
const char* encodingName(uint32_t enc, char* buf, size_t len);
rfbProtocolExtension* rfbGetExtensionIterator(void);
void rfbReleaseExtensionIterator(void);
void rfbEnableExtension(rfbClientPtr cl, rfbProtocolExtension* ext, void* data);
sraRegionPtr sraRgnCreateRect(int x1, int y1, int x2, int y2);
void sraRgnOr(sraRegionPtr dst, sraRegionPtr src);
void sraRgnSubtract(sraRegionPtr dst, sraRegionPtr src);
void sraRgnDestroy(sraRegionPtr rgn);
uint16_t ScaleX(void* scaledScreen, rfbScreenInfo* screen, uint16_t x);
uint16_t ScaleY(void* scaledScreen, rfbScreenInfo* screen, uint16_t y);
void LOCK(void* mutex);
void UNLOCK(void* mutex);
void TSIGNAL(void* cond);