#include <cstdint>
#include <cstddef>

enum class Status {
    OkStatus,
    InvalidArgument
};

namespace absl {
    template <typename T>
    class Span {
    public:
        Span(const T* data, size_t size) : data_(data), size_(size) {}
        size_t size() const { return size_; }
        const T& operator[](size_t i) const { return data_[i]; }
    private:
        const T* data_;
        size_t size_;
    };
}

inline Status InvalidArgument(const char*, ...) { return Status::InvalidArgument; }
inline Status OkStatus() { return Status::OkStatus; }