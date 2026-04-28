#include <assert.h>
#include <string.h>

#define CV_Assert assert

typedef unsigned char uchar;

struct RLByteStream {
    uchar* m_current;
    uchar* m_end;
    void readBlock();
    int getBytes(void* buffer, int count);
};