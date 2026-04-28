#include <stdbool.h>

struct FilterManagerState {
    bool remote_encode_complete_;
};

struct FilterManagerCallbacks {
    void endStream();
};

class FilterManager {
public:
    FilterManagerState state_;
    FilterManagerCallbacks filter_manager_callbacks_;
    void maybeEndEncode(bool end_stream);
};

#define ASSERT(expr) ((void)0)