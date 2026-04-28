#include <cstdint>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

using Bytef = unsigned char;

enum LogLevel { trace };

#define ENVOY_LOG(level, fmt, arg1, arg2) \
    do { \
        std::ostringstream oss; \
        oss << "excessive decompression ratio detected: output size " << arg1 << " for input size " << arg2; \
        std::cout << oss.str() << std::endl; \
    } while (0)

struct Buffer {
    struct RawSlice {
        void* mem_;
        size_t len_;
    };
    struct Instance {
        uint64_t length() const;
        std::vector<Buffer::RawSlice> getRawSlices() const;
    };
};

struct Runtime {
    static bool runtimeFeatureEnabled(const char* feature);
};

class ZlibDecompressorImpl {
public:
    void decompress(const Buffer::Instance& input_buffer, Buffer::Instance& output_buffer);

private:
    struct Stats {
        struct Counter {
            void inc();
        } zlib_data_error_;
        void inc();
    } stats_;
    
    struct z_stream {
        unsigned int avail_in;
        unsigned int avail_out;
        Bytef* next_in;
        Bytef* next_out;
    }* zstream_ptr_;
    
    bool inflateNext();
    void updateOutput(Buffer::Instance& output_buffer);
    static constexpr uint64_t MaxInflateRatio = 100;
};