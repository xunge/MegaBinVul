#include <stdint.h>
#include <assert.h>

#define CV_Assert(expr) assert(expr)

struct RBaseStream {
    uint8_t* m_current;
    uint8_t* m_start;
    int m_block_pos;
    bool isOpened();
    int getPos();
};

int validateToInt(int64_t value);