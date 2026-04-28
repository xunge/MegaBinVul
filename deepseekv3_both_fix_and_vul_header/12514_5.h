#include <cstddef>
#include <cstdint>
#include <string>

using int64 = int64_t;

enum DataType {
  DT_INVALID,
  DT_INT64,
  DT_STRING
};

class Status {
public:
  static Status OK();
};

class Tensor;
class TensorShape;

template<typename T>
class TensorVec {
public:
  size_t size() const;
  T operator()(int i) const;
};

class Tensor {
public:
  DataType dtype() const;
  const TensorShape& shape() const;
  template<typename T> const TensorVec<T>& vec() const;
  int dim_size(int dim) const;
};

class TensorShape {
public:
  std::string DebugString() const;
  int dim_size(int dim) const;
};

class OpInputList {
public:
  size_t size() const;
  const Tensor& operator[](int i) const;
};

namespace TensorShapeUtils {
  bool IsMatrix(const TensorShape& shape);
  bool IsVector(const TensorShape& shape);
};

namespace errors {
  Status InvalidArgument(const char* msg);
  Status InvalidArgument(const char* msg, int arg1);
  Status InvalidArgument(const char* msg, int arg1, int arg2);
  Status InvalidArgument(const char* msg, DataType arg1);
  Status InvalidArgument(const char* msg, DataType arg1, DataType arg2);
  Status InvalidArgument(const char* msg, const std::string& arg1);
  Status InvalidArgument(const char* msg, int arg1, const std::string& arg2);
  Status InvalidArgument(const char* msg, const std::string& arg1, int arg2);
  Status InvalidArgument(const char* msg, int arg1, const std::string& arg2, int arg3);
  Status InvalidArgument(const char* msg, const std::string& arg1, const char* arg2, int arg3);
  Status InvalidArgument(const char* msg, DataType arg1, const char* arg2, DataType arg3);
  Status InvalidArgument(const char* msg, int arg1, const char* arg2, int arg3, const char* arg4, int arg5);
};

int64_t CalculateBatchSize(const OpInputList& shapes_list_in, const OpInputList& dense_list_in);