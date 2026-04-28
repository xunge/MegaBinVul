#include <stdint.h>

#define HUF_ENCSIZE 65536
#define HUF_DECSIZE 65536

typedef int64_t Int64;

typedef struct HufDec {
    int len;
    int lit;
    int *p;
} HufDec;

class FastHufDecoder {
public:
    static bool enabled();
    FastHufDecoder(const char *ptr, int nCompressed, int im, int iM, int iM2);
    void decode(unsigned char *ptr, int nBits, unsigned short *raw, int nRaw);
};

template <typename T, int N>
class AutoArray {
    T data[N];
public:
    T& operator[](int i) { return data[i]; }
};

void notEnoughData();
void invalidTableSize();
void invalidNBits();
int readUInt(const char *ptr);
void hufClearDecTable(AutoArray<HufDec, HUF_DECSIZE> &hdec);
void hufUnpackEncTable(const char **ptr, int nCompressed, int im, int iM, AutoArray<Int64, HUF_ENCSIZE> &freq);
void hufBuildDecTable(AutoArray<Int64, HUF_ENCSIZE> &freq, int im, int iM, AutoArray<HufDec, HUF_DECSIZE> &hdec);
void hufDecode(AutoArray<Int64, HUF_ENCSIZE> &freq, AutoArray<HufDec, HUF_DECSIZE> &hdec, const char *ptr, int nBits, int iM, int nRaw, unsigned short *raw);
void hufFreeDecTable(AutoArray<HufDec, HUF_DECSIZE> &hdec);