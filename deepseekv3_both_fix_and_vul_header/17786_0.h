#include <stdint.h>

#define sz_rfbSetColourMapEntriesMsg 6
#define rfbSetColourMapEntries 1
#define FALSE 0
#define TRUE 1

typedef struct rfbClientRec* rfbClientPtr;
typedef int rfbBool;

struct rfbClientRec {
    struct {
        int bitsPerPixel;
    } format;
};

typedef struct {
    uint8_t type;
    uint8_t pad;
    uint16_t firstColour;
    uint16_t nColours;
} rfbSetColourMapEntriesMsg;

uint16_t Swap16IfLE(uint16_t value);
int rfbWriteExact(rfbClientPtr cl, const char* buf, int len);
void rfbCloseClient(rfbClientPtr cl);
void rfbErr(const char* format, const char* arg);
void rfbLogPerror(const char* msg);