#include <limits>
#include <vector>
#include <string>
#include <cstddef>

struct Status {
    bool ok() const;
    static Status OK();
};

struct OpInputList {
    size_t size() const;
};

struct Tensor {
    template <typename T>
    struct Flat {
        size_t size() const;
        T operator()(int index) const;
    };
    
    template <typename T>
    Flat<T> flat() const;
};

struct DeviceBase {
    struct CpuWorkerThreads {};
    const CpuWorkerThreads* tensorflow_cpu_worker_threads() const;
};

struct OpKernelContext {
    Status input(const char* name, const Tensor** tensor);
    Status input_list(const char* name, OpInputList* list);
    DeviceBase* device();
};

struct ModelWeights {};

struct Example {
    std::vector<float> sparse_features_;
    std::vector<float> dense_vectors_;
    float example_weight_;
    float example_label_;
};

namespace errors {
    Status InvalidArgument(const std::string& message);
    Status InvalidArgument(const char* msg1, int num1, const char* msg2, size_t num2);
}

namespace strings {
    std::string Printf(const char* format, ...);
}

Status CreateSparseFeatureRepresentation(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_sparse_features,
    const ModelWeights& weights,
    const OpInputList& sparse_example_indices_inputs,
    const OpInputList& sparse_feature_indices_inputs,
    const OpInputList& sparse_feature_values_inputs,
    std::vector<Example>* examples);

Status CreateDenseFeatureRepresentation(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_dense_features,
    const ModelWeights& weights,
    const OpInputList& dense_features_inputs,
    std::vector<Example>* examples);

Status ComputeSquaredNormPerExample(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_sparse_features,
    int num_dense_features,
    std::vector<Example>* examples);

#define TF_RETURN_IF_ERROR(expr) \
    do { \
        const Status _status = (expr); \
        if (!_status.ok()) return _status; \
    } while (0)

class Examples {
public:
    Status Initialize(OpKernelContext* const context,
                    const ModelWeights& weights,
                    int num_sparse_features,
                    int num_sparse_features_with_values,
                    int num_dense_features);

private:
    std::vector<Example> examples_;
    std::vector<float> probabilities_;
    std::vector<int> sampled_index_;
    std::vector<int> sampled_count_;
    int num_features_;
};