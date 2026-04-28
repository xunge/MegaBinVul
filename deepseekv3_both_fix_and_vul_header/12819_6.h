#include <arpa/inet.h>
#include <sys/types.h>
#include <cstdint>
#include <vector>
#include <iostream>

#define HEADER_LENGTH 8
#define MAX_MESSAGE_LENGTH (1024 * 1024 * 10)

typedef uint8_t byte;
typedef uint16_t PROTOCOL_ID;
typedef uint16_t PACKET_TYPE;

namespace dev {
namespace network {
    const ssize_t PACKET_INCOMPLETE = -1;
    const ssize_t PACKET_ERROR = -2;
}
}

class P2PMessage {
public:
    uint32_t m_length;
    PROTOCOL_ID m_protocolID;
    PACKET_TYPE m_packetType;
    uint32_t m_seq;
    std::vector<byte>* m_buffer;
    
    ssize_t decode(const byte* buffer, size_t size);
};

#define SESSION_LOG(level) if (false) std::cout
#define LOG_DESC(desc) desc
#define LOG_KV(key, value) key << "=" << value