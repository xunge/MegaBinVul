#include <memory>
#include <vector>
#include <cassert>

namespace ConnectionManagerImpl {

struct StreamInfo {
    enum ResponseFlag {
        DownstreamConnectionTermination
    };
    
    void onRequestComplete();
    bool hasAnyResponseFlag() const;
    int responseCode() const;
    void setResponseFlag(ResponseFlag flag);
    bool healthCheck() const;
};

struct Headers {
    void refreshByteSize();
};

struct AccessLog {
    struct Instance {
        void log(Headers* request, 
                Headers* response,
                Headers* trailers,
                StreamInfo& info);
    };
    using InstanceSharedPtr = std::shared_ptr<Instance>;
};

struct Tracing {
    struct HttpTracerUtility {
        static void finalizeDownstreamSpan(int& span, 
                                         Headers* request,
                                         Headers* response,
                                         Headers* trailers,
                                         StreamInfo& info,
                                         class ActiveStream& stream);
    };
};

struct Stats {
    struct Named {
        struct Counter {
            void dec();
        };
        Counter downstream_rq_active_;
        Counter downstream_cx_upgrades_active_;
    } named_;
};

struct Config {
    struct TracingStats {
        struct Counter {
            void inc();
        };
        Counter health_check_;
    };
    
    TracingStats& tracingStats();
    std::vector<AccessLog::InstanceSharedPtr> accessLogs();
};

struct ConnectionManager {
    Stats stats_;
    Config config_;
};

class ActiveStream {
public:
    ~ActiveStream();
    
    struct State {
        bool successful_upgrade_;
        int filter_call_state_;
    };

    StreamInfo stream_info_;
    ConnectionManager connection_manager_;
    std::shared_ptr<Headers> request_headers_;
    std::shared_ptr<Headers> response_headers_;
    std::shared_ptr<Headers> response_trailers_;
    std::vector<AccessLog::InstanceSharedPtr> access_log_handlers_;
    int* active_span_;
    State state_;
};

#define ASSERT(x) assert(x)

}