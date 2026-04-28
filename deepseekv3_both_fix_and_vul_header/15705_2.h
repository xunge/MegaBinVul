#include <cstdint>
#include <memory>
#include <optional>
#include <vector>
#include <string>

namespace Address {
class Instance;
}

namespace Network {

class ListenerFilterBuffer {
public:
    struct RawSlice {
        void* mem_;
    };
    RawSlice rawSlice() const;
    bool drain(size_t length);
};

class ConnectionSocket {
public:
    class ConnectionInfoProvider {
    public:
        const std::shared_ptr<Address::Instance>& remoteAddress() const;
        const std::shared_ptr<Address::Instance>& localAddress() const;
        void restoreLocalAddress(const std::shared_ptr<Address::Instance>& address);
        void setRemoteAddress(const std::shared_ptr<Address::Instance>& address);
    };
    ConnectionInfoProvider& connectionInfoProvider();
};

struct TLV {};

struct ProxyProtocolData {
    std::shared_ptr<Address::Instance> remote_address_;
    std::shared_ptr<Address::Instance> local_address_;
    std::vector<TLV> parsed_tlvs_;
};

class ProxyProtocolFilterState {
public:
    explicit ProxyProtocolFilterState(ProxyProtocolData data);
    static const char* key();
};

struct ProxyProtocolHeader {
    size_t wholeHeaderLength() const;
    size_t headerLengthWithoutExtension() const;
    size_t extensions_length_;
    bool local_command_;
    std::shared_ptr<Address::Instance> remote_address_;
    std::shared_ptr<Address::Instance> local_address_;
    int protocol_version_;
};

} // namespace Network

namespace StreamInfo {
class FilterState {
public:
    enum class StateType { Mutable };
    enum class LifeSpan { Connection };
    template<typename T> bool hasData(const std::string&) const;
    void setData(const std::string&, std::unique_ptr<Network::ProxyProtocolFilterState>, StateType, LifeSpan);
};
} // namespace StreamInfo

namespace Envoy {
namespace Hex {
std::string encode(const uint8_t* data, size_t length);
} // namespace Hex
} // namespace Envoy

namespace Address {
class Instance {
public:
    class Ip {
    public:
        int version() const;
        bool isUnicastAddress() const;
    };
    Ip* ip() const;
    bool operator!=(const Instance&) const;
};
} // namespace Address

enum class ReadOrParseState {
    Done,
    TryAgainLater,
    Error
};

class Filter {
private:
    std::optional<Network::ProxyProtocolHeader> proxy_protocol_header_;
    size_t max_proxy_protocol_len_;
    std::vector<Network::TLV> parsed_tlvs_;
    struct Callbacks {
        Network::ConnectionSocket& socket();
        StreamInfo::FilterState& filterState();
    }* cb_;

    ReadOrParseState readProxyHeader(Network::ListenerFilterBuffer& buffer);
    ReadOrParseState readExtensions(Network::ListenerFilterBuffer& buffer);
public:
    ReadOrParseState parseBuffer(Network::ListenerFilterBuffer& buffer);
};

#define ENVOY_LOG(level, ...)
#define trace 0
#define debug 1