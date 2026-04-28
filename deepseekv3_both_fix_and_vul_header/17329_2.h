#include <stdbool.h>

#define HUF_DECBITS 14
#define HUF_DECMASK ((1 << HUF_DECBITS) - 1)

typedef struct {
    int len;
    int lit;
    int *p;
} HufDec;

static void getChar(long long &c, int &lc, const char *&in);
static bool getCode(int lit, int rlc, long long &c, int &lc, const char *&in, const char *ie, unsigned short *&out, unsigned short *outb, unsigned short *oe);
static bool getCode(int lit, int rlc, long long &c, int &lc, const char *&in, unsigned short *&out, unsigned short *oe);
static int hufLength(long long hcode);
static long long hufCode(long long hcode);