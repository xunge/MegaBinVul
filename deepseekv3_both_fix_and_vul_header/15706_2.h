#include <stdbool.h>
#include <stdint.h>
#include <limits.h>
#include <netinet/in.h>
#include <vector>
#include <string>
#include <limits>

namespace Network {
struct ProxyProtocolData {
    struct Tlv {
        uint8_t type;
        std::vector<uint8_t> value;
    };
    std::vector<Tlv> tlv_vector_;
    struct Address {
        class Ip {
        public:
            std::string addressAsString() const;
            int port() const;
            int version() const;
        };
        Ip* ip() const;
    };
    Address* src_addr_;
    Address* dst_addr_;
};
}

namespace Buffer {
class Instance {
public:
    void add(const void* data, size_t size);
};
}

void generateV2Header(const std::string& src_addr, const std::string& dst_addr, int src_port, int dst_port, int version, uint16_t extension_length, Buffer::Instance& out);

#define PROXY_PROTO_V2_TLV_TYPE_LENGTH_LEN 3
#define ENVOY_LOG_MISC(level, ...)
#define IS_ENVOY_BUG(msg)
#define ASSERT(expr)

namespace absl {
template<typename T>
class flat_hash_set {
public:
    bool contains(const T& value) const;
};
}