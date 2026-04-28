#include <cstddef>

namespace Eigen {
    typedef ptrdiff_t Index;
    typedef Index DenseIndex;

    template<int N> struct type2index {
        static const int value = N;
    };

    template<typename... Indices> class IndexList {
    public:
        void set(std::size_t, DenseIndex) {}
        void set(std::size_t, int) {}
    };
}