#include <stdlib.h>
#include <stdint.h>

#define BPP 32
#define LZO_E_OK 0
#define FALSE 0
#define TRUE 1

typedef int rfbBool;
typedef uint8_t lzo_byte;
typedef uint32_t lzo_uint;
typedef lzo_uint *lzo_uintp;

typedef struct {
    int nBytes;
} rfbZlibHeader;

#define sz_rfbZlibHeader sizeof(rfbZlibHeader)

typedef struct rfbClient {
    char *raw_buffer;
    int raw_buffer_size;
    char *ultra_buffer;
    int ultra_buffer_size;
} rfbClient;

extern int rfbClientSwap32IfLE(int);
extern rfbBool ReadFromRFBServer(rfbClient*, char*, int);
extern void rfbClientLog(const char*, ...);
extern void CopyRectangle(rfbClient*, unsigned char*, int, int, int, int);
extern int lzo1x_decompress(const lzo_byte*, lzo_uint, lzo_byte*, lzo_uintp, void*);