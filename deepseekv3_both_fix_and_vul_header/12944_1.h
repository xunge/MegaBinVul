#include <stdbool.h>

struct Parent {
    struct {
        bool remote_decode_complete_;
    } state_;
    bool remoteDecodeComplete();
};

struct ActiveStreamDecoderFilter {
    Parent parent_;
    bool complete();
};