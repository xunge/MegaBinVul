#include <memory>
#include <string>
#include <cstdint>

using std::string;

class tstring : public std::string {
public:
    bool empty() const { return std::string::empty(); }
    const char* c_str() const { return std::string::c_str(); }
};

namespace checkpoint {
class TensorSliceReader {
public:
    using OpenTableFunction = void*;
    TensorSliceReader(const string& file_pattern, OpenTableFunction open_func, int preferred_shard);
    bool HasTensor(const string& name, class TensorShape* shape, class DataType* type) const;
    bool CopySliceData(const string& name, class TensorSlice const& slice, void* data) const;
    class Status status() const;
};
}  // namespace checkpoint

class TensorShape {
public:
    TensorShape();
    explicit TensorShape(int dims);
    bool IsSameSize(const TensorShape& other) const;
    int dims() const;
    int64_t num_elements() const;
    string DebugString() const;
};

class TensorSlice {
public:
    explicit TensorSlice(int dims);
};

class DataType {
public:
    enum Value {
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
    Value value;
    bool operator==(DataType other) const { return value == other.value; }
    operator int() const { return static_cast<int>(value); }
};

class Status {
public:
    bool ok() const;
};

template<typename T>
class TensorTypes {
public:
    class Flat {
    public:
        T* data();
        const T& operator()(int index) const;
        bool empty() const;
    };
};

class Tensor {
public:
    int64_t NumElements() const;
    template<typename T>
    typename TensorTypes<T>::Flat flat() const { return typename TensorTypes<T>::Flat(); }
};

class OpKernelContext {
public:
    const Tensor& input(int index) const;
    Status allocate_output(int index, const TensorShape& shape, Tensor** tensor);
    DataType expected_output_dtype(int index) const;
    void SetStatus(const Status& status);
    class SliceReaderCache {
    public:
        const checkpoint::TensorSliceReader* GetReader(
            const string& file_pattern,
            checkpoint::TensorSliceReader::OpenTableFunction open_func,
            int preferred_shard);
    };
    SliceReaderCache* slice_reader_cache() const;
};

#define OP_REQUIRES(context, expr, ...)
#define OP_REQUIRES_OK(context, expr)
#define CHECK_NOTNULL(ptr) (ptr)
#define TF_CALL_SAVE_RESTORE_TYPES(m) \
    m(float) m(double) m(int32_t) m(uint8_t) m(int16_t) m(int8_t) m(int64_t) m(bool) m(string)

template<typename T> struct DataTypeToEnum;
template<> struct DataTypeToEnum<float> { static const DataType::Value value = DataType::DT_FLOAT; };
template<> struct DataTypeToEnum<double> { static const DataType::Value value = DataType::DT_DOUBLE; };
template<> struct DataTypeToEnum<int32_t> { static const DataType::Value value = DataType::DT_INT32; };
template<> struct DataTypeToEnum<uint8_t> { static const DataType::Value value = DataType::DT_UINT8; };
template<> struct DataTypeToEnum<int16_t> { static const DataType::Value value = DataType::DT_INT16; };
template<> struct DataTypeToEnum<int8_t> { static const DataType::Value value = DataType::DT_INT8; };
template<> struct DataTypeToEnum<int64_t> { static const DataType::Value value = DataType::DT_INT64; };
template<> struct DataTypeToEnum<bool> { static const DataType::Value value = DataType::DT_BOOL; };
template<> struct DataTypeToEnum<string> { static const DataType::Value value = DataType::DT_STRING; };

#define DataTypeString(type) ""

namespace errors {
Status InvalidArgument(const char* message, ...);
Status NotFound(const char* message, ...);
Status Unimplemented(const char* message, ...);
}  // namespace errors

namespace checkpoint {
Status ParseShapeAndSlice(const string& shape_spec, TensorShape* shape,
                         TensorSlice* slice, TensorShape* output_shape);
}  // namespace checkpoint