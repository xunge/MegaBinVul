#include <optional>
#include <vector>
#include <algorithm>

class Type {
public:
    Type(std::nullptr_t) {}
    Type() = default;
};

class MLIRContext {};

template <typename T>
class SmallVector : public std::vector<T> {
public:
    using std::vector<T>::vector;
    bool failed() const { return false; }
};

namespace llvm {
template <unsigned N, typename T>
std::vector<typename T::value_type> to_vector(const T& range) {
    return std::vector<typename T::value_type>(range.begin(), range.end());
}

template <typename T, typename F>
auto map_range(const T& range, F&& func) {
    using ResultType = decltype(func(*range.begin()));
    std::vector<ResultType> result;
    std::transform(range.begin(), range.end(), std::back_inserter(result), std::forward<F>(func));
    return result;
}
} // namespace llvm

namespace spirv {
class StructType {
public:
    using Type = ::Type;
    std::vector<Type> getElementTypes() const;
    MLIRContext* getContext() const;
    bool operator!=(const Type& other) const;
};
} // namespace spirv

class LLVMTypeConverter {
public:
    Type convertType(Type type);
    bool convertTypes(const std::vector<Type>& types, std::vector<Type>& result);
    bool convertTypes(const std::vector<Type>& types, SmallVector<Type>& result);
};

namespace LLVM {
class LLVMStructType {
public:
    static Type getLiteral(MLIRContext* context,
                         const std::vector<Type>& elements,
                         bool isPacked);
    static Type getLiteral(MLIRContext* context,
                         const SmallVector<Type>& elements,
                         bool isPacked);
};
} // namespace LLVM

class VulkanLayoutUtils {
public:
    static Type decorateType(spirv::StructType type);
};

template <typename T>
bool failed(const T&) { return false; }