#include <set>
#include <cstddef>

class MidiManagerClient {
public:
    void AccumulateMidiBytesSent(size_t n);
};

namespace base {
class AutoLock {
public:
    AutoLock(void* lock) {}
};
}

class MidiManager {
public:
    void AccumulateMidiBytesSent(MidiManagerClient* client, size_t n);
protected:
    void* lock_;
    std::set<MidiManagerClient*> clients_;
};