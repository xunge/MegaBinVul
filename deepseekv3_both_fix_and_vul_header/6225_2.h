#include <vector>
#include <cstdint>
#include <string>

enum class RowPartitionType {
  FIRST_DIM_SIZE,
  VALUE_ROWIDS,
  ROW_SPLITS
};

class Status {
public:
  static Status OK();
};

class Tensor {
public:
  template<typename T>
  struct Scalar {
    T operator()() const;
  };
  template<typename T>
  Scalar<T> scalar() const;
  class Shape {
  public:
    int dim_size(int) const;
  };
  Shape shape() const;
};

class OpKernelContext {
public:
  Tensor input(int) const;
};

constexpr int kFirstPartitionInputIndex = 0;
extern std::vector<RowPartitionType> row_partition_types_;

using INDEX_TYPE = int32_t;

class errors {
public:
  static Status InvalidArgument(const char*);
  static Status InvalidArgument(const char*, const char*);
};

const char* RowPartitionTypeToString(RowPartitionType);