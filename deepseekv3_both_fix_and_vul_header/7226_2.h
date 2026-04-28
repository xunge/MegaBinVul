#include <cassert>
#include <iostream>

#define ASSERT(x) assert(x)
#define ENVOY_STREAM_LOG(level, msg, this_obj) std::cout << msg << std::endl
#define debug 0

struct TimeSource {};
struct Dispatcher {
    TimeSource timeSource();
};
struct DownstreamTiming {
    void onLastDownstreamRxByteReceived(TimeSource);
};
struct StreamInfo {
    DownstreamTiming& downstreamTiming();
};
struct FilterManagerState {
    bool remote_decode_complete_;
    bool remote_complete_;
};
class FilterManager {
protected:
    FilterManagerState state_;
    StreamInfo stream_info_;
    Dispatcher& dispatcher();
public:
    void maybeEndDecode(bool end_stream);
};