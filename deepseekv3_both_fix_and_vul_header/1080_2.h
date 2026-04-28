#include <cstdint>
#include <algorithm>
#include <vector>
#include <iostream>

enum DataType {
    DT_FLOAT = 0,
    DT_DOUBLE,
    DT_INT32,
    DT_INT64
};

struct Dim {
    int64_t size() const { return 0; }
};

struct TensorShapeProto {
    int dim_size() const { return 0; }
    const Dim& dim(int index) const { static Dim d; return d; }
    const std::vector<Dim>& dim() const { static std::vector<Dim> v; return v; }
};

struct TensorProperties {
    DataType dtype() const { return DT_FLOAT; }
    const TensorShapeProto& shape() const { static TensorShapeProto t; return t; }
};

struct OpInfo {
    const std::vector<TensorProperties>& outputs() const { static std::vector<TensorProperties> v; return v; }
};

struct OpLevelCostEstimator {
    int64_t CalculateOutputSize(const OpInfo& op_info, bool* found_unknown_shapes);
};

int64_t DataTypeSize(DataType dt) { return 0; }
DataType BaseType(DataType dt) { return dt; }
TensorShapeProto MaybeGetMinimumShape(const TensorShapeProto& shape, int num_dims, bool* found_unknown_shapes) { return shape; }
int64_t MultiplyWithoutOverflow(int64_t a, int64_t b) { return a * b; }

#define VLOG(x) std::cout