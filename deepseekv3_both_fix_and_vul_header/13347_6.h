#include <vector>
#include <functional>
#include <algorithm>

using Type = void*;
template<typename T> using SmallVector = std::vector<T>;

namespace spirv {
    struct StructType {
        void* getContext();
        std::vector<Type> getElementTypes();
    };
}

class LLVMTypeConverter {
public:
    bool convertTypes(const std::vector<Type>&, std::vector<Type>&);
    Type convertType(Type);
};

namespace LLVM {
    struct LLVMStructType {
        static Type getLiteral(void* context, const std::vector<Type>& elements, bool isPacked);
    };
}

namespace llvm {
    template <unsigned N, typename T>
    std::vector<T> to_vector(const std::vector<T>& vec) {
        return vec;
    }
    
    template <typename T, typename F>
    std::vector<T> map_range(const std::vector<T>& vec, F func) {
        std::vector<T> result;
        std::transform(vec.begin(), vec.end(), std::back_inserter(result), func);
        return result;
    }
}

static inline bool failed(bool condition) {
    return !condition;
}