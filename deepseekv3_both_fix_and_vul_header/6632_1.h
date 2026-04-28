#include <assert.h>

struct WBaseStream {
    bool isOpened();
    int m_block_pos;
    char* m_current;
    char* m_start;
    int getPos();
};

#define CV_Assert(expr) assert(expr)