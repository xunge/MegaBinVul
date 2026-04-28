#include <string>

typedef enum {
    TF_QUINT8,
    TF_QINT8,
    TF_QINT16,
    TF_QUINT16,
    TF_QINT32,
    TF_RESOURCE
} TF_DataType;

typedef void PyObject;
typedef long Py_ssize_t;

struct PyArray_Descr {
    PyObject* fields;
};

class Status {
public:
    static Status OK();
    static Status Internal(const char* msg);
};

class errors {
public:
    static Status Internal(const char* msg);
};

namespace tensorflow {
    using string = std::string;
}

int PyBytes_Check(PyObject*);
const char* PyBytes_AsString(PyObject*);
PyObject* PyUnicode_AsASCIIString(PyObject*);
int PyDict_Next(PyObject*, Py_ssize_t*, PyObject**, PyObject**);