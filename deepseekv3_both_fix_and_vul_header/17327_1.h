#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <vector>

#define HUF_ENCSIZE 256
#define HUF_DECSIZE 256

typedef struct HufDec {
    int len;
    int lit;
    int *p;
} HufDec;

int readUInt(const char *ptr);
void hufClearDecTable(HufDec *hdec);
void hufUnpackEncTable(const char **ptr, int nbytes, int im, int iM, long long *freq);
void hufBuildDecTable(long long *freq, int im, int iM, HufDec *hdec);
void hufDecode(long long *freq, HufDec *hdec, const char *ptr, int nBits, int iM, int nRaw, unsigned short *raw);
void hufFreeDecTable(HufDec *hdec);