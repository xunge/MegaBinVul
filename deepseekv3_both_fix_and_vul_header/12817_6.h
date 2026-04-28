#include <arpa/inet.h>
#include <stdint.h>
#include <sys/types.h>
#include <vector>

typedef unsigned char byte;
#define HEADER_LENGTH 24

namespace dev {
namespace network {
    const ssize_t PACKET_INCOMPLETE = -1;
    const ssize_t PACKET_ERROR = -2;
}  // namespace network
namespace eth {
    const uint16_t CompressFlag = 0x8000;
}  // namespace eth
}  // namespace dev

typedef uint16_t VERSION_TYPE;
typedef uint32_t PROTOCOL_ID;
typedef uint16_t PACKET_TYPE;

class bytesConstRef {
public:
    bytesConstRef(const byte* data, size_t size) : m_data(data), m_size(size) {}
    const byte* data() const { return m_data; }
    size_t size() const { return m_size; }

private:
    const byte* m_data;
    size_t m_size;
};

class SnappyCompress {
public:
    static void uncompress(const bytesConstRef& input, std::vector<byte>& output);
};

class P2PMessage {
public:
    static const size_t MAX_MESSAGE_LENGTH = 1024 * 1024;
};

class Logger {
public:
    Logger& operator<<(const char*) { return *this; }
    Logger& operator<<(uint32_t) { return *this; }
};

Logger WARNING;
#define SESSION_LOG(level) level
#define LOG_DESC(x) x
#define LOG_KV(k, v) v

class BCOSConfig {
public:
    static bool compressEnabled() { return false; }
};

BCOSConfig g_BCOSConfig;

class P2PMessageRC2 {
public:
    size_t m_deliveredLength;
    uint32_t m_length;
    uint16_t m_version;
    uint32_t m_protocolID;
    uint16_t m_packetType;
    uint32_t m_seq;
    std::vector<byte>* m_cache;
    std::vector<byte>* m_buffer;
    
    ssize_t decode(const byte* buffer, size_t size);
};