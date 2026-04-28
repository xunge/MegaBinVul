#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <vector>

#define CV_Assert assert

class WBaseStream {
protected:
    char* m_start;
    char* m_current;
    std::vector<char>* m_buf;
    FILE* m_file;
    size_t m_block_pos;
    
public:
    bool isOpened() const;
    void writeBlock();
};