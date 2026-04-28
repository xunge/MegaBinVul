#include <stdlib.h>
#include <string.h>

typedef int rfbBool;
typedef unsigned int lzo_uint;
typedef unsigned char lzo_byte;

struct rfbZlibHeader {
    int nBytes;
};

struct rfbClient {
    char* raw_buffer;
    int raw_buffer_size;
    char* ultra_buffer;
    int ultra_buffer_size;
};

typedef struct rfbClient rfbClient;
typedef struct rfbZlibHeader rfbZlibHeader;

#define FALSE 0
#define TRUE 1
#define BPP 32
#define LZO_E_OK 0
#define rfbEncodingRaw 0

#define sz_rfbZlibHeader sizeof(rfbZlibHeader)

static int rfbClientSwap32IfLE(int x) { return x; }
static int rfbClientSwap16IfLE(int x) { return x; }
static rfbBool ReadFromRFBServer(rfbClient* client, char* buf, int len) { return TRUE; }
static void rfbClientLog(const char* format, ...) {}
static void CopyRectangle(rfbClient* client, unsigned char* ptr, unsigned short sx, unsigned short sy, unsigned short sw, unsigned short sh) {}
static int lzo1x_decompress(const lzo_byte* src, lzo_uint src_len, lzo_byte* dst, lzo_uint* dst_len, void* wrkmem) { return LZO_E_OK; }