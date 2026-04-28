#include <vector>
#include <string>
#include <sys/uio.h>
#include <cstdint>

using int64 = int64_t;

enum DataType {
    DT_FLOAT,
    DT_DOUBLE,
    DT_INT32,
    DT_UINT8,
    DT_INT16,
    DT_INT8,
    DT_STRING,
    DT_COMPLEX64,
    DT_INT64,
    DT_BOOL,
    DT_QINT8,
    DT_QUINT8,
    DT_QINT32,
    DT_BFLOAT16,
    DT_QINT16,
    DT_QUINT16,
    DT_UINT16,
    DT_COMPLEX128,
    DT_HALF,
    DT_RESOURCE,
    DT_VARIANT,
    DT_UINT32,
    DT_UINT64
};

struct TensorShape {
    TensorShape() = default;
    explicit TensorShape(const std::vector<int64>& dim_sizes);
};

struct TensorProto {
    bool ParseFromString(const std::string& str);
};

struct CompressedComponentMetadata {
    DataType dtype() const;
    TensorShape tensor_shape() const;
    int tensor_size_bytes() const;
};

struct CompressedElement {
    int component_metadata_size() const;
    const CompressedComponentMetadata& component_metadata(int) const;
    const std::string& data() const;
};

class Tensor {
public:
    Tensor() = default;
    Tensor(DataType dtype, const TensorShape& shape);
    bool FromProto(const TensorProto& proto);
};

class TensorBuffer {
public:
    void* data() const;
    size_t size() const;
};

class DMAHelper {
public:
    static TensorBuffer* buffer(Tensor* tensor);
};

class tstring : public std::string {
public:
    using std::string::string;
    void resize_uninitialized(size_t size);
    char* mdata() { return &(*this)[0]; }
    size_t size() const { return std::string::size(); }
};

class Status {
public:
    static Status OK();
    static Status Internal(const std::string& msg);
    static Status Internal(const std::string& msg1, size_t num);
    static Status Internal(const std::string& msg1, size_t num1, const std::string& msg2, size_t num2);
};

namespace port {
    bool Snappy_GetUncompressedLength(const char* input, size_t length, size_t* result);
    bool Snappy_UncompressToIOVec(const char* compressed, size_t compressed_length, const struct iovec* iov, size_t num_iov);
}

namespace errors {
    Status Internal(const std::string& msg);
    Status Internal(const std::string& msg1, size_t num);
    Status Internal(const std::string& msg1, size_t num1, const std::string& msg2, size_t num2);
}

bool DataTypeCanUseMemcpy(DataType dtype);