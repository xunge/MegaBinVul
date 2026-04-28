#include <cstdint>
#include <limits>
#include <string>
#include <vector>
#include <sstream>

using int64 = int64_t;

enum class Padding {
  EXPLICIT
};

enum class DataFormat {
  NHWC
};

struct Status {
  static Status OK();
  bool ok() const;
  Status& operator=(const Status& x);
};

struct errors {
  struct InvalidArgument {
    InvalidArgument(const char* msg);
    InvalidArgument(const char* msg, const std::string& str);
    InvalidArgument(const char* msg, int a, int b);
    InvalidArgument(const char* msg, int a);
    InvalidArgument(const char* msg, int a, const char* sep, int b);
    operator Status() const;
  };
};

#define TF_REQUIRES(condition, error) \
  if (!(condition)) return (error)

#define TF_RETURN_IF_ERROR(expr) \
  do { \
    Status _status = (expr); \
    if (!_status.ok()) return _status; \
  } while (0)

struct Tensor {
  int dims() const;
  int dim_size(int i) const;
  struct Shape {
    std::string DebugString() const;
  };
  Shape shape() const;
};

struct Conv2DParameters {
  DataFormat data_format;
  Padding padding;
  std::vector<int> strides;
  std::vector<int> dilations;
  std::vector<int64_t> explicit_paddings;
};

struct Conv2DDimensions {
  int batch;
  int input_rows;
  int input_cols;
  int in_depth;
  int filter_rows;
  int filter_cols;
  int patch_depth;
  int out_depth;
  int stride_rows;
  int stride_cols;
  int dilation_rows;
  int dilation_cols;
  int64_t out_rows;
  int64_t out_cols;
  int64_t pad_rows_before;
  int64_t pad_rows_after;
  int64_t pad_cols_before;
  int64_t pad_cols_after;
};

template <typename T, typename U>
bool FastBoundsCheck(T x, U upper) {
  return x < upper;
}

int64_t GetTensorDim(const Tensor& tensor, DataFormat data_format, char dimension);
int GetTensorDim(const std::vector<int>& vec, DataFormat data_format, char dimension);
Status GetWindowedOutputSizeVerboseV2(int64_t input_size, int64_t filter_size,
                                     int64_t dilation_rate, int64_t stride,
                                     Padding padding_type,
                                     int64_t* output_size,
                                     int64_t* padding_before,
                                     int64_t* padding_after);
void GetExplicitPaddingForDim(const std::vector<int64_t>& explicit_paddings,
                             DataFormat data_format, char dimension,
                             int64_t* padding_before, int64_t* padding_after);