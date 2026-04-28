#include <stdbool.h>

typedef struct {
    bool remote_decode_complete_;
} State;

typedef struct {
    void (*onLastDownstreamRxByteReceived)(void*);
} DownstreamTiming;

typedef struct {
    DownstreamTiming downstreamTiming();
} StreamInfo;

typedef struct {
    void* timeSource();
} Dispatcher;

typedef struct FilterManager {
    State state_;
    StreamInfo stream_info_;
    Dispatcher dispatcher();
    bool remoteDecodeComplete();
    void maybeEndDecode(bool end_stream);
} FilterManager;

#define ENVOY_STREAM_LOG(level, message, filter_manager)
#define ASSERT(condition)