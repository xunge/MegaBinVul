#include <vector>
#include <cstdint>
#include <string>
#include <sstream>

using int32 = int32_t;
using int64 = int64_t;

enum class Padding {
  EXPLICIT
};

enum class TensorFormat {
  FORMAT_NCHW_VECT_C
};
constexpr TensorFormat FORMAT_NCHW_VECT_C = TensorFormat::FORMAT_NCHW_VECT_C;

class TensorShape {
public:
  int dims() const { return 0; }
};

class Status {
public:
  bool ok() const { return true; }
  static Status OK() { return Status(); }
};

class errors {
public:
  static Status InvalidArgument(const std::string& message) { 
    return Status(); 
  }
  static Status InvalidArgument(const char* msg, int dims, const char* sep, TensorFormat format) {
    std::ostringstream oss;
    oss << msg << dims << sep << static_cast<int>(format);
    return Status();
  }
  static Status Unimplemented(const std::string& message) { 
    return Status(); 
  }
};

class DeviceType {
public:
  explicit DeviceType(int type) {}
  bool operator==(const DeviceType& other) const { return true; }
};

static const DeviceType DEVICE_CPU(0);

class Device {
public:
  struct Attributes {
    int device_type() const { return 0; }
  };
  const Attributes& attributes() const { static Attributes a; return a; }
};

class OpKernelContext {
public:
  Device* device() { return nullptr; }
  void CtxFailure(const char* file, int line, const Status& status) {}
};

#define OP_REQUIRES(CTX, COND, STATUS) \
  do { if (!(COND)) { (CTX)->CtxFailure(__FILE__, __LINE__, (STATUS)); return; } } while (0)

#define OP_REQUIRES_OK(CTX, STATUS) \
  do { if (!(STATUS).ok()) { (CTX)->CtxFailure(__FILE__, __LINE__, (STATUS)); return; } } while (0)

struct PoolParameters {
  TensorFormat data_format;
  int depth;
  int tensor_in_cols;
  int tensor_in_rows;
  int tensor_in_batch;
  int window_rows;
  int window_cols;
  int depth_window;
  int row_stride;
  int col_stride;
  int depth_stride;
  int pad_top;
  int pad_bottom;
  int pad_left;
  int pad_right;
  int pad_depth;
  int out_height;
  int out_width;
  int out_depth;
  
  PoolParameters(OpKernelContext* context,
                const std::vector<int32>& ksize,
                const std::vector<int32>& stride,
                Padding padding,
                std::vector<int64> explicit_paddings,
                TensorFormat data_format,
                const TensorShape& tensor_in_shape);
};

int GetTensorSpatialDims(int dims, TensorFormat data_format) { return 0; }
int GetTensorDim(const TensorShape& shape, TensorFormat data_format, char dim) { return 0; }
int GetTensorDim(const std::vector<int32>& vec, TensorFormat data_format, char dim) { return 0; }
Status CheckValidPadding(Padding padding, const std::vector<int64>& explicit_paddings, int num_dims, TensorFormat data_format) { return Status::OK(); }
void GetExplicitPaddingForDim(const std::vector<int64>& explicit_paddings, TensorFormat data_format, char dim, int* pad_before, int* pad_after) {}
Status CheckPaddingSize(int window_rows, int window_cols, int pad_top, int pad_bottom, int pad_left, int pad_right) { return Status::OK(); }
Status GetWindowedOutputSizeVerbose(int input_size, int filter_size, int stride, Padding padding, int* output_size, int* padding_before, int* padding_after) { return Status::OK(); }