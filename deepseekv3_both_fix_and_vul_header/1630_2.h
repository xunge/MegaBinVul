#include <algorithm>
#include <vector>
#include <cstdint>

template<typename T>
class ArrayRef {
public:
    ArrayRef(const std::vector<T>& vec) {}
    const T* begin() const { return nullptr; }
    const T* end() const { return nullptr; }
    size_t size() const { return 0; }
    T front() const { return T(); }
    T back() const { return T(); }
};

template<typename T, unsigned N>
class SmallVector {
public:
    SmallVector(const T* begin, const T* end) {}
    T* begin() { return nullptr; }
    T* end() { return nullptr; }
};

class Type {
public:
    template<typename T>
    T dyn_cast() const { return T(); }
    operator bool() const { return false; }
};

class RankedTensorType : public Type {
public:
    ArrayRef<int64_t> getShape() const { return ArrayRef<int64_t>({}); }
    int64_t getDimSize(int dim) const { return 0; }
};

namespace quant {
class UniformQuantizedPerAxisType {
public:
    ArrayRef<double> getScales() const { return ArrayRef<double>({}); }
    ArrayRef<int64_t> getZeroPoints() const { return ArrayRef<int64_t>({}); }
    int32_t getFlags() const { return 0; }
    Type getStorageType() const { return Type(); }
    Type getExpressedType() const { return Type(); }
    int64_t getStorageTypeMin() const { return 0; }
    int64_t getStorageTypeMax() const { return 0; }
    static UniformQuantizedPerAxisType get(
        int32_t flags, Type storageType, Type expressedType,
        const SmallVector<double, 4>& scales, 
        const SmallVector<int64_t, 4>& zeroPoints,
        int quant_dim, int64_t storageTypeMin, 
        int64_t storageTypeMax) { return UniformQuantizedPerAxisType(); }
};
}

template<typename T>
bool BroadcastVector(int64_t dim_size, SmallVector<T, 4>& vec) { return false; }