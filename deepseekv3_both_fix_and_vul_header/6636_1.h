#include <assert.h>
#include <stdint.h>

struct RBaseStream {
    int m_block_pos;
    char* m_current;
    char* m_start;
    bool isOpened();
    int getPos();
};

#define CV_Assert(expr) assert(expr)