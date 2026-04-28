#include <stdbool.h>

struct State {
    bool remote_complete_;
    bool remote_decode_complete_;
};

struct Parent {
    State state_;
};

class ActiveStreamDecoderFilter {
private:
    Parent parent_;
public:
    bool complete();
};