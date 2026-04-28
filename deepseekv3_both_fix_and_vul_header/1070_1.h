#include <cstdint>
#include <memory>
#include <vector>

namespace port {
    struct StringListDecoder {
        bool ReadSizes(std::vector<uint32_t>* sizes);
        const char* Data(size_t size);
    };
}

struct ResourceHandleProto {
    bool ParseFromArray(const char* data, size_t size);
};

struct ResourceHandle {
    struct Status {
        bool ok() const;
    };
    Status FromProto(const ResourceHandleProto& proto);
};

using uint32 = uint32_t;