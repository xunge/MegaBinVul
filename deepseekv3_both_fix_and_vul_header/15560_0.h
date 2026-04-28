#include <cstdint>
#include <cstdlib>

typedef unsigned char binary;

class IOCallback {
public:
    void readFully(binary* buffer, std::size_t size);
};

class MemIOCallback {
private:
    binary* dataBuffer;
    std::size_t dataBufferPos;
    std::size_t dataBufferMemorySize;
    std::size_t dataBufferTotalSize;
public:
    std::uint32_t write(IOCallback& IOToRead, std::size_t Size);
};