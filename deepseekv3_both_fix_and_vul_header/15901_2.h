#include <vector>
#include <string>

typedef void* PyObject;

enum DataType {
  DT_INVALID,
  DT_FLOAT,
  DT_DOUBLE,
  DT_HALF,
  DT_INT32,
  DT_INT64,
  DT_UINT64,
  DT_COMPLEX128,
  DT_STRING,
  DT_BOOL
};

struct ConverterState {
  DataType inferred_dtype;
  std::vector<int64_t> inferred_shape;
};

class Tensor {
public:
  Tensor(DataType dtype, const std::vector<int64_t>& shape) {}
};

class Status {
public:
  static Status OK() { return Status(); }
};

#define TF_RETURN_IF_ERROR(expr) do { Status _status = (expr); } while(0)
#define RETURN_STRING_AS_STATUS(expr) return Status()

const char* ErrorFoundInt64 = "";
const char* ErrorFoundFloat = "";

namespace errors {
Status Unimplemented(const char* msg, const char* dtype_str) { return Status(); }
}

namespace {
class FloatConverter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class DoubleConverter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class NumpyHalfConverter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class Int32Converter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class Int64Converter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class UInt64Converter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class Complex128Converter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class StringConverter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};
class BoolConverter {
public:
  static const char* Convert(PyObject*, ConverterState*, Tensor*) { return nullptr; }
};

Status InferShapeAndType(PyObject*, ConverterState*) { return Status::OK(); }
const char* DataTypeString(DataType) { return ""; }
}