#include <cstdlib>
#include <cstring>

typedef unsigned char binary;

class MemIOCallback {
private:
    binary* dataBuffer;
    std::size_t dataBufferMemorySize;
    std::size_t dataBufferPos;
    std::size_t dataBufferTotalSize;
public:
    std::size_t write(const void* Buffer, std::size_t Size);
};