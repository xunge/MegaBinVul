#include <memory>
#include <utility>

struct RequestTrailerMap {
    // Forward declaration only
};
using RequestTrailerMapPtr = std::unique_ptr<RequestTrailerMap>;

class ScopeTrackerScopeState {
public:
    ScopeTrackerScopeState(void*, void*);
};

#define ENVOY_STREAM_LOG(level, msg, stream, trailers) \
    do { (void)level; (void)msg; (void)stream; (void)trailers; } while(0)

#define ASSERT(expr) ((void)0)

struct ConnectionManagerReadCallbacks {
    struct Connection {
        void* dispatcher();
    };
    Connection connection();
};

struct ConnectionManagerImpl {
    struct ActiveStream {
        void decodeTrailers(RequestTrailerMapPtr&&);
        void resetIdleTimer();
        bool validateTrailers();
        void maybeEndDecode(bool);
        
        RequestTrailerMapPtr request_trailers_;
        struct {
            bool deferred_to_next_io_iteration_;
        } state_;
        struct {
            void decodeTrailers(RequestTrailerMap&);
        } filter_manager_;
        struct {
            ConnectionManagerReadCallbacks* read_callbacks_;
        } connection_manager_;
    };
};

constexpr int debug = 0;