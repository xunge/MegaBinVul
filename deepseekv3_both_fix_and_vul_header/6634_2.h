#include <assert.h>

class RBaseStream {
protected:
    int m_current;
public:
    void skip(int bytes);
};

#define CV_Assert assert