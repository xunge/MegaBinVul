#include <cmath>
#include <cstdint>
#include <string>

using int64 = int64_t;
using std::isfinite;

struct Status {
    static Status OK();
};

template<typename T, int N>
struct TensorData {
    T operator()(int64 i, int64 j) const;
};

struct Tensor {
    int NumElements() const;
    int dims() const;
    int dim_size(int) const;
    template<typename T, int N> TensorData<T,N> tensor() const;
    struct Shape {
        std::string DebugString() const;
    };
    Shape shape() const;
};

struct errors {
    static Status InvalidArgument(const char*);
    static Status InvalidArgument(const char*, const std::string&);
    static Status InvalidArgument(const char*, int64_t, const char*,
                                 float, const char*, float, const char*,
                                 float, const char*, float);
};