#include <utility>
#include <cstdint>
#include <cstddef>

namespace Sirikata {
    class JpegError {};
}

class bounded_iostream {
protected:
    size_t byte_bound;
    size_t byte_position;
    Sirikata::JpegError err;
    bounded_iostream* parent;

public:
    uint32_t write_no_buffer(const void* from, size_t bytes_to_write);
    virtual std::pair<unsigned int, Sirikata::JpegError> Write(const unsigned char* from, size_t bytes_to_write) = 0;
};