#include <limits>
#include <string>
#include <vector>
#include <sstream>

struct Status {
  bool ok() const { return true; }
  static Status OK() { return Status(); }
};

struct errors {
  template<typename... Args>
  static Status InvalidArgument(Args&&... args) {
    std::ostringstream oss;
    (oss << ... << args);
    return Status();
  }
};

namespace strings {
std::string Printf(const char* format, ...);
}

struct OpInputList {
  size_t size() const { return 0; }
};

struct Tensor {
  template <typename T>
  struct Flat {
    T operator()(int) const { return T(); }
    size_t size() const { return 0; }
  };

  template <typename T>
  Flat<T> flat() const { return Flat<T>(); }
};

struct DeviceBase {
  struct CpuWorkerThreads {};
  const CpuWorkerThreads* tensorflow_cpu_worker_threads() const { return nullptr; }
};

struct ModelWeights {};

struct Example {
  std::vector<float> sparse_features_;
  std::vector<float> dense_vectors_;
  float example_weight_;
  float example_label_;
};

struct OpKernelContext {
  Status input_list(const std::string& name, OpInputList* list) { return Status::OK(); }
  Status input(const std::string& name, const Tensor** tensor) { return Status::OK(); }
  const DeviceBase* device() const { return nullptr; }
};

struct Examples {
  std::vector<Example> examples_;
  std::vector<float> probabilities_;
  std::vector<int> sampled_index_;
  std::vector<int> sampled_count_;
  int num_features_;

  Status Initialize(OpKernelContext* context,
                   const ModelWeights& weights,
                   int num_sparse_features,
                   int num_sparse_features_with_values,
                   int num_dense_features);
};

Status CreateSparseFeatureRepresentation(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_sparse_features,
    const ModelWeights& weights,
    const OpInputList& sparse_example_indices_inputs,
    const OpInputList& sparse_feature_indices_inputs,
    const OpInputList& sparse_feature_values_inputs,
    std::vector<Example>* examples) { return Status::OK(); }

Status CreateDenseFeatureRepresentation(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_dense_features,
    const ModelWeights& weights,
    const OpInputList& dense_features_inputs,
    std::vector<Example>* examples) { return Status::OK(); }

Status ComputeSquaredNormPerExample(
    const DeviceBase::CpuWorkerThreads& worker_threads,
    int num_examples,
    int num_sparse_features,
    int num_dense_features,
    std::vector<Example>* examples) { return Status::OK(); }

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    const Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)