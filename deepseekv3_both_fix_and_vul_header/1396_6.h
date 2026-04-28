#include <cstdint>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <memory>
#include <iostream>

#define MSG_ACK 1
#define MSG_SET_CHUNK 2
#define MSG_USER_CONTROL 3
#define MSG_WIN_SIZE 4
#define MSG_SET_PEER_BW 5
#define MSG_AGGREGATE 6

#define CONTROL_PING_REQUEST 1
#define CONTROL_PING_RESPONSE 2
#define CONTROL_STREAM_BEGIN 3
#define CONTROL_STREAM_EOF 4
#define CONTROL_STREAM_DRY 5

struct RtmpPacket {
    using Ptr = std::shared_ptr<RtmpPacket>;
    static Ptr create();
    
    uint8_t type_id;
    uint32_t time_stamp;
    uint32_t stream_index;
    uint32_t chunk_id;
    uint32_t body_size;
    std::string buffer;
};

class RtmpProtocol {
private:
    uint32_t _chunk_size_in;
    uint32_t _windows_size;
    uint32_t _bandwidth;
    uint8_t _band_limit_type;
    
public:
    void handle_chunk(RtmpPacket::Ptr packet);
    void sendUserControl(uint16_t type, uint32_t data);
    void onStreamBegin(uint32_t stream_index);
    void onStreamEof(uint32_t stream_index);
    void onStreamDry(uint32_t stream_index);
    void onRtmpChunk(RtmpPacket::Ptr packet);
};

inline uint32_t load_be32(const char* data) {
    return (static_cast<uint32_t>(static_cast<uint8_t>(data[0])) << 24) |
           (static_cast<uint32_t>(static_cast<uint8_t>(data[1])) << 16) |
           (static_cast<uint32_t>(static_cast<uint8_t>(data[2])) << 8) |
           static_cast<uint32_t>(static_cast<uint8_t>(data[3]));
}

inline uint16_t load_be16(const char* data) {
    return (static_cast<uint16_t>(static_cast<uint8_t>(data[0])) << 8) |
           static_cast<uint16_t>(static_cast<uint8_t>(data[1]));
}

inline uint32_t load_be24(const uint8_t* data) {
    return (static_cast<uint32_t>(data[0]) << 16) |
           (static_cast<uint32_t>(data[1]) << 8) |
           static_cast<uint32_t>(data[2]);
}

#define TraceL std::cout
#define WarnL std::cerr