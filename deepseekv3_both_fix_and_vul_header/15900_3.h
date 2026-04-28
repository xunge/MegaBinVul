typedef void* PyObject;

struct Safe_PyObjectPtr {
    PyObject* ptr;
    PyObject* get() { return ptr; }
};

namespace Eigen {
struct half {
    half(double v);
};
}

template<typename T>
const char* ConvertOneFloat(PyObject* v, T* out);

Safe_PyObjectPtr make_safe(PyObject* obj);
PyObject* PyNumber_Float(PyObject* o);
double PyFloat_AS_DOUBLE(PyObject* o);