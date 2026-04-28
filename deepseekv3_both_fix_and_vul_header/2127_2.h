#include <vector>
#include <cstdint>

class ByteVector {
public:
    ByteVector();
    ByteVector mid(uint32_t index, uint32_t length) const;
    size_t size() const;

private:
    struct Data {
        std::vector<uint8_t> data;
        size_t size;
    };
    Data* d;
};

using ConstIterator = std::vector<uint8_t>::const_iterator;
using uint = uint32_t;