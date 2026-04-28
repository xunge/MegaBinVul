#include <memory>
#include <cstddef>

namespace Buffer {
class Instance {
public:
    size_t length() const;
    void move(Instance&);
};

class OwnedImpl : public Instance {
};
} // namespace Buffer

namespace ConnectionManagerImpl {
class ActiveStream {
public:
    void decodeData(Buffer::Instance&, bool);

    struct ScopeTrackerScopeState {
        ScopeTrackerScopeState(ActiveStream*, void*);
    };

    struct State {
        bool deferred_to_next_io_iteration_;
        bool deferred_end_stream_;
    };

    struct ConnectionManager {
        struct ReadCallbacks {
            struct Connection {
                void* dispatcher();
            };
            Connection& connection();
        };
        ReadCallbacks* read_callbacks_;
    };

    struct FilterManager {
        struct StreamInfo {
            void addBytesReceived(size_t);
        };
        void decodeData(Buffer::Instance&, bool);
        StreamInfo& streamInfo();
    };

private:
    ConnectionManager connection_manager_;
    FilterManager filter_manager_;
    State state_;
    std::unique_ptr<Buffer::OwnedImpl> deferred_data_;

    void maybeEndDecode(bool);
};
} // namespace ConnectionManagerImpl