#include <stdint.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>

typedef struct {
    uint32_t u;
    unsigned char c[4];
} mask_t;

typedef struct {
    unsigned char b0;
    unsigned char b1;
} data_t;

typedef struct {
    mask_t mask;
    data_t *data;
    int headerLen;
    int opcode;
} header_t;

typedef struct {
    int (*readFunc)(void *, char *, int);
    void *ctxPtr;
} ctxInfo_t;

typedef struct {
    char *writePos;
    char *readPos;
    char carryBuf[4];
    int carrylen;
    char codeBufDecode[1];
    int nReadPayload;
    int readlen;
    int hybiDecodeState;
    header_t header;
    ctxInfo_t ctxInfo;
} ws_ctx_t;

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof((arr)[0]))
#define WS_HYBI_STATE_ERR (-1)
#define WS_HYBI_STATE_FRAME_COMPLETE 1
#define WS_HYBI_STATE_CLOSE_REASON_PENDING 2
#define WS_OPCODE_CLOSE 8
#define WS_OPCODE_TEXT_FRAME 1
#define WS_OPCODE_BINARY_FRAME 2
#define WS_NTOH16(x) (x)

static int hybiRemaining(ws_ctx_t *wsctx);
static int hybiWsFrameComplete(ws_ctx_t *wsctx);
static char *hybiPayloadStart(ws_ctx_t *wsctx);
static int rfbBase64PtoN(char *out, unsigned char *in, int inlen);
static int hybiReturnData(char *dst, int len, ws_ctx_t *wsctx, int *sockRet);
static void ws_dbg(const char *fmt, ...);
static void rfbErr(const char *fmt, ...);