#include <functional>
#include <cstdint>
#include <climits>

namespace Sirikata {
    class DecoderWriter;
    namespace JpegError {
        struct nil {};
    }
    template<typename T> class JpegAllocator {};
}

class bounded_iostream {
public:
    bounded_iostream(Sirikata::DecoderWriter *w,
                    const std::function<void(Sirikata::DecoderWriter*, size_t)> &size_callback,
                    const Sirikata::JpegAllocator<uint8_t> &alloc);
private:
    Sirikata::DecoderWriter* parent;
    Sirikata::JpegError::nil err;
    std::function<void(Sirikata::DecoderWriter*, size_t)> size_callback;
    size_t buffer_position;
    size_t byte_position;
    size_t byte_bound;
    size_t num_bytes_attempted_to_write;
    void set_bound(size_t bound);
};