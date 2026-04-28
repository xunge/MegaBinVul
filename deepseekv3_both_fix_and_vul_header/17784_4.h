#include <stdlib.h>
#include <string.h>
#include <errno.h>
#ifdef WIN32
#include <winsock2.h>
#endif

#define DEFAULT_CONNECT_TIMEOUT 0
#define DEFAULT_READ_TIMEOUT 0
#define RFB_INVALID_SOCKET (-1)
#define FALSE 0
#define TRUE 1

typedef int rfbBool;

typedef struct {
    int requestedDepth;
} AppData;

typedef struct {
    int bitsPerPixel;
    int depth;
    rfbBool bigEndian;
    rfbBool trueColour;
    int redMax;
    int greenMax;
    int blueMax;
    int redShift;
    int greenShift;
    int blueShift;
} rfbPixelFormat;

typedef struct {
    int x;
    int y;
} rfbRectangle;

typedef void (*HandleKeyboardLedStateProc)(int);
typedef void (*DummyPointFunc)(int, int);
typedef void (*DummyRectFunc)(int, int, int, int);
typedef void (*DummyFunc)(void);
typedef void (*CopyRectangleFromRectangleFunc)(int, int, int, int, int, int);
typedef void (*FillRectangleFunc)(int, int, int, int, unsigned long);
typedef void (*CopyRectangleFunc)(int, int, int, int, char*);
typedef char* (*ReadPasswordFunc)(void);
typedef int (*MallocFrameBufferFunc)(int, int);

typedef struct {
    AppData appData;
    int endianTest;
    char* programName;
    char* serverHost;
    int serverPort;
    char* destHost;
    int destPort;
    int connectTimeout;
    int readTimeout;
    int CurrentKeyboardLedState;
    HandleKeyboardLedStateProc HandleKeyboardLedState;
    rfbRectangle updateRect;
    char* frameBuffer;
    int outputWindow;
    rfbPixelFormat format;
    char* bufoutptr;
    int buffered;
    char buf[1024];
    int raw_buffer_size;
    rfbBool decompStreamInited;
    rfbBool zlibStreamActive[4];
    DummyPointFunc HandleCursorPos;
    DummyRectFunc SoftCursorLockArea;
    DummyFunc SoftCursorUnlockScreen;
    DummyRectFunc GotFrameBufferUpdate;
    CopyRectangleFromRectangleFunc GotCopyRect;
    FillRectangleFunc GotFillRect;
    CopyRectangleFunc GotBitmap;
    void (*FinishedFrameBufferUpdate)(void);
    ReadPasswordFunc GetPassword;
    MallocFrameBufferFunc MallocFrameBuffer;
    DummyFunc Bell;
    int QoS_DSCP;
    int authScheme;
    int subAuthScheme;
    void* GetCredential;
    void* tlsSession;
    void (*LockWriteToTLS)(void);
    void (*UnlockWriteToTLS)(void);
    int sock;
    int listenSock;
    char* listenAddress;
    int listen6Sock;
    char* listen6Address;
    char* clientAuthSchemes;
    void* GetSASLMechanism;
    void* GetUser;
    void* saslSecret;
} rfbClient;

void rfbClientErr(const char* fmt, ...);
void initAppData(AppData* appData);

extern DummyPointFunc DummyPoint;
extern DummyRectFunc DummyRect;
extern DummyFunc Dummy;
extern CopyRectangleFromRectangleFunc CopyRectangleFromRectangle;
extern FillRectangleFunc FillRectangle;
extern CopyRectangleFunc CopyRectangle;
extern ReadPasswordFunc ReadPassword;
extern MallocFrameBufferFunc MallocFrameBuffer;