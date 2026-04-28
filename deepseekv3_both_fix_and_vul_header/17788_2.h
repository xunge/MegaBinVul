#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>

#define RFB_BUFFER_SIZE 8192
#define MAX_TEXTCHAT_SIZE 1024
#define sz_rfbFramebufferUpdateMsg 4
#define sz_rfbFramebufferUpdateRectHeader 12
#define sz_rfbCopyRect 4
#define sz_rfbServerCutTextMsg 8
#define sz_rfbTextChatMsg 8
#define sz_rfbXvpMsg 4
#define sz_rfbResizeFrameBufferMsg 8
#define sz_rfbPalmVNCReSizeFrameBufferMsg 8
#define sz_rfbSupportedMessages 128

typedef bool rfbBool;
#define TRUE true
#define FALSE false

typedef struct {
    int x, y, w, h;
} rfbRectangle;

typedef struct {
    uint32_t encoding;
    rfbRectangle r;
} rfbFramebufferUpdateRectHeader;

typedef struct {
    uint16_t srcX, srcY;
} rfbCopyRect;

typedef struct {
    uint8_t type;
    union {
        struct {
            uint16_t nRects;
        } fu;
        struct {
            uint32_t length;
        } sct;
        struct {
            uint32_t length;
        } tc;
        struct {
            uint8_t version;
            uint8_t code;
        } xvp;
        struct {
            uint16_t framebufferWidth;
            uint16_t framebufferHeigth;
        } rsfb;
        struct {
            uint16_t buffer_w;
            uint16_t buffer_h;
        } prsfb;
    };
} rfbServerToClientMsg;

typedef struct {
    uint16_t client2server[32];
    uint16_t server2client[32];
} rfbSupportedMessages;

typedef struct _rfbClientProtocolExtension {
    struct _rfbClientProtocolExtension *next;
    rfbBool (*handleEncoding)(struct _rfbClient* client, rfbFramebufferUpdateRectHeader *rect);
    rfbBool (*handleMessage)(struct _rfbClient* client, rfbServerToClientMsg *msg);
} rfbClientProtocolExtension;

typedef struct _rfbClient {
    int serverPort;
    struct {
        bool readTimestamp;
    } *vncRec;
    int width;
    int height;
    struct {
        int x, y, w, h;
    } updateRect;
    struct {
        int bitsPerPixel;
        bool bigEndian;
        uint32_t redMax, greenMax, blueMax;
        uint32_t redShift, greenShift, blueShift;
    } format;
    struct {
        struct {
            uint32_t greenMax;
        } format;
    } si;
    struct {
        int qualityLevel;
    } appData;
    uint8_t *buffer;
    bool KeyboardLedStateEnabled;
    uint32_t CurrentKeyboardLedState;
    rfbSupportedMessages supportedMessages;
    rfbBool (*HandleCursorPos)(struct _rfbClient*, int, int);
    rfbBool (*HandleKeyboardLedState)(struct _rfbClient*, uint32_t, int);
    rfbBool (*MallocFrameBuffer)(struct _rfbClient*);
    rfbBool (*SoftCursorLockArea)(struct _rfbClient*, int, int, int, int);
    rfbBool (*SoftCursorUnlockScreen)(struct _rfbClient*);
    void (*GotBitmap)(struct _rfbClient*, uint8_t*, int, int, int, int);
    void (*GotCopyRect)(struct _rfbClient*, int, int, int, int, int, int);
    void (*GotFrameBufferUpdate)(struct _rfbClient*, int, int, int, int);
    void (*FinishedFrameBufferUpdate)(struct _rfbClient*);
    void (*Bell)(struct _rfbClient*);
    void (*GotXCutText)(struct _rfbClient*, char*, uint32_t);
    void (*HandleTextChat)(struct _rfbClient*, int, char*);
    void (*HandleXvpMsg)(struct _rfbClient*, uint8_t, uint8_t);
} rfbClient;

enum {
    rfbSetColourMapEntries = 1,
    rfbFramebufferUpdate = 0,
    rfbBell = 2,
    rfbServerCutText = 3,
    rfbTextChat = 4,
    rfbXvp = 250,
    rfbResizeFrameBuffer = 251,
    rfbPalmVNCReSizeFrameBuffer = 252
};

enum {
    rfbEncodingRaw = 0,
    rfbEncodingCopyRect = 1,
    rfbEncodingRRE = 2,
    rfbEncodingCoRRE = 4,
    rfbEncodingHextile = 5,
    rfbEncodingZlib = 6,
    rfbEncodingTight = 7,
    rfbEncodingZRLE = 16,
    rfbEncodingZYWRLE = 17,
    rfbEncodingUltra = 18,
    rfbEncodingUltraZip = 19,
    rfbEncodingTRLE = 15,
    rfbEncodingXCursor = -240,
    rfbEncodingRichCursor = -239,
    rfbEncodingPointerPos = -232,
    rfbEncodingKeyboardLedState = -231,
    rfbEncodingNewFBSize = -223,
    rfbEncodingSupportedMessages = -222,
    rfbEncodingSupportedEncodings = -221,
    rfbEncodingServerIdentity = -220,
    rfbEncodingLastRect = -224
};

enum {
    rfbTextChatOpen = 0,
    rfbTextChatClose = 1,
    rfbTextChatFinished = 2
};

extern rfbClientProtocolExtension* rfbClientExtensions;
extern rfbBool ReadFromRFBServer(rfbClient* client, char* buf, int len);
extern rfbBool HandleCursorShape(rfbClient* client, int x, int y, int w, int h, int encoding);
extern rfbBool SendIncrementalFramebufferUpdateRequest(rfbClient* client);
extern rfbBool SendFramebufferUpdateRequest(rfbClient* client, int x, int y, int w, int h, rfbBool incremental);
extern void rfbClientLog(const char* format, ...);
extern void rfbClientErr(const char* format, ...);
extern uint16_t rfbClientSwap16IfLE(uint16_t value);
extern uint32_t rfbClientSwap32IfLE(uint32_t value);
extern void SetClient2Server(rfbClient* client, int msg);
extern void SetServer2Client(rfbClient* client, int msg);