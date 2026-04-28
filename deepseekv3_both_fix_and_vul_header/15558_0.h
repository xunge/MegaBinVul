#include <cstdint>
#include <cstring>

class MemIOCallback {
private:
    char* dataBuffer;
    std::uint64_t dataBufferPos;
    std::uint64_t dataBufferTotalSize;
public:
    std::size_t read(void *Buffer, std::size_t Size);
};