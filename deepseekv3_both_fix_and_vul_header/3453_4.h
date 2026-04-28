#include <stdint.h>
#include <stdbool.h>

typedef int32_t Atomic32;

namespace base {
namespace subtle {
typedef Atomic32 Atomic32;
}
}

struct AsyncMemoryParams {
    void* shared_memory;
    uint32_t shm_size;
    uint32_t shm_data_offset;
    uint32_t shm_data_size;
};

struct Buffer {
    void* shared_memory;
    uint32_t size;
};

class QuerySync {};

class Decoder {
public:
    Buffer GetSharedMemoryBuffer(uint32_t shm_id);
    class AsyncPixelTransferManager* GetAsyncPixelTransferManager();
};

class AsyncPixelTransferManager {
public:
    void AsyncNotifyCompletion(AsyncMemoryParams params, void* observer);
};

class AsyncPixelTransferCompletionObserverImpl {
public:
    AsyncPixelTransferCompletionObserverImpl(Atomic32 submit_count) {}
};

class Manager {
public:
    Decoder* decoder();
};

class AsyncPixelTransfersCompletedQuery {
public:
    bool End(Atomic32 submit_count);
    Manager* manager();
    uint32_t shm_id();
    uint32_t shm_offset();
    bool AddToPendingTransferQueue(Atomic32 submit_count);
    AsyncPixelTransferCompletionObserverImpl* observer_;
};

typedef uint32_t uint32;