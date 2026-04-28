#include <cstdint>

enum class Protocol { Http10, Http11, Http2 };
enum class StreamResetReason { ConnectError, ProtocolError, LocalReset };
enum class DrainState { Closing };
enum class LogLevel { debug };

#define ENVOY_STREAM_LOG(level, message, stream) 

struct StreamInfo {
    enum ResponseFlag {
        UpstreamConnectionFailure,
        UpstreamConnectionTermination,
        UpstreamProtocolError
    };
    bool hasResponseFlag(ResponseFlag flag) const { return false; }
};

struct Headers {
    bool ContentLength() const { return false; }
};

struct FilterManager {
    bool remoteDecodeComplete() const { return false; }
    bool remoteComplete() const { return false; }
    void setLocalComplete() {}
    StreamInfo& streamInfo() { return stream_info_; }
    StreamInfo stream_info_;
};

struct StreamState {
    bool codec_saw_local_complete_;
    bool saw_connection_close_;
};

struct Stream {
    void resetStream(StreamResetReason reason) {}
};

struct ResponseEncoder {
    Stream& getStream() { return stream_; }
    Stream stream_;
};

struct Codec {
    Protocol protocol() { return Protocol::Http2; }
};

struct ActiveStream {
    ResponseEncoder* response_encoder_;
    Headers* request_headers_;
    Headers* response_headers_;
    FilterManager filter_manager_;
    StreamState state_;
};

class ConnectionManagerImpl {
public:
    void doEndStream(ActiveStream& stream);
    void doDeferredStreamDestroy(ActiveStream& stream) {}
    void checkForDeferredClose(bool close) {}
    bool requestWasConnect(Headers* headers, Protocol protocol) { return false; }
    Codec* codec_;
    DrainState drain_state_;
};