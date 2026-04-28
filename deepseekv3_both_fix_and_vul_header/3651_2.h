#include <stddef.h>
#include <stdint.h>
#include <vector>

class SpdyWriteQueue {
public:
    SpdyWriteQueue();
    SpdyWriteQueue(bool removing_writes);
private:
    bool removing_writes_;
};