#include <vector>
#include <deque>
#include <cassert>

#define CHECK assert
#define MINIMUM_PRIORITY 0
#define MAXIMUM_PRIORITY 7

class SpdyWriteQueue {
public:
    void Clear();
private:
    bool removing_writes_;
    struct SpdyBufferProducer {};
    struct PendingWrite {
        SpdyBufferProducer* frame_producer;
    };
    std::deque<PendingWrite> queue_[MAXIMUM_PRIORITY + 1];
};

template<typename T>
void STLDeleteElements(std::vector<T*>* container) {
    for (auto ptr : *container) {
        delete ptr;
    }
    container->clear();
}