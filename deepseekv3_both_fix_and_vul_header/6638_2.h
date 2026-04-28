#include <assert.h>

#define CV_Assert assert

struct RBaseStream {
    int m_start;
    int m_current;
    int m_block_pos;
    int m_block_size;
    void* m_file;

    bool isOpened();
    void setPos(int pos);
};