#include <vector>
#include <cstring>
#include <cstdint>
#include <string>

typedef int64_t tinyexr_int64;

struct ChannelInfo {
    std::string name;
    int pixel_type;
    unsigned char p_linear;
    int x_sampling;
    int y_sampling;
};

namespace tinyexr {
    void swap4(unsigned int*);
}

const char* ReadString(std::string* out, const char* ptr, size_t len);