#include <cstddef>

struct Status {
    static Status OK();
    Status(const Status&);
    Status(const char*);
};

namespace errors {
    const char* InvalidArgument(const char*);
}

template<typename T>
struct Flat {
    T operator()(std::size_t) const;
    std::size_t dimension(std::size_t) const;
};

struct Tensor {
    int NumElements() const;
    template<typename T>
    Flat<T> flat() const;
};