#include <stdint.h>
#include <atomic>

namespace base {
namespace subtle {
typedef int32_t Atomic32;
}  // namespace subtle

template <typename T>
class CheckedNumeric {
public:
    explicit CheckedNumeric(T value) : value_(value) {}
    CheckedNumeric(const T& value) : value_(value) {}  // Add constructor for direct type conversion
    bool IsValid() const { return true; }
    T ValueOrDie() const { return value_; }
    CheckedNumeric& operator+=(T value) { value_ += value; return *this; }

private:
    T value_;
};
}  // namespace base

class AsyncPixelTransferCompletionObserverImpl;

class AsyncPixelTransfersCompletedQuery {
public:
    bool End(base::subtle::Atomic32 submit_count);
    uint32_t shm_id() const;
    uint32_t shm_offset() const;
    bool AddToPendingTransferQueue(base::subtle::Atomic32 submit_count);
    class Manager* manager();
    AsyncPixelTransferCompletionObserverImpl* observer_;
};

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

struct QuerySync {};

class AsyncPixelTransferCompletionObserverImpl {
public:
    explicit AsyncPixelTransferCompletionObserverImpl(base::subtle::Atomic32 submit_count);
};

class Manager {
public:
    class Decoder* decoder();
};

class Decoder {
public:
    Buffer GetSharedMemoryBuffer(uint32_t shm_id);
    class AsyncPixelTransferManager* GetAsyncPixelTransferManager();
};

class AsyncPixelTransferManager {
public:
    void AsyncNotifyCompletion(const AsyncMemoryParams& params, AsyncPixelTransferCompletionObserverImpl* observer);
};

typedef uint32_t uint32;