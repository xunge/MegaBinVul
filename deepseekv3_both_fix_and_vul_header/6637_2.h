#include <assert.h>
#include <string.h>

#define CV_Assert assert

typedef unsigned char uchar;

struct WLByteStream {
    uchar* m_current;
    uchar* m_end;
    void writeBlock();
    void putBytes(const void* buffer, int count);
};