#include <stddef.h>
#include <assert.h>

#define CV_Assert assert

typedef unsigned char uchar;

class RBaseStream {
public:
    void skip(int bytes);
protected:
    uchar* m_current;
};