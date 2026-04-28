#include <cstdint>
#include <stdexcept>
#include <vector>
#include <string>

struct Tensor {
    template <typename T>
    struct FlatVector {
        T& operator()(int64_t idx) { return data[idx]; }
        T& operator[](int64_t idx) { return data[idx]; }
        std::vector<T> data;
    };
    
    template <typename T>
    FlatVector<T> flat() { return FlatVector<T>(); }
    
    int64_t NumElements() const { return 0; }
    int64_t dim_size(int) const { return 0; }
};

struct OpKernelContext {};
using Index = int64_t;

struct errors {
    struct InvalidArgument : public std::invalid_argument {
        InvalidArgument(const std::string& msg1, const std::string& msg2) 
            : std::invalid_argument(msg1 + msg2) {}
    };
};

int batch_dims_;

#define OP_REQUIRES(ctx, condition, error) \
    do { if (!(condition)) throw error; } while (0)