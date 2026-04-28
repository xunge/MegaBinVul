#include <cstdint>

struct TensorShapeProto {};

struct TensorProto {
    const TensorShapeProto& tensor_shape() const;
    int dtype() const;
};

class PartialTensorShape {
public:
    PartialTensorShape(const TensorShapeProto&);
    int64_t num_elements() const;
};

class TensorShape {
public:
    TensorShape(const TensorShapeProto&);
    int64_t num_elements() const;
};

int DataTypeSize(int dtype);