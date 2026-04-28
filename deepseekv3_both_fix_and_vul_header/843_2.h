#include <memory>
#include <vector>

struct HeaderMap {
    void refreshByteSize();
};

struct StreamInfo {
    void setUpstreamTiming(void*);
    void onRequestComplete();
};

struct Tracing {
    struct Span {};
    struct EgressConfig {
        static EgressConfig& get();
    };
    struct HttpTracerUtility {
        static void finalizeUpstreamSpan(Span&, HeaderMap*, HeaderMap*, StreamInfo&, EgressConfig&);
    };
};

struct Timer {
    void disableTimer();
};

struct UpstreamLog {
    void log(HeaderMap*, HeaderMap*, HeaderMap*, StreamInfo&);
};

struct FilterConfig {
    std::vector<std::shared_ptr<UpstreamLog>> upstream_logs_;
};

struct Filter {
    HeaderMap* downstream_headers_;
    FilterConfig config_;
    
    struct UpstreamRequest {
        ~UpstreamRequest();
        void clearRequestEncoder();
        
        std::shared_ptr<HeaderMap> upstream_headers_;
        std::shared_ptr<HeaderMap> upstream_trailers_;
        StreamInfo stream_info_;
        std::shared_ptr<Timer> per_try_timeout_;
        Tracing::Span* span_;
        void* upstream_timing_;
        Filter& parent_;
    };
};