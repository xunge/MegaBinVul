#include <vector>
#include <cstdint>
#include <string>

using int64 = int64_t;

struct Status {
    bool ok;
    static Status OK();
};

struct Tensor;
struct TensorShape;

struct OpInputList {
    size_t size() const;
    Tensor& operator[](int);
    const Tensor& operator[](int) const;
};

struct OpOutputList {
    size_t size() const;
    Status allocate(int, const TensorShape&, Tensor**);
};

struct Tensor {
    template<typename T> T flat();
    template<typename T> T flat() const;
    template<typename T, int N> struct TensorMap {
        void setZero();
    };
    template<typename T, int N> TensorMap<T,N> shaped(const int (&dims)[N]);
    template<typename T, int N> TensorMap<T,N> shaped(const int (&dims)[N]) const;
    int NumElements() const;
    const TensorShape& shape() const;
};

struct TensorShape {};

struct FeatureWeightsSparseStorage {
    FeatureWeightsSparseStorage(int64,
                              const typename Tensor::TensorMap<float,2>&,
                              const typename Tensor::TensorMap<float,2>&);
};

struct FeatureWeightsDenseStorage {
    FeatureWeightsDenseStorage(const typename Tensor::TensorMap<float,2>&,
                             const typename Tensor::TensorMap<float,2>&);
};

namespace errors {
    Status InvalidArgument(const std::string&);
    Status InvalidArgument(const char*, size_t, const char*, size_t);
}

Status TF_RETURN_IF_ERROR(Status status);

class OpKernelContext {
public:
    Status input_list(const char*, OpInputList*);
    Status output_list(const char*, OpOutputList*);
};

class ModelWeights {
    std::vector<FeatureWeightsSparseStorage> sparse_weights_;
    std::vector<FeatureWeightsDenseStorage> dense_weights_;
public:
    Status Initialize(OpKernelContext* context);
};