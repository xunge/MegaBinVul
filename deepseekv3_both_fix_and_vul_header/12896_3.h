#include <cstddef>
#include <type_traits>

namespace Eigen {
    typedef ptrdiff_t DenseIndex;
    
    template<int N>
    struct type2index {
        static const int value = N;
        operator int() const { return value; }
    };
    
    template<typename... Indices>
    struct IndexList {
        void set(size_t index, int value) {}
    };
    
    template<>
    struct IndexList<Eigen::DenseIndex, Eigen::type2index<1>> {
        void set(size_t index, Eigen::DenseIndex value) {}
    };
    
    template<>
    struct IndexList<int, Eigen::type2index<1>> {
        void set(size_t index, int value) {}
    };
}