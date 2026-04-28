#include <memory>
#include <string>

class MemmappedTensorAllocator;
class Env;
class Status;

enum DataType {
  DT_STRING
};

class TensorShape {};

class Tensor {
public:
  Tensor(MemmappedTensorAllocator* allocator, DataType dtype, const TensorShape& shape);
};

class MemmappedTensorAllocator {
public:
  bool InitializeFromRegion(const std::string& region_name, const Env& env);
  Status allocation_status();
  void set_delete_on_deallocate();
};

class OpKernelContext {
public:
  const Env& env() const;
  void set_output(int index, const Tensor& tensor);
};

class errors {
public:
  static Status Unimplemented(const std::string& message);
};

#define OP_REQUIRES(ctx, condition, ...)
#define OP_REQUIRES_OK(ctx, status)

class ImmutableConstantOp {
public:
  void Compute(OpKernelContext* ctx);
private:
  std::string region_name_;
  DataType dtype_;
  TensorShape shape_;
};