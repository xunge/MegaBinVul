#include <cstdint>
#include <cstdlib>
#include <string>

class Allocator;

enum DataType {
  DT_INVALID
};

struct TensorShape {
  static bool IsValid(const std::string& shape);
  TensorShape(const std::string& shape);
  int64_t num_elements() const;
};

struct TensorProto {
  std::string tensor_shape() const;
  DataType dtype() const;
  std::string tensor_content() const;
};

struct TensorBuffer {
  void* data() const;
};

class Tensor;

struct LogMemory {
  static const int UNKNOWN_STEP_ID;
  static void RecordTensorAllocation(const char* description, int step_id, const Tensor& tensor);
};

#define CHECK_NOTNULL(ptr) ((ptr) ? (ptr) : (abort(), (ptr)))
#define CASES_WITH_DEFAULT(...)

class Tensor {
 public:
  bool FromProto(Allocator* a, const TensorProto& proto);
  void set_dtype(DataType dtype);
  void UnrefIfNonNull(TensorBuffer* buf);
  bool MemoryLoggingEnabled() const;
  TensorBuffer* buf_;
  TensorShape shape_;
};