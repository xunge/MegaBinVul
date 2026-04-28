#include <memory>
#include <string>

namespace Envoy {
namespace Http {

class RequestHeaderMap {
public:
    const char* Method() const;
    const char* Path() const;
};

enum class FilterHeadersStatus {
    Continue,
    StopIteration
};

enum class Code {
    BadRequest
};

}  // namespace Http

namespace Tracing {
class Span;
}  // namespace Tracing

namespace StreamInfo {
class FilterState;
}  // namespace StreamInfo

}  // namespace Envoy

namespace utils {
extern const char kRcDetailFilterServiceControl[];
extern const char kRcDetailErrorTypeBadRequest[];
extern const char kRcDetailErrorMissingMethod[];
extern const char kRcDetailErrorMissingPath[];

std::string generateRcDetails(const char* filter, const char* error_type, const char* error_detail);
bool handleHttpMethodOverride(Envoy::Http::RequestHeaderMap& headers);
}  // namespace utils

#define ENVOY_LOG(level, ...)

class ServiceControlFilter {
public:
    enum State {
        Calling,
        Complete
    };

    Envoy::Http::FilterHeadersStatus decodeHeaders(Envoy::Http::RequestHeaderMap& headers, bool);
    void rejectRequest(Envoy::Http::Code code, const std::string& message, const std::string& rc_details);
    
private:
    State state_;
    bool stopped_;
    struct Handler {
        void fillFilterState(Envoy::StreamInfo::FilterState& filter_state);
        void callCheck(Envoy::Http::RequestHeaderMap& headers, Envoy::Tracing::Span& parent_span, ServiceControlFilter& filter);
    };
    std::unique_ptr<Handler> handler_;
    
    struct Factory {
        std::unique_ptr<Handler> createHandler(Envoy::Http::RequestHeaderMap& headers, void* decoder_callbacks, void* stats);
    };
    Factory factory_;
    
    struct DecoderCallbacks {
        struct DownstreamCallbacks {
            void clearRouteCache();
        };
        DownstreamCallbacks* downstreamCallbacks();
        void* route();
        struct StreamInfo {
            Envoy::StreamInfo::FilterState* filterState();
        };
        StreamInfo& streamInfo();
        Envoy::Tracing::Span& activeSpan();
    };
    DecoderCallbacks* decoder_callbacks_;
    
    void* stats_;
};