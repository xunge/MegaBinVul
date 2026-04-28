#include <string.h>

class String {
public:
    String(size_t size, int reserveFlag);
    struct BufferSlice {
        char* ptr;
    };
    BufferSlice bufferSlice();
    void setSize(size_t size);
};

size_t safe_address(size_t chunks, size_t endlen, size_t srclen);
const int ReserveString = 0;