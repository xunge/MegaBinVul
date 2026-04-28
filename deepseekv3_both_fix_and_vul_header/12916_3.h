#include <string>
#include <vector>

struct PyObject {};
struct PyArrayObject {};
struct Tensor {};
struct Device {
  std::string name() const { return ""; }
};

class Status {
 public:
  bool ok() const { return true; }
  static Status Internal(const char* msg) { return Status(); }
};

Status OkStatus() { return Status(); }

bool IsCPUDevice(const Device* device) { return true; }

PyObject* PyList_New(int64_t size) { return nullptr; }
void Py_DECREF(PyObject* obj) {}
void PyList_SetItem(PyObject* list, int64_t index, PyObject* item) {}
PyObject* Py_BuildValue(const char* format, ...) { return nullptr; }
PyObject* EagerTensorFromHandle(void* handle) { return nullptr; }
PyObject* PyArray_Return(PyArrayObject* obj) { return nullptr; }
Status TensorToNdarray(const Tensor& t, PyObject** arg) { return OkStatus(); }

struct TFE_Context {
  void* CreateLocalHandleFromTFTensor(const Tensor& t, const char* device_name) { return nullptr; }
};

namespace tensorflow {
void* wrap(void* ptr) { return ptr; }
TFE_Context* unwrap(TFE_Context* ctx) { return ctx; }
}

struct PyCall {
  std::vector<Tensor> ins;
  const Device* device;
  bool eager;
  std::string token;
};

namespace errors {
Status Internal(const char* msg) { return Status(); }
}

#define CHECK(expr) (void)(expr)