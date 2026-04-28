#include <mutex>
#include <memory>

namespace detail {
class AtFork {
public:
    static void registerHandler(void*, bool(*)(), void(*)(), void(*)());
};
} // namespace detail

template<typename T, typename Tag>
class SingletonThreadLocal {
public:
    static T& get();
};

struct RandomTag {};

class BufferedRandomDevice {
public:
    explicit BufferedRandomDevice(size_t bufferSize);
private:
    size_t bufferSize_;
    std::unique_ptr<unsigned char[]> buffer_;
    unsigned char* ptr_;
    static std::once_flag flag;
};