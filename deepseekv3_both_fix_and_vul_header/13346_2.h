#include <optional>
#include <vector>

namespace spirv {
struct StructType {
    struct MemberDecorationInfo {};
    void getMemberDecorations(std::vector<MemberDecorationInfo>&) const {}
    bool hasOffset() const { return false; }
};
}  // namespace spirv

class LLVMTypeConverter {};
class Type {
public:
    Type() = default;
    Type(std::nullptr_t) {}
};
Type convertStructTypeWithOffset(spirv::StructType, LLVMTypeConverter&);
Type convertStructTypePacked(spirv::StructType, LLVMTypeConverter&);

template<typename T, unsigned N>
using SmallVector = std::vector<T>;